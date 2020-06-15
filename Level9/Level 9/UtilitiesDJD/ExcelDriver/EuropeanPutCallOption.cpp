/*
 * fileName:          EuropeanPutCallOption.hpp
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-10
 * @lastModifiedDate: 2020-06-10
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Implementations of the EuropeanPutCallOption derived class */


#include "EuropeanPutCallOption.hpp"
#include "boost/math/distributions/normal.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;
using namespace boost::math;


// default constructor
EuropeanPutCallOption::EuropeanPutCallOption() : Option(), type(Call) {} // call base class's default constructor, 
																		 // then assign the Option type to Call by default

// constructor that takes full parameters
EuropeanPutCallOption::EuropeanPutCallOption(double T, double K, double sig, double r, double b, double U) : Option(T, K, sig, r, b, U), type(Call) {}
																											// call base class's constructor that takes full parameters
																											// then assign the Option type to Call by default

// constructor that takes a struct of parameters
EuropeanPutCallOption::EuropeanPutCallOption(const struct OptionData& sourceData) : Option(sourceData), type(Call) {}
																					// call base class's constructor that takes a struct
																					// then assign the Option type to Call by default


// constructor that takes an Option type and a struct of parameters
EuropeanPutCallOption::EuropeanPutCallOption(const enum OptionType& type, struct OptionData& sourceData) : Option(sourceData), type(type) {}
																											// call base class's constructor that takes a struct
																											// then assign Option type to input Option type

// constructor that takes an Option type only
EuropeanPutCallOption::EuropeanPutCallOption(const enum OptionType& inputType) : Option(), type(inputType) {}
																				// call base class default constructor
																				// then assign Option type to input Option type

// constructor that takes an Optino type and full parameters explicitly
EuropeanPutCallOption::EuropeanPutCallOption(const enum OptionType& inputType, double T, double K, double sig, double r, double b, double U)
											: Option(T, K, sig, r, b, U), type(inputType) {}
											// call base class constructor that takes full parameters
											// then assign Option type to input Option type

// copy constructor	
EuropeanPutCallOption::EuropeanPutCallOption(const EuropeanPutCallOption& source) : Option(source), type(source.type) {}
																					// call base class copy constructor
																					// then assign derived class's own member, which is option type

// assignment operator
EuropeanPutCallOption& EuropeanPutCallOption::operator = (const EuropeanPutCallOption& rhs)
{
	// check if self assignment
	if (this == &rhs)
	{
		// return this object
		return *this;
	}
	// if not 
	// assignment the base portion
	Option::operator=(rhs);
	// copy over the option type
	type = rhs.type;
	// return this object
	return *this;
}

// destructor
EuropeanPutCallOption::~EuropeanPutCallOption() {}

// calculate call option value function that takes full parameters
double EuropeanPutCallOption::CallPrice(double inputT, double inputK, double inputSig, double inputR, double inputB, double inputU) const
{
	// use the global Price function to calculate
	return	::Price(Call, inputT, inputK, inputSig, inputR, inputB, inputU);
}


// calculate put option value function that takes full parameters
double EuropeanPutCallOption::PutPrice(double inputT, double inputK, double inputSig, double inputR, double inputB, double inputU) const
{
	// use the global Price function to calculate
	return ::Price(Put, inputT, inputK, inputSig, inputR, inputB, inputU);
}

// function to calculate Option price using Put-Call Parity
double EuropeanPutCallOption::PutCallParity(double optionPrice) const
{
	// if current type is Call
	if (this->type == Call)
	{
		// Put = ...
		return optionPrice + K * exp(-r * T) - U;
	}

	// if current type is Put
	// Call = ...
	return optionPrice - K * exp(-r * T) + U;
}

// calculate Price for Call or Put option
// this function assume the Option object already has desired parameters
double EuropeanPutCallOption::Price() const
{
	// if type is Call, use the CallPrice function
	if (type == Call) { return CallPrice(T, K, sig, r, b, U); }
	// if type is Put, use the PutPrice function
	return PutPrice(T, K, sig, r, b, U);
}

