/*
 * fileName:          MyDrawPutCallOptions.cpp
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-11
 * @lastModifiedDate: 2020-06-11
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Plot Put and Call Option Values Using the Same Batches in Excel */


#include "ExcelDriverLite.hpp"
#include "Utilities.hpp"
#include "Option.hpp"
#include "EuropeanPutCallOption.hpp"
#include <cmath>
#include <list>
#include <string>
#include <vector>


int main()
{
	// initialize a struct of parameters
	// parameter order in the struct: r, sig, K, T, b, U
	OptionData Batch = { 0.05, 0.2, 25, 1, 0.05, NULL};

	// initialize a Call object and a Put object 
	// using the constructor that takes a option Type and a struct of parameters
	EuropeanPutCallOption CallOption(Call, Batch);
	EuropeanPutCallOption PutOption(Put, Batch);
	
	// initialize a vector of Option object
	vector<EuropeanPutCallOption> allOption;
	// push the Call and the Put object into the vector
	allOption.push_back(CallOption);
	allOption.push_back(PutOption);
	
	// initialize a master list of vector as the results
	list< vector<double> > allBatchVal;

	// generate a vector of stock prices using the generateMesh global function
	// this function is defined in Option.cpp class
	vector<double> stockPriceMesh = generateMesh(10, 50, 40);

	// iterate through the Option vector
	for (int i = 0; i != allOption.size(); ++i)
	{
		// initialize a temp vector to store the option value for current batch
		vector<double> tempBatchPrice;

		for (int j = 0; j != stockPriceMesh.size(); ++j)
		{	
			// set the current stock price to the current Option object
			allOption[i].U = stockPriceMesh[j];

			// calculate and push the option value into the temp vector
			tempBatchPrice.push_back(allOption[i].Price());
		}
		// push the temp vector into the master list 
		allBatchVal.push_back(tempBatchPrice);
	}

	// initialize a list of strings as labels
	list<string> labels;
	// push the strings into the list
	labels.push_back("Call Option");
	labels.push_back("Put Option");

	// initialize a ExcelDriver object 
	ExcelDriver xl; xl.MakeVisible(true);

	// there was an exception on my machine thrown by ExcelDriver::ThrowAsString
	// so I do a try & catch so that the excel will be generated without termination 
	try {
		// call the CreateChart function to plot in Excel
		xl.CreateChart(stockPriceMesh, labels, allBatchVal, "Comparing Call and Put Option Value With Same Parameters", "Underlying Price (Stock Price)", "Option Value");
	}
	
	// catch the type string exception
	catch (string message)
	{
		// print the exception message
		cout << message << endl;
	}

	return 0;
}
