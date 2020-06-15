/*
 * fileName:          PerpetualAmericanOption.hpp
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-10
 * @lastModifiedDate: 2020-06-10
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Header file of the PerpetualAmericanOption derived class */

#ifndef PERPETUAL_AMERICAN_HPP
#define PERPETUAL_AMERICAN_HPP
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Option.hpp"
using namespace std;

// define vector of a vector to type matrix
typedef vector< vector<double> > matrix;


// Perpetual American Option class that is derived from Option class
class PerpetualAmericanOption : public Option
{
// some private functions to calculate Option Price
private:
	double CallPrice(double K, double sig, double r, double b, double U) const;
	double PutPrice(double K, double sig, double r, double b, double U) const;

// public functions that can be accessed by users to calculate price 
public:
	// change the Option type
	void toggle();

	// function to calculate Option Price
	// this function assumes the option object has the desired parameters
	double Price() const;

	// function to that takes full parameters to calculate function price
	double Price(double K, double sig, double r, double b, double U) const;

	// calculate the price by taking only the parameter of Stock Price
	double PriceWithStock(double newU);

	// calculate the price by taking only the parameter of Strike Price
	double PriceWithStrike(double newK);

	// calculate the price by taking only the parameter of vol
	double PriceWithVol(double newSig);

	// calculate the price by taking only the parameter of interest rate
	double PriceWithRate(double newR);

	// calculate the price by taking only the parameter of cost of carry
	double PriceWithDiv(double newB);

	// Matrix Pricer Version 1
	// function to Calculate the price of Option of a matrix of parameters
	// takes the argument of a matrix of parameters and a vector of parameter types
	matrix matrixPricer(const matrix& paramMat, const vector<enum ParamType>& paramTypes) const;

	// Matrix Pricer Version 2
	// it specifically calculate a matrix of option prices between 2 variables
	// takes the argument of 2 vectors of parameters and 2 parameter types
	matrix matrixPricer(const vector<double> param1, const vector<double> param2, const enum ParamType& paramType1, const enum ParamType& paramType2) const;

	// helper function to calculate current row of matrix pricer
	vector<double> matrixPricerHelper(double (PerpetualAmericanOption::*PriceFun)(double), PerpetualAmericanOption* currOption, const vector<double>& params) const;
	

public:
	// default constructor
	PerpetualAmericanOption();

	// constructor that takes full parameters
	PerpetualAmericanOption(double K, double sig, double r, double b, double U);

	// constructor that takes a struct of parameters
	PerpetualAmericanOption(const struct OptionData& sourceData);

	// constructor that takes option type and a struct of parameters
	PerpetualAmericanOption(const enum OptionType& type, const struct OptionData& sourceData);

	// constructor takes only an option type
	PerpetualAmericanOption(const enum OptionType& type);

	//constructor that takes option type and full parameters
	PerpetualAmericanOption(const enum OptionType& type, double K, double sig, double r, double b, double U);

	// copy constructor
	PerpetualAmericanOption(const PerpetualAmericanOption& source);

	// assignment operator
	PerpetualAmericanOption& operator = (const PerpetualAmericanOption& rhs);

	// destructor
	virtual ~PerpetualAmericanOption();

	// type of option
	enum OptionType type;

	// helper function to display the parameters in the option
	string DisplayParams() const;
};

// global function to calculate the Option Price
double Price(const enum OptionType& type, double K, double sig, double r, double b, double U);



#endif