// calculate Price for Call or Put Option
// this function takes full parameters
double EuropeanPutCallOption::Price(double T, double K, double sig, double r, double b, double U) const
{
	// if type is Call, use the CallPrice function
	if (type == Call) { return CallPrice(T, K, sig, r, b, U); }
	// if type is Put, use the PutPrice function
	return PutPrice(T, K, sig, r, b, U);
}

// calculate the price by taking only the parameter of Stock Price
double EuropeanPutCallOption::PriceWithStock(double newU)
{
	// set stock price to the new input stock price
	U = newU;
	// use the member Price function
	return Price();

}

// calculate the price by taking only the parameter of Strike Price
double EuropeanPutCallOption::PriceWithStrike(double newK)
{
	// set strike price to the new input strike price
	K = newK;
	// use the member Price function
	return Price();

}

// calculate the price by taking only the parameter of Vol
double EuropeanPutCallOption::PriceWithVol(double newSig)
{
	// set vol to the new input vol
	sig = newSig;
	// use the member Price function
	return Price();

}

// calculate the price by taking only the parameter of Rate
double EuropeanPutCallOption::PriceWithRate(double newR)
{
	// set r to the new input r
	r = newR;
	// use the member Price function
	return Price();

}

// calculate the price by taking only the parameter of Cost of Carry
double EuropeanPutCallOption::PriceWithDiv(double newB)
{
	// set b to the new input b
	b = newB;
	// use the member Price function
	return Price();

}

// calculate the price by taking only the parameter of Time
double EuropeanPutCallOption::PriceWithTime(double newT)
{
	// set T to the new input T
	T = newT;
	// use the member Price function
	return Price();

}

// helper function to calculate current row of option price matrix pricer
vector<double> EuropeanPutCallOption::matrixPricerHelper(double (EuropeanPutCallOption::*PriceFun)(double), EuropeanPutCallOption* currOption, const vector<double>& params) const
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
matrix EuropeanPutCallOption::matrixPricer(const matrix& paramMat, const vector<enum ParamType>& paramTypes) const
{
	// initialize the result matrix
	matrix resMat;
	// initialize the current row vector 
	vector<double> currRes;

	for (int i = 0; i != paramMat.size(); ++i)
	{
		// since after finishing each row, we want to refresh the parameters to the original passed in parameters
		// here we store a copy of the original Option by using its copy constructor
		EuropeanPutCallOption originalOption(*this);

		// a switch to determine the type of the parameter 
		// then pass the corresponding pricing function to the matrix pricer helper function and calculate the current row
		switch (paramTypes[i])
		{
		case Stock:
			currRes = matrixPricerHelper(&EuropeanPutCallOption::PriceWithStock, &originalOption, paramMat[i]);
			break;

		case Strike:
			currRes = matrixPricerHelper(&EuropeanPutCallOption::PriceWithStrike, &originalOption, paramMat[i]);
			break;

		case IntRate:
			currRes = matrixPricerHelper(&EuropeanPutCallOption::PriceWithRate, &originalOption, paramMat[i]);
			break;

		case Time:
			currRes = matrixPricerHelper(&EuropeanPutCallOption::PriceWithTime, &originalOption, paramMat[i]);
			break;

		case Vol:
			currRes = matrixPricerHelper(&EuropeanPutCallOption::PriceWithVol, &originalOption, paramMat[i]);
			break;

		case COC:
			currRes = matrixPricerHelper(&EuropeanPutCallOption::PriceWithDiv, &originalOption, paramMat[i]);
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
matrix EuropeanPutCallOption::matrixPricer(const vector<double> param1, const vector<double> param2, const enum ParamType& paramType1, const enum ParamType& paramType2) const
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
		EuropeanPutCallOption originalOption(*this);
		
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
			originalOption.K= currParam1;
			break;

		case IntRate:
			originalOption.r = currParam1;
			break;

		case Time:
			originalOption.T = currParam1;
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
			currRes = matrixPricerHelper(&EuropeanPutCallOption::PriceWithStock, &originalOption, param2);
			break;

		case Strike:
			currRes = matrixPricerHelper(&EuropeanPutCallOption::PriceWithStrike, &originalOption, param2);
			break;

		case IntRate:
			currRes = matrixPricerHelper(&EuropeanPutCallOption::PriceWithRate, &originalOption, param2);
			break;

		case Time:
			currRes = matrixPricerHelper(&EuropeanPutCallOption::PriceWithTime, &originalOption, param2);
			break;

		case Vol:
			currRes = matrixPricerHelper(&EuropeanPutCallOption::PriceWithVol, &originalOption, param2);
			break;

		case COC:
			currRes = matrixPricerHelper(&EuropeanPutCallOption::PriceWithDiv, &originalOption, param2);
			break;
		}
		// store the current row into the result matrix
		resMat.push_back(currRes);
	}
	// return the result matrix
	return resMat;

}


