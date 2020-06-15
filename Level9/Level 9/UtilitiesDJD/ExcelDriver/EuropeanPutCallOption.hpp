/*
 * fileName:          EuropeanPutCallOption.hpp
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-10
 * @lastModifiedDate: 2020-06-10
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Header file of the EuropeanPutCallOption derived class */

#ifndef EUROPEAN_PUTCALL_HPP
#define EUROPEAN_PUTCALL_HPP

#include <iostream>
#include "Option.hpp"
#include <vector>
#include <sstream>
#include <string>
using namespace std;

// define vector of a vector to type matrix
typedef vector< vector<double> > matrix;


// European Option class that is derived from the Option base class
class EuropeanPutCallOption : public Option
{

// private field to calculate of either Put or Call function
// these 2 functions cannot be accessed by the user directly
private:
	double CallPrice(double T, double K, double sig, double r, double b, double U) const;
	double PutPrice(double T, double K, double sig, double r, double b, double U) const;
	

// some public functions to calculate the values that the user want
public:
	
	// calculate the price of the option, override the pure virtual function in base class
	// to use this function, we assume the Option has the desired parameters already
	double Price() const;

	// calculate the price by taking parameters directly
	// this function can be used before assigning values to the Option
	double Price(double T, double K, double sig, double r, double b, double U) const;

	// calculate the price by taking only the parameter of Stock Price
	double PriceWithStock(double newU);

	// calculate the price by taking only the parameter of Time
	double PriceWithTime(double newT);

	// calculate the price by taking only the parameter of Strike Price
	double PriceWithStrike(double newK);

	// calculate the price by taking only the parameter of Volatility
	double PriceWithVol(double newSig);

	// calculate the price by taking only the parameter of Interest Rate
	double PriceWithRate(double newR);

	// calculate the price by taking only the parameter cost of carry
	double PriceWithDiv(double newB);
	
	// calculate Call or Put price using Put-Call Parity
	double PutCallParity(double optionPrice) const;

	// Matrix Pricer Version 1
	// function to Calculate the price of Option of a matrix of parameters
	// takes the argument of a matrix of parameters and a vector of parameter types
	matrix matrixPricer(const matrix& paramMat, const vector<enum ParamType>& paramTypes) const;

	// Matrix Pricer Version 2
	// it specifically calculate a matrix of option prices between 2 variables
	// takes the argument of 2 vectors of parameters and 2 parameter types
	matrix matrixPricer(const vector<double> param1, const vector<double> param2, const enum ParamType& paramType1, const enum ParamType& paramType2) const;
	
	// helper function to calculate current row of option value matrix pricer
	vector<double> matrixPricerHelper(double (EuropeanPutCallOption::*PriceFun)(double), EuropeanPutCallOption* currOption, const vector<double>& params) const;

	// Greek Matrix Pricer Version 1
	// Calculate the price of specified Greek for a matrix of parameters
	// takes the argument of a matrix of parameters, a vector of parameter types, and a pointer to the Greek function
	matrix matrixGreek(const matrix& paramMat, const vector<enum ParamType>& paramTypes, double (EuropeanPutCallOption::*GreekFun)(void) const) const;

	// Greek Matrix Pricer Version 2
	// Specifically focus on the relationship between 2 types of parameters
	// takes the argument of a 2 vector of parameters, 2 parameter types, and a pointer to the Greek function
	matrix matrixGreek(const vector<double>& param1, const vector<double>& param2, const enum ParamType& paramType1, const enum ParamType& paramType2, 
					   double (EuropeanPutCallOption::* GreekFun)(void) const) const;



	// Functions for Greeks, to use these functions, we assume the Option has the desired parameters already

	// calculate delta
	double Delta() const;

	// calculate gamma
	double Gamma() const;

	// calculate vega
	double Vega() const;

	// calculate theta
	double Theta() const;

	// calculate approximate delta
	double ApproxDelta(double U, double h) const;

	// calculate approximate gamma
	double ApproxGamma(double U, double h) const;

	

	

// constructors, destructor, operators, and helper functions
public:
	// default constructor
	EuropeanPutCallOption();
	
	// constructor that takes full parameters
	EuropeanPutCallOption(double T, double K, double sig, double r, double b, double U);

	// constructor that takes a struct of parameters
	EuropeanPutCallOption(const struct OptionData& sourceData);

	// constructor that takes an Option Type and a struct of parameters
	EuropeanPutCallOption(const enum OptionType& type, struct OptionData& sourceData);

	// constructor that takes an Option Type 
	EuropeanPutCallOption(const enum OptionType& type);

	// constructor that takes an Option Type and full parameters
	EuropeanPutCallOption(const enum OptionType& type, double T, double K, double sig, double r, double b, double U);

	// copy constructor
	EuropeanPutCallOption(const EuropeanPutCallOption& source);

	// assignment operator
	EuropeanPutCallOption& operator = (const EuropeanPutCallOption& rhs);

	// destructor
	virtual ~EuropeanPutCallOption();
	
	// change the option type, override the pure virtual function in base class
	void toggle();

	// type of option
	enum OptionType type;

	// helper function to display the parameters
	string DisplayParams() const;
};


// Global Functions for calculating prices or Greeks values
// These functions can be called by users directly without initiating an Option object

// calculate the option price by taking a Option Type and full parameters
double Price(const enum OptionType& type, double T, double K, double sig, double r, double b, double U);

// calculate the approximated delta by taking a Option Type and full parameters
double ApproxDelta(const enum OptionType& type, double T, double K, double sig, double r, double b, double U, double h);

// calculate the approximated gamma by taking a Option Type and full parameters
double ApproxGamma(const enum OptionType& type, double T, double K, double sig, double r, double b, double U, double h);

// calculate the delta by taking a Option Type and full parameters
double Delta(const enum OptionType& type, double T, double K, double sig, double r, double b, double U);

// calculate the gamma by taking a Option Type and full parameters
double Gamma(const enum OptionType& type, double T, double K, double sig, double r, double b, double U);

// calculate the vega by taking a Option Type and full parameters
double Vega(const enum OptionType& type, double T, double K, double sig, double r, double b, double U);

// calculate the theta by taking a Option Type and full parameters
double Theta(const enum OptionType& type, double T, double K, double sig, double r, double b, double U);


#endif