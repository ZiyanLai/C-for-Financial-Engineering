/*
 * fileName:          MyTestBatches.cpp
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-12
 * @lastModifiedDate: 2020-06-12
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Compare Results of FDM Between Different Batches of Data */

#include "FdmDirector.hpp"
#include <iostream>
#include <string>
using namespace std;
#include "UtilitiesDJD/ExcelDriver/ExcelDriverLite.hpp"


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

	// set values for J, N, SMax
	int J = 200;
	int N = 150000;
	double SMax = 400;

	// define a tuple of 5 doubles as type paramsTuple for convenience
	typedef tuple<double, double, double, double, double> paramsTuple;

	// create 4 batches of parameters
	paramsTuple Batch1 = { 0.25, 65, 0.3, 0.08, 0.0 };
	paramsTuple Batch2 = { 1.0, 100, 0.2, 0.0, 0.0 };
	paramsTuple Batch3 = { 1.0, 10, 0.5, 0.12, 0.0 };
	paramsTuple Batch4 = { 30.0, 100, 0.3, 0.08, 0.0 };

	// create a vector to store all the batches
	vector<paramsTuple> Batches;

	// push each batch into the vector
	Batches.push_back(Batch1);
	Batches.push_back(Batch2);
	Batches.push_back(Batch3);
	Batches.push_back(Batch4);

	// create a vector of 2 Option types
	vector<OptionType> types = { Call, Put };
	
	// create a list of vector to store FDM results
	list< vector<double> > results;
	// create a vector of double to store xArray
	vector<double> xArray;

	// initialize a string for printing purpose
	string printStr;

	// for each Option type
	for (int t = 0; t != 2; ++t)
	{
		// set BS type to the current option type
		BS::Type = types[t];
		
		// if current type is Call
		if (types[t] == Call)
		{
			// set print string to "Call"
			printStr = "Call";
		}
		// if current type is Put
		if (types[t] == Put)
		{
			// set print string to "Put"
			printStr = "Put";
		}

		// print the computing status
		cout << "Calculating on " << printStr << " Option:\n";

		// for each batch of parameters
		for (int i = 0; i != Batches.size(); ++i)
		{
			// extract the current batch 
			paramsTuple currBatch = Batches[i];
			// assign batch parameters to BS
			BS::T = get<0>(currBatch);
			BS::K = get<1>(currBatch);
			BS::sig = get<2>(currBatch);
			BS::r = get<3>(currBatch);
			BS::D = get<4>(currBatch);
			// set BS SMax
			BS::SMax = SMax;

			//create FDMDirector object with the current parameters
			FDMDirector currFdir(SMax, BS::T, J, N);

			// store xArray
			xArray = currFdir.xarr;

			// call doit function to compute
			currFdir.doit();

			// push the current FDM result into the list
			results.push_back(currFdir.current());

			// print computing status
			cout << "Finished Batch " << i + 1 << endl;

		}
		// print computing status
		cout << "Done with " << printStr << " Option.\n";
	}
	
	// print this when finished all computations
	cout << "Finished!\n";

	// initialize a list of labels
	list<string> labels = { "Batch1_Call","Batch2_Call","Batch3_Call","Batch4_Call","Batch1_Put","Batch2_Put","Batch3_Put","Batch4_Put" };
	// initialize an ExcelDrive object
	ExcelDriver xl; xl.MakeVisible(true);

	// there was an exception on my machine thrown by ExcelDriver::ThrowAsString
	// so I do a try & catch so that the excel will be generated without termination 
	try 
	{
		// call CreateChart function to plot in excel
		xl.CreateChart(xArray, labels, results, "Comparing Option Value between Different Batches", "Underlying Price (Stock Price)", "Option Value");
	}
	// catch the type string exception 
	catch (string message)
	{
		// print the exception message
		cout << message << endl;
	}
	
	return 0;
}
