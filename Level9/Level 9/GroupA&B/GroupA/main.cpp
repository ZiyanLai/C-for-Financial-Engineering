/*
 * fileName:          main.cpp
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-10
 * @lastModifiedDate: 2020-06-10
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Test various functionalities for Option */

#include <iostream>
#include "EuropeanPutCallOption.hpp"
#include "PerpetualAmericanOption.hpp"
#include "boost/tuple/tuple.hpp"
#include "boost/tuple//tuple_io.hpp"
#include <vector>
using namespace std;

// define vector of a vector to type matrix
typedef vector< vector<double> > matrix;

int main()
{   
    cout << "Start testing on European Option: \n\n";
   
    {
		// test various constructors and assignment operator for EuropeanPutCallOption class
		cout << "Testing various constructors and assignment operator: \n";

        EuropeanPutCallOption myEUCall0;
        cout << "myEUCall0 (default constructor): " << myEUCall0.DisplayParams() << endl;

		EuropeanPutCallOption myEUCall1(0.25, 65, 0.3, 0.08, 0.08, 60);
		cout << "\nmyEUCall1 (constructor that takes full parameters): " << myEUCall1.DisplayParams() << endl;

		EuropeanPutCallOption myEUCall2(Call);
		cout << "\nmyEUCall2 (constructor that takes only a Type): " << myEUCall2.DisplayParams() << endl;

        EuropeanPutCallOption myEUCall3(Call, 0.25, 65, 0.3, 0.08, 0.08, 60);
		cout << "\nmyEUCall3 (constructor that takes type and full parameters): " << myEUCall3.DisplayParams() << endl;
        
        // initialize a struct of parameters
        // order in the struct: r, Sig, K, T, b, U
        OptionData params = { 0.08, 0.3, 65, 0.25, 0.08, 60 };

        EuropeanPutCallOption myEUCall4(params);
		cout << "\nmyEUCall4 (constructor that takes a struct of parameters): " << myEUCall4.DisplayParams() << endl;

		EuropeanPutCallOption myEUCall5(Put, params);
		cout << "\nmyEUCall5 (constructor that takes an option Type and a struct of parameters): " << myEUCall5.DisplayParams() << endl;

        EuropeanPutCallOption myEUCall6(myEUCall5);
        cout << "\nmyEUCall6 (copy constructor by copying myEUCall5): " << myEUCall6.DisplayParams() << endl;

        cout << "\nassignment operator: myEUCall6 = myEUCall0\n";
        myEUCall6 = myEUCall0;
        cout << "myEUCall6: " << myEUCall6.DisplayParams() << endl;

        cout << "\ntoggle myEUCall6\n";
        myEUCall6.toggle();
        cout << "myEUCall6: " << myEUCall6.DisplayParams() << "\n\n";
    }



    {
		// start testing European Option Price functions
		cout << "Testing European Option Price functions: \n";

        // define a tuple that contains 5 double as type Params, for convenience
        typedef boost::tuple<double, double, double, double, double> Params;

        // create a vector that contain Params
        vector<Params> batches;

        // create 4 batches of data
        Params batch1(0.25, 65, 0.3, 0.08, 60);
        Params batch2(1.0, 100, 0.2, 0.0, 100);
        Params batch3(1.0, 10, 0.5, 0.12, 5);
        Params batch4(30.0, 100, 0.3, 0.08, 100);

        // push these batches into the vector
        batches.push_back(batch1);
        batches.push_back(batch2);
        batches.push_back(batch3);
        batches.push_back(batch4);


        //  for each batch
        for (int i = 0; i != 4; ++i)
        {
            // get the current batch of Params
            Params currBatch = batches[i];
            // initialize an OptionData struct
            OptionData currData;

            // assign current batch's value into the struct
            currData.T = currBatch.get<0>();
            currData.K = currBatch.get<1>();
            currData.sig = currBatch.get<2>();
            currData.r = currBatch.get<3>();
            currData.b = currData.r;
            currData.U = currBatch.get<4>();

            // initialize a Call option with the constructor that takes a struct of parameters
            EuropeanPutCallOption currOption(currData);

            // display the parameters
            cout << currOption.DisplayParams() << endl;

            // display the Call value
            cout << "Call Value (using Black-Scholes): " << currOption.Price();

            // display the Put value using Put-Call Parity
            cout << "; Put Value (using Put-Call Parity): " << currOption.PutCallParity(currOption.Price()) << endl;

            // change the option to Put
            currOption.toggle();

            // display the Put value
            cout << "Put Value (using Black-Scholes): " << currOption.Price();

            // display the Call value using Put-Call parity
            cout << "; Call Value (using Put-Call Parity): " << currOption.PutCallParity(currOption.Price()) << endl;

        }
    }

    {
        // Test on mesh generator
        cout << "\nGenerate a mesh of Stock Prices and calculate option prices: \n";

        // use global function to generate a mesh of stock prices
        vector<double> mesh = generateMesh(10.0, 50.0, 40);
        // initialize a vector to store call value 
        vector<double> callValue;
        // use constructor that takes full parameters
        EuropeanPutCallOption myEUCall(0.25, 65, 0.3, 0.08, 0.08, NULL);

        // display the parameters 
        cout << myEUCall.DisplayParams() << endl;

        // for each stock price in the mesh
        for (int i = 0; i != mesh.size(); ++i)
        {
            // calculate and push the Call option value into the vector
            callValue.push_back(myEUCall.PriceWithStock(mesh[i]));
        }

        // for each value in the call option vector
        for (int i = 0; i != mesh.size(); ++i)
        {
            // print the stock price and corresponding Call Option value
            cout << "Stock Price = " << mesh[i] << ", European Call Option Value: " << callValue[i] << endl;
        }

    }

    {
        // testing the 2 versions of matrix pricer with various T and Sig
        cout << "\nTesting on 2 versions of Matrix Pricer on variable T and Sig: \n\n";

        // Start with Version 1
        cout << "Testing Matrix Pricer Version 1: \n";

        // create a batch of data and construct a Call option
		OptionData batch = { 0.08, 0.3, 65, 0.25, 0.08, 60 };
		EuropeanPutCallOption myEUCall1(Call, batch);

		// display the parameters in the Option
		cout << myEUCall1.DisplayParams() << "\n\n";

        // generate various mesh of parameters
		vector<double> sMesh = generateMesh(50, 100, 7);
		vector<double> kMesh = generateMesh(50, 70, 7);
		vector<double> rMesh = generateMesh(0.02, 0.1, 7);
		vector<double> sigMesh = generateMesh(0.1, 0.8, 7);
		vector<double> tMesh = generateMesh(0.25, 1.05, 7);
		vector<double> bMesh = generateMesh(0.02, 0.1, 7);

        // store them in to the parameter matrix
		matrix paramMat = { sMesh, kMesh, rMesh, sigMesh, tMesh, bMesh };

        // initialize a parameter type vector
		vector<enum ParamType> paramName = { Stock, Strike, IntRate, Vol, Time, COC };

        // use matrix pricer version1 to calculate a result matrix
		matrix resultMatrix = myEUCall1.matrixPricer(paramMat, paramName);


		for (int i = 0; i != resultMatrix.size(); ++i)
		{
            // print the header of matrix
			cout << "Varying " << enumToString(paramName[i]) << " from " << paramMat[i][0] << " to " << paramMat[i][paramMat[i].size() - 1] << ": ";
			for (int j = 0; j != resultMatrix[i].size(); ++j)
			{
                // print values in matrix
				cout << resultMatrix[i][j] << " ";
			}
			cout << endl;
		}

		// Then Version 2
		cout << "\nTesting Matrix Pricer Version 2: \n";

        // initialize a vector of T
        vector<double> vectorT;

        // initialize a vector if Sig
        vector<double> vectorSig;

        // set initial T and Sig
        double currT = 0.25;
        double currSig = 0.3;

        // use constructor that takes full parameters
        // we set initial T and Sig to current T and current Sig
        EuropeanPutCallOption myEUCall2(currT, 65, currSig, 0.08, 0.08, 60);

        // display the parameters in the Option
        cout << myEUCall2.DisplayParams() << endl;

        for (int i = 0; i != 5; ++i)
        {
            // push 5 different T values 
            vectorT.push_back(currT);
            // increment currT
            currT += 0.2;
        }

        for (int i = 0; i != 5; ++i)
        {
            // push 5 different Sig values
            vectorSig.push_back(currSig);
            // increment currSig
            currSig += 0.1;
        }	

        // print header of the matrix
        cout << "Row: " << enumToString(Vol) << " varying from " << vectorSig[0] << " to " << vectorSig[vectorSig.size() - 1] << endl;
        cout << "Column: " << enumToString(Time) << " varying from " << vectorT[0] << " to " << vectorT[vectorT.size() - 1] << "\n\n";

        // use matrix pricer version 2 to calculate
		resultMatrix = myEUCall1.matrixPricer(vectorT, vectorSig, Time, Vol);

		for (int i = 0; i != resultMatrix.size(); ++i)
		{
			for (int j = 0; j != resultMatrix[i].size(); ++j)
			{
                // print the result matrix
				cout << resultMatrix[i][j] << " ";
			}
			cout << endl;
		}
    }
    

    {
        // Test the Greeks functionalities
        cout << "\n" << "Testing Greeks Formulas: \n";

        // initialize European Option with constructor that takes full parameters
        EuropeanPutCallOption myEUCall(0.5, 100, 0.36, 0.1, 0, 105);
        // display parameters in the Call option
        cout << myEUCall.DisplayParams() << endl;
        // calculate Delta using member function
        cout << "Call's Delta (using member function): " << myEUCall.Delta() << endl;
        // calculate Delta using global function
        cout << "Call's Delta (using Global Function): " << Delta(Call, 0.5, 100, 0.36, 0.1, 0, 105) << endl;

        // switch the type to Put
        myEUCall.toggle();
        // display parameters in the Put option
        cout << myEUCall.DisplayParams() << endl;
        // calculate Delta using member function
        cout << "Put's Delta (using member function): " << myEUCall.Delta() << endl;
        // calculate Delta using global function
        cout << "Put's Delta (using Global Function): " << Delta(Put, 0.5, 100, 0.36, 0.1, 0, 105) << endl;


        // test on mesh generator
        cout << "\n" << "Generate a mesh of Stock Prices and calculate Delta:\n";
        // switch the type back to Call
        myEUCall.toggle();
        // set stock price to NULL as we will use various stock prices later on
        myEUCall.U = NULL;
        // display parameters
        cout << myEUCall.DisplayParams() << endl;
        // create a mesh of different stock prices
        vector<double> UMesh = generateMesh(10, 50, 40);
        // initialize a vector to store the Delta results
        vector<double> EUCallDelta;

        for (int i = 0; i != UMesh.size(); ++i)
        {
            // assign the current stock price
            myEUCall.U = UMesh[i];
            // calculate Delta
            double callDelta = myEUCall.Delta();
            // push the result into the vector
            EUCallDelta.push_back(callDelta);
        }

        for (int i = 0; i != UMesh.size(); ++i)
        {
            // print each stock price and their corresponding delta
            cout << "Stock Price: " << UMesh[i] << ", Call's Delta: " << EUCallDelta[i] << endl;
        }

    }

    {
		// Test the Greeks Matrix Pricers
		cout << "\n" << "Testing Greeks Matrix Pricer: \n";
	    
        // initialize a Call Option
        EuropeanPutCallOption myEUCall(0.5, 100, 0.36, 0.1, 0.0, 105);

		// initialize a vector for different T
        vector<double> deltaVectorT = generateMesh(myEUCall.T, 5, 7);

		// initialize a vector for different Sig
        vector<double> deltaVectorSig = generateMesh(myEUCall.sig, 0.8, 7);

		// initialize a vector for different K
		vector<double> deltaVectorK = generateMesh(myEUCall.K, 110, 7);

		// initialize a vector for different r
		vector<double> deltaVectorR = generateMesh(myEUCall.r, 0.5, 7);
		

        cout << "\nTest Greek Matrix Pricer Version 1: \n";

        // display the initial parameters
        cout << myEUCall.DisplayParams() << "\n\n";

        // initialize the matrix of parameters
        matrix paramMat = { deltaVectorT, deltaVectorSig, deltaVectorK, deltaVectorR };

        // initialize a vector of parameter types
        vector<enum ParamType> paramType = { Time, Vol, Strike, IntRate };

        // calculate the result matrix with Greek Matrix Pricer version 1
        matrix res = myEUCall.matrixGreek(paramMat, paramType, &EuropeanPutCallOption::Delta);


        for (int i = 0; i != res.size(); ++i)
        {
            // print the header of matrix
            cout << "Varying " << enumToString(paramType[i]) << " from " << paramMat[i][0] << " to " << paramMat[i][paramMat[i].size() - 1] << ": ";
            for (int j = 0; j != res[i].size(); ++j)
            {
                // print out the result
                cout << res[i][j] << " ";
            }
            cout << endl;
        }


        // test Greek Matrix Pricer version 2
        cout << "\nTest Greek Matrix Pricer Version 2:\n";

		// display the initial parameters
		cout << myEUCall.DisplayParams() << endl;

		// print header of the matrix
		cout << "Row: " << enumToString(Vol) << " varying from " << deltaVectorSig[0] << " to " << deltaVectorSig[deltaVectorSig.size() - 1] << endl;
		cout << "Column: " << enumToString(Time) << " varying from " << deltaVectorT[0] << " to " << deltaVectorT[deltaVectorT.size() - 1] << "\n\n";

        // calculate the result matrix with Greek Matrix Pricer version 2
        res = myEUCall.matrixGreek(deltaVectorT, deltaVectorSig, Time, Vol, &EuropeanPutCallOption::Delta);
		for (int i = 0; i != res.size(); ++i)
		{
			for (int j = 0; j != res[i].size(); ++j)
			{
                // display the results
				cout << res[i][j] << " ";
			}
			cout << endl;
		}
    }
    


    {
        // start testing approximate delta and gamma functions
        cout << "\n\nTesting Approximate Greeks: \n";

        cout << "\nTesting Approximate Delta: \n";

        // initialize an Option
        EuropeanPutCallOption myEUCall(0.5, 100, 0.36, 0.1, 0, 105);

        // generate a mesh of different h
        vector<double> hMesh = generateMesh(0.01, 10, 50);

        // display parameters 
        cout << myEUCall.DisplayParams() << endl;

        // print the exact delta value
        cout << "\nExact Delta: " << myEUCall.Delta() << endl;

        for (int i = 0; i != hMesh.size(); ++i)
        {
            // calculate current approximate delta using member function
            double approxDelta1 = myEUCall.ApproxDelta(myEUCall.U, hMesh[i]);
            // calculate current approximate delta using global function
            double approxDelta2 = ApproxDelta(myEUCall.type, myEUCall.T, myEUCall.K, myEUCall.sig, myEUCall.r, myEUCall.b, myEUCall.U, hMesh[i]);
            // print the current delta
            cout << "h: " << hMesh[i] << ", Approx.Delta (member function): " << approxDelta1 << ", Approx.Delta (global function):" << approxDelta2 << endl;
        }

        // print the exact gamma value
        cout << "\n\nExact Gamma: " << myEUCall.Gamma() << endl;
        for (int i = 0; i != hMesh.size(); ++i)
        {
            // calculate current approximate gamma using member function
            double approxGamma1 = myEUCall.ApproxGamma(myEUCall.U, hMesh[i]);

            // calculate current approximate gamma using global function
            double approxGamma2 = ApproxGamma(myEUCall.type, myEUCall.T, myEUCall.K, myEUCall.sig, myEUCall.r, myEUCall.b, myEUCall.U, hMesh[i]);

            // print out the current gamma
            cout << "h: " << hMesh[i] << ", Approx.Gamma (member function): " << approxGamma1 << ", Approx.Gamma (global function):" << approxGamma2 << endl;
        }

    }

    
    // start testing on Perpetual American Option
    cout << "\n\n\n\Testing Perpetual American Option: \n\n";

    {
        cout << "Testing various constructors and assignment operator: \n";
        // test various constructors and assignment operator for PerpetualAmericanOption class
        {
            PerpetualAmericanOption myAMCall0;
            cout << "myAMCall0 (default constructor): " << myAMCall0.DisplayParams() << endl;

            PerpetualAmericanOption myAMCall1(65, 0.3, 0.08, 0.08, 60);
            cout << "\nmyAMCall1 (constructor that takes full parameters): " << myAMCall1.DisplayParams() << endl;

            PerpetualAmericanOption myAMCall2(Call);
            cout << "\nmyAMCall2 (constructor that takes only a Type): " << myAMCall2.DisplayParams() << endl;

            PerpetualAmericanOption myAMCall3(Call, 65, 0.3, 0.08, 0.08, 60);
            cout << "\nmyAMCall3 (constructor that takes type and full parameters): " << myAMCall3.DisplayParams() << endl;

            // initialize a struct of parameters
            // order in the struct: r, Sig, K, T, b, U
            OptionData params = { 0.08, 0.3, 65, NULL, 0.08, 60 };

            PerpetualAmericanOption myAMCall4(params);
            cout << "\nmyAMCall4 (constructor that takes a struct of parameters): " << myAMCall4.DisplayParams() << endl;

            PerpetualAmericanOption myAMCall5(Put, params);
            cout << "\nmyAMCall5 (constructor that takes an option Type and a struct of parameters): " << myAMCall5.DisplayParams() << endl;

            PerpetualAmericanOption myAMCall6(myAMCall5);
            cout << "\nmyAMCall6 (copy constructor by copying myEUCall5): " << myAMCall6.DisplayParams() << endl;

            cout << "\nassignment operator: myAMCall6 = myAMCall0\n";
            myAMCall6 = myAMCall0;
            cout << "myAMCall6: " << myAMCall6.DisplayParams() << endl;

            cout << "\ntoggle myAMCall6\n";
            myAMCall6.toggle();
            cout << "myAMCall6: " << myAMCall6.DisplayParams() << "\n\n";
        }
    }

    {
        cout << "Testing Perpetual American Option Pricing formula: \n";

        // initialize an American Option with constructor that takes full parameters
        PerpetualAmericanOption myAMCall(100.0, 0.1, 0.1, 0.02, 110);

        // display parameters
        cout << myAMCall.DisplayParams() << endl;

        // print and calculate option value using member function
        cout << "American Call Option Value(Using member function): " << myAMCall.Price() << endl;

        // print and calculate option value using global function
        cout << "American Call Option Value(Using global function): " << Price(Call, 100.0, 0.1, 0.1, 0.02, 110) << endl;

        // initialize an American Option with constructor that takes an Option type and full parameters
        PerpetualAmericanOption myAMPut(Put, 100.0, 0.1, 0.1, 0.02, 110);

        // display parameters
        cout << "\n" << myAMPut.DisplayParams() << endl;

        // print and calculate option value using member function
        cout << "American Put Option Value(Using member function): " << myAMPut.Price() << endl;

        // print and calculate option value using global function
        cout << "American Put Option Value(Using global function): " << Price(Put, 100.0, 0.1, 0.1, 0.02, 110) << endl;


        cout << "\nGenerate a mesh of Stock Price and calculate Option value: " << endl;
        // set stock price to NULL, as we will assign different stock values later on
        myAMCall.U = NULL;

        // display parameters
        cout << myAMCall.DisplayParams() << endl;

        vector<double> UMesh = generateMesh(10, 50, 40);

        for (int i = 0; i != UMesh.size(); ++i)
        {
            // assign current stock price
            myAMCall.U = UMesh[i];
            // calculate using PriceWithStock
            double amVal = myAMCall.PriceWithStock(UMesh[i]);
            // print out the option value 
            cout << "Stock Price: " << UMesh[i] << ", American Call's value: " << amVal << endl;
        }
    }

    {
        // testing the 2 versions of matrix pricer with various T and Sig
        cout << "\nTesting on 2 versions of Matrix Pricer on variable T and Sig: \n\n";

        // Start with Version 1
        cout << "Testing Matrix Pricer Version 1: \n";

        // create a batch of data and construct a Call option
        OptionData batch = { 0.1, 0.1, 100, NULL, 0.02, 110 };
        PerpetualAmericanOption myAMCall1(Call, batch);

        // display the parameters in the Option
        cout << myAMCall1.DisplayParams() << "\n\n";

        // generate various mesh of parameters
        vector<double> sMesh = generateMesh(50, 110, 7);
        vector<double> kMesh = generateMesh(50, 100, 7);
        vector<double> rMesh = generateMesh(0.02, 0.1, 7);
        vector<double> sigMesh = generateMesh(0.1, 0.8, 7);
        vector<double> bMesh = generateMesh(0.02, 0.1, 7);

        // store them in to the parameter matrix
        matrix paramMat = { sMesh, kMesh, rMesh, sigMesh, bMesh };

        // initialize a parameter type vector
        vector<enum ParamType> paramName = { Stock, Strike, IntRate, Vol, COC };

        // use matrix pricer version1 to calculate a result matrix
        matrix resultMatrix = myAMCall1.matrixPricer(paramMat, paramName);


        for (int i = 0; i != resultMatrix.size(); ++i)
        {
            // print the header of matrix
            cout << "Varying " << enumToString(paramName[i]) << " from " << paramMat[i][0] << " to " << paramMat[i][paramMat[i].size() - 1] << ": ";
            for (int j = 0; j != resultMatrix[i].size(); ++j)
            {
                // print values in matrix
                cout << resultMatrix[i][j] << " ";
            }
            cout << endl;
        }

        // Then Version 2
        cout << "\nTesting Matrix Pricer Version 2: \n";

        // initialize a vector of K
        vector<double> vectorK;

        // initialize a vector if Sig
        vector<double> vectorSig;

        // set initial T and Sig
        double currK = 50;
        double currSig = 0.1;

        // use constructor that takes full parameters
        // we set initial T and Sig to current K and current Sig
        PerpetualAmericanOption myAMCall2(currK, currSig, 0.1, 0.02, 110);

        // display the parameters in the Option
        cout << myAMCall2.DisplayParams() << endl;

        for (int i = 0; i != 5; ++i)
        {
            // push 5 different K values 
            vectorK.push_back(currK);
            // increment currK
            currK += 15;
        }

        for (int i = 0; i != 5; ++i)
        {
            // push 5 different Sig values
            vectorSig.push_back(currSig);
            // increment currSig
            currSig += 0.1;
        }

        // print header of the matrix
        cout << "Row: " << enumToString(Strike) << " varying from " << vectorK[0] << " to " << vectorK[vectorK.size() - 1] << endl;
        cout << "Column: " << enumToString(Vol) << " varying from " << vectorSig[0] << " to " << vectorSig[vectorSig.size() - 1] << "\n\n";

        // use matrix pricer version 2 to calculate
        resultMatrix = myAMCall2.matrixPricer(vectorSig, vectorK, Vol, Strike);

        for (int i = 0; i != resultMatrix.size(); ++i)
        {
            for (int j = 0; j != resultMatrix[i].size(); ++j)
            {
                // print the result matrix
                cout << resultMatrix[i][j] << " ";
            }
            cout << endl;
        }


    }
    
}
