/*
 * fileName:          PerpetualAmericanOption.cpp
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-10
 * @lastModifiedDate: 2020-06-10
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Implementations of the PerpetualAmericanOption derived class */

#include "PerpetualAmericanOption.hpp"
#include <iostream>
#include "boost/math/distributions/normal.hpp"
#include <string>
#include <sstream>
#include <math.h>
using namespace std;

// default constructor
PerpetualAmericanOption::PerpetualAmericanOption() : Option(), type(Call) {}
													// use base class default constructor, then set option type to Call by default

// constructor that takes full parameters
PerpetualAmericanOption::PerpetualAmericanOption(double K, double sig, double r, double b, double U) : Option(NULL, K, sig, r, b, U), type(Call) {}
																										// use base class constructor that takes full parameters
																										// set T to NULL
																										// set option type to Call by default

// constructor that takes a struct of parameters
PerpetualAmericanOption::PerpetualAmericanOption(const struct OptionData& sourceData) : Option(sourceData), type(Call) {}
																						// use base class constructor that takes a struct
																						// set type to Call by default

// constructor that takes an option type and a struct of parameters
PerpetualAmericanOption::PerpetualAmericanOption(const enum OptionType& type, const struct OptionData& sourceData) : Option(sourceData), type(type) {}
																													// use base class constructor that takes a struct
																													// set type to input option type

// constructor that takes an option type only
PerpetualAmericanOption::PerpetualAmericanOption(const enum OptionType& inputType) : Option(), type(inputType) {}
																					// use base class default constructor
																					// set type to input option type

// cconstructor that takes an option type and full parameters
PerpetualAmericanOption::PerpetualAmericanOption(const enum OptionType& inputType, double K, double sig, double r, double b, double U)
	: Option(NULL, K, sig, r, b, U), type(inputType) {}
	// use base class constructor that takes full parameters
	// set T to NULL
	// set type to input option type

// copy constructor
PerpetualAmericanOption::PerpetualAmericanOption(const PerpetualAmericanOption& source) : Option(source), type(source.type) {}
																						// copy the base portion and then set option type

// assignment operator
PerpetualAmericanOption& PerpetualAmericanOption::operator = (const PerpetualAmericanOption& rhs)
{
	// if self assignment
	if (this == &rhs)
	{
		// return this object
		return *this;
	}
	// copy the base portion
	Option::operator=(rhs);
	// copy the option type
	type = rhs.type;
	// return this object
	return *this;
}

// destructor
PerpetualAmericanOption::~PerpetualAmericanOption() {}

// calculate call option value function that takes full parameters
double PerpetualAmericanOption::CallPrice(double inputK, double inputSig, double inputR, double inputB, double inputU) const
{
	// use the global Price function to calculate
	return ::Price(Call, inputK, inputSig, inputR, inputB, inputU);
}

// calculate put option value function that takes full parameters
double PerpetualAmericanOption::PutPrice(double inputK, double inputSig, double inputR, double inputB, double inputU) const
{
	// use the global Price function to calculate
	return ::Price(Put, inputK, inputSig, inputR, inputB, inputU);
}

// calculate Price for Call or Put option
// this function assume the Option object already has desired parameters
double PerpetualAmericanOption::Price() const
{
	// if type is Call, use CallPrice
	if (type == Call) { return CallPrice(K, sig, r, b, U); }
	// if type is Put, use PutPrice
	return PutPrice(K, sig, r, b, U);
}

// calculate Price for Call or Put Option
// this function takes full parameters
double PerpetualAmericanOption::Price(double inputK, double inputSig, double inputR, double inputB, double inputU) const
{
	// if type is Call, use CallPrice
	if (type == Call) { return CallPrice(inputK, inputSig, inputR, inputB, inputU); }
	// if type is Put, use PutPrice
	return PutPrice(inputK, inputSig, inputR, inputB, inputU);
}