// Greek Matrix Pricer Version 1
// Calculate the price of specified Greek for a matrix of parameters
// takes the argument of a matrix of parameters, a vector of parameter types, and a pointer to the Greek function
matrix EuropeanPutCallOption::matrixGreek(const matrix& paramMat, const vector<enum ParamType>& paramTypes, double (EuropeanPutCallOption::*GreekFun)(void) const) const
{
	// initialize the result matrix
	matrix resMat;
	
	for (int i = 0; i != paramMat.size(); ++i)
	{
		// since after finishing each row, we want to refresh the parameters to the original passed in parameters
		// here we store a copy of the original Option by using its copy constructor
		EuropeanPutCallOption originalOption(*this);

		// initialize a pointer to the option object, so that we can activate the function pointer
		EuropeanPutCallOption* optionPtr = &originalOption;

		// initialize the current row vector 
		vector<double> currRes;

		// a switch to determine the type of the parameter 
		// then pass the corresponding pricing function to the matrix pricer helper function and calculate and store into the current row
		switch (paramTypes[i])
		{
		case Stock:
			for (int j = 0; j != paramMat[i].size(); ++j)
			{
				originalOption.U = paramMat[i][j];
				currRes.push_back((optionPtr->*GreekFun)());
			}
			break;

		case Strike:
			for (int j = 0; j != paramMat[i].size(); ++j)
			{
				originalOption.K = paramMat[i][j];
				currRes.push_back((optionPtr->*GreekFun)());
			}
			break;

		case IntRate:
			for (int j = 0; j != paramMat[i].size(); ++j)
			{
				originalOption.r = paramMat[i][j];
				currRes.push_back((optionPtr->*GreekFun)());
			}
			break;

		case Time:
			for (int j = 0; j != paramMat[i].size(); ++j)
			{
				originalOption.T = paramMat[i][j];
				currRes.push_back((optionPtr->*GreekFun)());
			}
			break;

		case Vol:
			for (int j = 0; j != paramMat[i].size(); ++j)
			{
				originalOption.sig = paramMat[i][j];
				currRes.push_back((optionPtr->*GreekFun)());
			}
			break;

		case COC:
			for (int j = 0; j != paramMat[i].size(); ++j)
			{
				originalOption.b = paramMat[i][j];
				currRes.push_back((optionPtr->*GreekFun)());
			}
			break;
		}
		// store the result of this row of option value
		resMat.push_back(currRes);
	}
	// return the final result matrix
	return resMat;
}

