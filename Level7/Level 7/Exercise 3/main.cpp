/*
 * fileName:          main.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-06
 * @lastModifiedDate: 2020-06-06
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* STL Algorithms */

#include <iostream>
#include <vector>
#include <algorithm>
#include "functionObject.hpp"
using namespace std;

// global function to check if the input is greater
bool IsGreater(double input)
{
    // initialize a literal value as standard
    const double standard = 6;
    // return a boolean 
    return input < standard;
}


int main()
{
    // initialize number of elements
    int numElem = 10;

    // initialize a vector<double>
    vector<double> myVec;

    // fill elements into the vector
    cout << "Elements in the vector: \n";
    for (int i = 0; i != numElem; ++i)
    {
        myVec.push_back(i + 2.1);
        // print each element in the vector
        cout << myVec[i] << "  ";    
    }


    // call the global function to count 
    int countNum = count_if(myVec.begin(), myVec.end(), IsGreater);    
    // print the result
    cout << "\n\nusing global function:\n";
    cout << "There are " << countNum << " element(s) that are smaller than 6"<< endl;



    // test Function Object
    cout << "\nNow testing Function Object:";

    // initialize a variable as standard
    double standard;
    // ask for user input
    cout << "\nPlease input a number as a standard to be compared with: \n";
    // read user input
    cin >> standard;

    // initialize a FunctionObject object with constructor
    FunctionObject<double> FO(standard);
    
    // use class object instead of global function
    countNum = count_if(myVec.begin(), myVec.end(), FO);
    // print the result
    cout << "using function object:\n";
    cout << "There are " << countNum << " element(s) that are smaller than " << standard << endl;

}