// calculate the price by taking only the parameter of Stock Price
double PerpetualAmericanOption::PriceWithStock(double newU)
{
	// set stock price to the new input stock price
	U = newU;
	// use the member Price function
	return Price();
}

// calculate the price by taking only the parameter of Strike Price
double PerpetualAmericanOption::PriceWithStrike(double newK)
{
	// set the strike price to the new strike price
	K = newK;
	// use the member Price function
	return Price();
}

// calculate the price by taking only the parameter of vol 
double PerpetualAmericanOption::PriceWithVol(double newSig)
{
	// set the vol to the new vol price
	sig = newSig;
	// use the member Price function
	return Price();
}

// calculate the price by taking only the parameter of rate
double PerpetualAmericanOption::PriceWithRate(double newR)
{
	// set rate to the new rate
	r = newR;
	// use the member Price function
	return Price();
}

// calculate the price by taking only the parameter of cost of carry
double PerpetualAmericanOption::PriceWithDiv(double newB)
{
	// set b to new b
	b = newB;
	// use the member Price function
	return Price();
}


// helper function to calculate current row of matrix pricer
vector<double> PerpetualAmericanOption::matrixPricerHelper(double (PerpetualAmericanOption::* PriceFun)(double), PerpetualAmericanOption* currOption, const vector<double>& params) const
{
	vector<double> res;
	for (int i = 0; i != params.size(); ++i)
	{
		double currParam = params[i];
		double currVal = (currOption->*PriceFun)(currParam);
		res.push_back(currVal);
	}
	return res;
}

// Matrix Pricer Version 1
// function to Calculate the price of Option of a matrix of parameters
// takes the argument of a matrix of parameters and a vector of parameter types
matrix PerpetualAmericanOption::matrixPricer(const matrix& paramMat, const vector<enum ParamType>& paramTypes) const
{
	// initialize the result matrix
	matrix resMat;
	// initialize the current row vector 
	vector<double> currRes;

	for (int i = 0; i != paramMat.size(); ++i)
	{
		// since after finishing each row, we want to refresh the parameters to the original passed in parameters
		// here we store a copy of the original Option by using its copy constructor
		PerpetualAmericanOption originalOption(*this);

		// a switch to determine the type of the parameter 
		// then pass the corresponding pricing function to the matrix pricer helper function and calculate the current row
		switch (paramTypes[i])
		{
		case Stock:
			currRes = matrixPricerHelper(&PerpetualAmericanOption::PriceWithStock, &originalOption, paramMat[i]);
			break;

		case Strike:
			currRes = matrixPricerHelper(&PerpetualAmericanOption::PriceWithStrike, &originalOption, paramMat[i]);
			break;

		case IntRate:
			currRes = matrixPricerHelper(&PerpetualAmericanOption::PriceWithRate, &originalOption, paramMat[i]);
			break;

		case Vol:
			currRes = matrixPricerHelper(&PerpetualAmericanOption::PriceWithVol, &originalOption, paramMat[i]);
			break;

		case COC:
			currRes = matrixPricerHelper(&PerpetualAmericanOption::PriceWithDiv, &originalOption, paramMat[i]);
			break;
		}
		// store the result of this row of option value
		resMat.push_back(currRes);
	}
	// return the final result matrix
	return resMat;
}

