/*
 * fileName:          MyTestDifferentParams.cpp
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-12
 * @lastModifiedDate: 2020-06-12
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Test the Impact of Different Combinations of J and N */

#include "FdmDirector.hpp"

#include <iostream>
#include <string>
using namespace std;

#include "UtilitiesDJD/ExcelDriver/ExcelDriverLite.hpp"


// enum Class so we can have different types for option
enum OptionType {
	Call,
	Put
};


namespace BS // Black Scholes
{
	double sig = NULL;
	double K = NULL;
	double T = NULL;
	double r = NULL;
	double D = NULL; // aka q
	enum OptionType Type;
	double SMax;

	double mySigma (double x, double t)
	{

		double sigmaS = sig*sig;

		return 0.5 * sigmaS * x * x;
	}

	double myMu (double x, double t)
	{
		
		return (r - D) * x;
	
	}

	double myB (double x, double t)
	{	
	
		return  -r;
	}

	double myF (double x, double t)
	{
		return 0.0;
	}

	double myBCL (double t)		
	{
		// Put
		if (Type == Put)
		{
			return K * exp(-r * t);
		}

		// Call
		return 0.0;
	}

	double myBCR (double t)
	{
		// Put
		if (Type == Put)
		{
			return 0.0;
		}
		// Call
		return SMax;
	}

	double myIC (double x)
	{ // Payoff 
		// Put
		if (Type == Put)
		{
			return max(K - x, 0.0);
		}

		// Call
		return max(x - K, 0.0);
	}

}

// define the type of this tuple as package for convenience
typedef tuple<vector<double>, list<vector<double>> > package;

// function to calculate the Finite difference method 
// Nvec is a vector that contains different N values
// fixedJ is a double of a fixed value J
// SMax is the largest stock price we are about
// return a tuple of a vector of double (xArray) and a list of vector of double (FDM result)
package Calculate(vector<int> Nvec, int fixedJ, double SMax)
{
	// initialize a list of double as results of FDM
	list< vector<double> > results;
	// initialize a vector to store X array
	vector<double> xArray;
	
	// for each N in the Nvec
	for (int i = 0; i != Nvec.size(); ++i)
	{
		// extract the current N value
		int currVariable = Nvec[i];

		// initialize a current Fdir object with the current parameters
		FDMDirector currFdir(SMax, BS::T, fixedJ, currVariable);

		// set XArray
		xArray = currFdir.xarr;

		// call doit() function to calculate result
		currFdir.doit();

		// store the vector result of the current N value into the result list
		results.push_back(currFdir.current());
	}

	// store the XArray and FDM result into the package
	package res = { xArray, results };

	// return the package
	return res;
}

int main()
{
	using namespace ParabolicIBVP;

	// Assignment of functions
	sigma = BS::mySigma;
	mu = BS::myMu;
	b = BS::myB;
	f = BS::myF;
	BCL = BS::myBCL;
	BCR = BS::myBCR;
	IC = BS::myIC;


	// we will use Batch1
	// initiate a tuple of 5 doubles as the parameters for Batch1
	tuple<double, double, double, double, double> paramsTuple = { 0.25, 65, 0.3, 0.08, 0.0 };

	// set BS value from the values in the tuple
	BS::T = get<0>(paramsTuple);
	BS::K = get<1>(paramsTuple);
	BS::sig = get<2>(paramsTuple);
	BS::r = get<3>(paramsTuple);
	BS::D = get<4>(paramsTuple);
	BS::SMax = 200;
	// set the Type to Call option
	BS::Type = Call;
	
	// initialize vector of different J values
	vector<int> JVals = { 30, 100, 250, 330 };
	// initialize vector of different N values
	vector<int> NVals = { 1000, 10000, 100000 };

	// initialize a package of result
	package res;
	// initialize a list of labels
	list<string> labels = { "N = 1000", "N = 10000", "N = 100000" };
	// initialize a ExcelDriver object 
	ExcelDriver xl; xl.MakeVisible(true);

	// for each J value in the vector
	for (int i = 0; i != JVals.size(); ++i)
	{
		// calculate all the N values with Calculate function
		res = Calculate(NVals, JVals[i], BS::SMax);

		// there was an exception on my machine thrown by ExcelDriver::ThrowAsString
		// so I do a try & catch so that the excel will be generated without termination 
		try
		{
			// draw in excel
			xl.CreateChart(get<0>(res), labels, get<1>(res), "Batch 1 Call Option Value with J = " + to_string(JVals[i]) + " and Different N Values", 
															 "Underlying Price (Stock Price)", " Call Option Value");
		}

		// catch the type string exception 
		catch (string message)
		{
			// print out the exception message
			cout << message << endl;
		}
		// print the computation status
		cout << "finished with J = " + to_string(JVals[i]) << endl;
	}

	// print this when all computations are done
	cout << "Finished!" << endl;
	return 0;
}