// Greek Matrix Pricer Version 2
// Specifically focus on the relationship between 2 types of parameters
// takes the argument of a 2 vector of parameters, 2 parameter types, and a pointer to the Greek function
matrix EuropeanPutCallOption::matrixGreek(const vector<double>& param1, const vector<double>& param2, const enum ParamType& paramType1, const enum ParamType& paramType2,
	double (EuropeanPutCallOption::* GreekFun)(void) const) const
{
	// initialize the result matrix
	matrix resMat;
	for (int i = 0; i != param1.size(); ++i)
	{
		// since after finishing each row, we want to refresh the parameters to the original passed in parameters
		// here we store a copy of the original Option by using its copy constructor
		EuropeanPutCallOption originalOption(*this);

		// initialize a pointer to the option object, so that we can activate the function pointer
		EuropeanPutCallOption* optionPtr = &originalOption;

		// initialize the current row vector 
		vector<double> currRes;

		// determine the parameter type of the Column
		// then set the parameter
		switch (paramType1)
		{
		case Stock:
			originalOption.U = param1[i];
			break;

		case Strike:
			originalOption.K = param1[i];
			break;

		case IntRate:
			originalOption.r = param1[i];
			break;

		case Time:
			originalOption.T = param1[i];
			break;

		case Vol:
			originalOption.sig = param1[i];
			break;

		case COC:
			originalOption.b = param1[i];
			break;
		}
		
		for (int j = 0; j != param2.size(); ++j)
		{
			// determine the parameter type of the row
			// then set the type
			switch (paramType2)
			{
			case Stock:
				originalOption.U = param2[j];
				break;

			case Strike:
				originalOption.K = param2[j];
				break;

			case IntRate:
				originalOption.r = param2[j];
				break;

			case Time:
				originalOption.T = param2[j];
				break;

			case Vol:
				originalOption.sig = param2[j];
				break;

			case COC:
				originalOption.b = param2[j];
				break;
			}
			// call the Greek function pointer and then store the result into the row vector
			currRes.push_back((optionPtr->*GreekFun)());
		}
		// store the row vector into the result matrix
		resMat.push_back(currRes);
	}
	// return the result matrix
	return resMat;

}

// calculate delta
double EuropeanPutCallOption::Delta() const
{
	// use global function
	return ::Delta(type, T, K, sig, r, b, U);
}

// calculate gamma
double EuropeanPutCallOption::Gamma() const
{
	// use global function
	return ::Gamma(type, T, K, sig, r, b, U);
}

// calculate theta
double EuropeanPutCallOption::Theta() const
{
	// use global function
	return ::Theta(type, T, K, sig, r, b, U);
}

// calculate vega
double EuropeanPutCallOption::Vega() const
{
	// use global funcion
	return ::Vega(type, T, K, sig, r, b, U);
}

// calculate Approximate delta
double EuropeanPutCallOption::ApproxDelta(double newU, double newH) const
{
	// use the global function
	return ::ApproxDelta(type, T, K, sig, r, b, newU, newH);
}

// calcualte Approximate gamma
double EuropeanPutCallOption::ApproxGamma(double newU, double newH) const
{
	// use the global function
	return ::ApproxGamma(type, T, K, sig, r, b, newU, newH);
}

// toggle function to switch the Option Type
void EuropeanPutCallOption::toggle()
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

// helper function to display the parameters in the Option
// return a string
string EuropeanPutCallOption::DisplayParams() const
{
	// initialize a stringstream object
	stringstream ss;
	// if type is Call
	if (type == Call) {
		// push message into ss
		ss << "European Call Option's parameters: " <<"T: " << T << ", K: " << K << ", Vol: " << sig << ", r: " << r << ", S: " << U << ", b: " << b;
	}
	// if type is Put
	if (type == Put) {
		// push different message into ss
		ss << "European Put Option's parameters: " << "T: " << T << ", K: " << K << ", Vol: " << sig << ", r: " << r << ", S: " << U << ", b: " << b;
	}
	// retrieve the string and return
	return ss.str();
}


// Global Functions:
// These functions contain actual implementations of the formulas
// member functions will eventually use these functions to calculate their values
// In addition, the benefit of having these global function is that it allows users to calculate values directly, 
// without initializing an Option object first

// Global function to calculate Price
double Price(const enum OptionType& inputType, double inputT, double inputK, double inputSig, double inputR, double inputB, double inputU)
{
	// initialize val as our result
	double val;
	// use boost normal distribution of mean 0 and std 1
	normal_distribution<> normalDist(0, 1);
	// calculate d1
	double d1 = ((log(inputU / inputK) + (inputB + pow(inputSig, 2) / 2) * inputT) / (inputSig * sqrt(inputT)));
	// calculate d2
	double d2 = d1 - inputSig * sqrt(inputT);
	// calculate N(d1)
	double Nd1 = cdf(normalDist, d1);
	// calculate N(d2)
	double Nd2 = cdf(normalDist, d2);
	// calculate -N(d1)
	double NNEGd1 = cdf(normalDist, -d1);
	// calculate -N(d2)
	double NNEGd2 = cdf(normalDist, -d2);

	// if input Option type is Call
	if (inputType == Call)
	{
		// use Call's formula
		val = inputU * exp((inputB - inputR) * inputT) * Nd1 - inputK * exp(-inputR * inputT) * Nd2;
	}
	
	// if input Option type is Put
	if (inputType == Put)
	{
		// use Put's formula
		val = inputK * exp(-inputR * inputT) * NNEGd2 - inputU * exp((inputB - inputR) * inputT) * NNEGd1;
	}

	// return the result
	return val;
}