// Matrix Pricer Version 2
// it specifically calculate a matrix of option prices between 2 variables
// takes the argument of 2 vectors of parameters and 2 parameter types
matrix PerpetualAmericanOption::matrixPricer(const vector<double> param1, const vector<double> param2, const enum ParamType& paramType1, const enum ParamType& paramType2) const
{
	// initialize the result matrix
	matrix resMat;
	// initialize the current row vector 
	vector<double> currRes;
	// for each value in parameter vector 1
	for (int i = 0; i != param1.size(); ++i)
	{
		// since after finishing each row, we want to refresh the parameters to the original passed in parameters
		// here we store a copy of the original Option by using its copy constructor
		PerpetualAmericanOption originalOption(*this);

		// extract the current element from parameter vector 1
		double currParam1 = param1[i];

		// determine which parameter type is parameter1
		// then set the corresponding value to the value of first element in parameter 1
		switch (paramType1)
		{
		case Stock:
			originalOption.U = currParam1;
			break;

		case Strike:
			originalOption.K = currParam1;
			break;

		case IntRate:
			originalOption.r = currParam1;
			break;

		case Vol:
			originalOption.sig = currParam1;
			break;

		case COC:
			originalOption.b = currParam1;
			break;
		}

		// we also need to determine which type is parameter 2
		// then pass in the corresponding pricing function to the matrix pricer helper function
		switch (paramType2)
		{
		case Stock:
			currRes = matrixPricerHelper(&PerpetualAmericanOption::PriceWithStock, &originalOption, param2);
			break;

		case Strike:
			currRes = matrixPricerHelper(&PerpetualAmericanOption::PriceWithStrike, &originalOption, param2);
			break;

		case IntRate:
			currRes = matrixPricerHelper(&PerpetualAmericanOption::PriceWithRate, &originalOption, param2);
			break;

		case Vol:
			currRes = matrixPricerHelper(&PerpetualAmericanOption::PriceWithVol, &originalOption, param2);
			break;

		case COC:
			currRes = matrixPricerHelper(&PerpetualAmericanOption::PriceWithDiv, &originalOption, param2);
			break;
		}
		// store the current row into the result matrix
		resMat.push_back(currRes);
	}
	// return the result matrix
	return resMat;

}

// helper function to display the option parameters
string PerpetualAmericanOption::DisplayParams() const
{
	stringstream ss;

	// if type is Call
	if (type == Call) {
		// return Call string
		ss << "American Call Option's parameters: " << "K: " << K << ", Vol: " << sig << ", r: " << r << ", S: " << U << ", b: " << b;
	}
	// if type is put
	if (type == Put) {
		// return Put string
		ss << "American Put Option's parameters: " << "K: " << K << ", Vol: " << sig << ", r: " << r << ", S: " << U << ", b: " << b;
	}

	// retrieve the string and return
	return ss.str();
}

// function to change option type
void PerpetualAmericanOption::toggle()
{
	// if current type is Call
	if (type == Call) {
		// set type to Put
		type = Put;
		// return
		return;
	}
	// if current type is Put
	// set type to Call
	type = Call;
}

// Global Function:
// This function contains actual implementations of the formulas
// member functions will eventually use this function to calculate their values
// In addition, the benefit of having this global function is that it allows users to calculate values directly, 
// without initializing an Option object first
double Price(const enum OptionType& inputType, double K, double sig, double r, double b, double U)
{
	// initialize val as our result
	double val;
	// calculate y1
	double y1 = 0.5 - b / pow(sig, 2) + sqrt( pow((b / pow(sig, 2) - 0.5), 2) + (2 * r / pow(sig, 2)) );
	// calculate y2
	double y2 = 0.5 - b / pow(sig, 2) - sqrt( pow((b / pow(sig, 2) - 0.5), 2) + (2 * r / pow(sig, 2)) );

	// if input option type is Call
	if (inputType == Call)
	{
		// handle special case
		if (y1 == 1)
		{
			// return special value
			return U;
		}
		// if not special case, use the formula for Call as regular
		val = (K / (y1 - 1.0)) * pow((((y1 - 1.0) / y1) * (U / K)), y1);
	}

	// if input option type is Put
	if (inputType == Put)
	{
		// handle special case
		if (y2 == 0)
		{
			// return special value
			return U;
		}
		// if not special case, use the formula for Put as regular
		val = (K / (1.0 - y2)) * pow((((y2 - 1.0) / y2) * (U / K)), y2);
	}

	// return the result
	return val;
}




