/*
 * fileName:          Option.hpp
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-10
 * @lastModifiedDate: 2020-06-10
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Header file of the Option base class */

#ifndef OPTION_HPP
#define OPTION_HPP

#include <iostream>
#include <vector>
using namespace std;


class Option
{

// give it 2 private function which will be used when initialization
private:

	// function to assign values when initialization
	void init();

	// function to copy values when initialization
	void copy(const Option& source);

// some public member data so that the user can access these parameters
// derived class will inherit these parameters
public:
	double r;		// Interest rate
	double sig;		// Volatility
	double K;		// Strike price
	double T;		// Expiry date
	double b;		// Cost of carry
	double U;		// current Underlying price

	// pure virtual function to change the Option type
	// this ensures any derived Option class must have a toggle function
	virtual void toggle() = 0;

	// pure virtual function to Calculate the price of Option
	// this ensures any derived Option class must have a Price function
	virtual double Price() const = 0;


// some constructors, destructor, operators, and helper functions
public:
	// default constructor
	Option();

	// constructor that takes full parameters
	Option(double T, double K, double sig, double r, double b, double U);

	// constructor that takes a struct of parameters
	Option(const struct OptionData& sourceData);

	// copy constructor
	Option(const Option& anotherEO);

	// destructor
	virtual ~Option();

	//assignment operator
	Option& operator = (const Option& rhs);

	// function to display the parameters in the Option
	virtual string DisplayParams() const = 0;

};


// a struct of Option parameters
struct OptionData
{
	double r;		// Interest rate
	double sig;		// Volatility
	double K;		// Strike price
	double T;		// Expiry date
	double b;		// Cost of carry
	double U;		// current underlying price
};


// an enum class of OptionType, which is consists of Call and Put
enum OptionType 
{
	Call,
	Put
};

// an enum class of Parameter Type
enum ParamType
{
	Stock,		// stock price
	Strike,		// strike price
	Time,		// time to maturity
	IntRate,	// interest rate
	COC,		// cost of carry
	Vol,		// volatility
};


// helper function to print the enum to string
string enumToString(const enum ParamType& paramType);


// global function to generate a mesh
vector<double> generateMesh(double start, double end, int meshSize);

#endif