// Global function to calculate delta
double Delta(const enum OptionType& inputType,  double T, double K, double sig, double r, double b, double U)
{
	// use boost normal distribution of mean 0 and std 1
	normal_distribution<> normalDist(0, 1);

	// calculate d1
	double d1 = ((log(U / K) + (b + pow(sig, 2) / 2) * T) / (sig * sqrt(T)));

	// if input Option type is Call
	if (inputType == Call)
	{
		// use delta formula for Call
		return exp((b - r) * T) * cdf(normalDist, d1);
	}

	// if input Option type is Put
	// use delta formula for Put
	return exp((b - r) * T) * (cdf(normalDist, d1) - 1);
}

// Global function to calculate gamma
double Gamma(const enum OptionType& inputType, double T, double K, double sig, double r, double b, double U)
{
	// use boost normal distribution of mean 0 and std 1
	normal_distribution<> normalDist(0, 1);

	// calculate d1
	double d1 = ((log(U / K) + (b + pow(sig, 2) / 2) * T) / (sig * sqrt(T)));

	// since Put and Call has the same gamma formula,
	// just use this uniform formula
	return (pdf(normalDist, d1) * exp((b - r) * T)) / (U * sig * sqrt(T));
	
}

// Global function to calculate theta
double Theta(const enum OptionType& inputType, double T, double K, double sig, double r, double b, double U)
{
	// use boost normal distribution of mean 0 and std 1
	normal_distribution<> normalDist(0, 1);

	//calculate d1
	double d1 = ((log(U / K) + (b + pow(sig, 2) / 2) * T) / (sig * sqrt(T)));

	// calculate d2
	double d2 = d1 - sig * sqrt(T);

	// if input option type is Call
	if (inputType == Call)
	{
		// use theta formula for Call
		return (-U * sig * exp((b - r) * T) * pdf(normalDist, d1)) / (2 * sqrt(T)) - (b - r) * U * exp((b - r) * T) * cdf(normalDist, d1) - r * K * exp(-r * T) * cdf(normalDist, d2);
	}

	// if input option type is Put
	// use theta formula for Put
	return (-U * sig * exp((b - r) * T) * pdf(normalDist, d1)) / (2 * sqrt(T)) + (b - r) * U * exp((b - r) * T) * cdf(normalDist, -d1) + r * K * exp(-r * T) * cdf(normalDist, -d2);
}	

// Global function to calculate theta
double Vega(const enum OptionType& inputType, double T, double K, double sig, double r, double b, double U)
{
	// use boost normal distribution of mean 0 and std 1
	normal_distribution<> normalDist(0, 1);

	// calculate d1
	double d1 = ((log(U / K) + (b + pow(sig, 2) / 2) * T) / (sig * sqrt(T)));

	// since Put and Call share the same vega formula
	// calculate the uniform formula and return
	return U * sqrt(T) * exp((b - r) * T) * pdf(normalDist, d1);
}


// global function to calculate approximate delta
double ApproxDelta(const enum OptionType& inputType, double T, double K, double sig, double r, double b, double U, double h)
{
	// utilize the global Price function that takes option type and full parameters
	return (::Price(inputType, T, K, sig, r, b, U + h) - ::Price(inputType, T, K, sig, r, b, U - h)) / (2 * h);
}

// global function to calculate approximate gamma
double ApproxGamma(const enum OptionType& inputType, double T, double K, double sig, double r, double b, double U,  double h)
{
	// utilize the global Price function that takes option type and full parameters
	return (::Price(inputType, T, K, sig, r, b, U + h) - 2 * ::Price(inputType, T, K, sig, r, b, U) + ::Price(inputType, T, K, sig, r, b, U - h)) / (pow(h, 2));
}
