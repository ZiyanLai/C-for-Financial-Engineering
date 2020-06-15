/*
 * fileName:          MyDrawCallOptionBatches.cpp
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-11
 * @lastModifiedDate: 2020-06-11
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Plot Call Option Values for Different Batches in Excel */


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
	// create struct of different batches of data
	// parameter order in the struct: r, sig, K, T, b, U
	OptionData Batch1 = {0.08, 0.3, 65, 0.25, 0.08, NULL};
	OptionData Batch2 = {0.0, 0.2, 100, 1.0, 0.0, NULL};
	OptionData Batch3 = {0.12, 0.5, 10, 1.0, 0.12, NULL};
	OptionData Batch4 = {0.08, 0.3, 100, 30, 0.08, NULL};

	// creat Call objects using constructor that takes a Option type and a struct
	EuropeanPutCallOption Call1(Call, Batch1);
	EuropeanPutCallOption Call2(Call, Batch2);
	EuropeanPutCallOption Call3(Call, Batch3);
	EuropeanPutCallOption Call4(Call, Batch4);

	// create a vector of EuropeanPutCallOptin
	vector<EuropeanPutCallOption> allCall;

	// push all the Call Options into the vector
	allCall.push_back(Call1);
	allCall.push_back(Call2);
	allCall.push_back(Call3);
	allCall.push_back(Call4);

	// create a master list of vectors to store the results for different batches
	list< vector<double> > allBatchVal;

	// generate a stock price mesh
	// this function is defined in the Option.cpp class
	vector<double> stockPriceMesh = generateMesh(10, 50, 40);

	//iterate through each batch
	for (int i = 0; i != allCall.size(); ++i)
	{
		// initialize a vector to store the option values for current batch
		vector<double> tempBatchPrice;

		for (int j = 0; j != stockPriceMesh.size(); ++j)
		{
			// set the current stock price to the current Call Option object
			allCall[i].U = stockPriceMesh[j];

			// calculate and push the current option value
			tempBatchPrice.push_back(allCall[i].Price());
		}
		// push the vector of option prices of current batch into the master list
		allBatchVal.push_back(tempBatchPrice);
	}

	// create a list of string for labels
	list<string> labels;

	// push different strings into the labels vector
	labels.push_back("Batch1 Call");
	labels.push_back("Batch2 Call");
	labels.push_back("Batch3 Call");
	labels.push_back("Batch4 Call");

	// initialize an ExcelDriver object
	ExcelDriver xl; xl.MakeVisible(true);
	
	// there was an exception on my machine thrown by ExcelDriver::ThrowAsString
	// so I do a try & catch so that the excel will be generated without termination 
	try
	{
		// call CreateChart function to plot in Excel
		xl.CreateChart(stockPriceMesh, labels, allBatchVal, "Comparing Call Option Value between Different Batches", "Underlying Price (Stock Price)", "Call Option Value");
	}
	
	// catch the type string exception
	catch (string message)
	{
		// print the exception message
		cout << message << endl;
	}
	

	return 0;
}
