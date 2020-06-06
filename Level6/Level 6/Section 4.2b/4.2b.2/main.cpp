/*
 * fileName:          main.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-03
 * @lastModifiedDate: 2020-06-03
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Test the NumericArray class */

#include <iostream>
#include "array.cpp"
#include "numericArray.cpp"
#include "point.hpp"
#include "shape.hpp"
#include "arrayException.hpp"
using namespace std;

int main()
{
    NumericArray<Point> dummyPointArray;    // Yes, we can create an NumericArray with type Point;
                                            // however, the template assumes the type can be able to conduct 
                                            // + * operations, where Point object cannot.
                                            // So even if we can create an NumericArray with type Point,
                                            // we cannot conduct any of the following numeric operations.

    // test default constructor
    NumericArray<int> intArray0;  
    // test constructor that takes a size      
    NumericArray<int> intArray1(10);
    // test copy constructor 
    NumericArray<int> intArray2(intArray1);
    // create a large array
    NumericArray<int> intArray3(100);
    
    // fill in numbers in intArray1
    intArray1[0] = 5;
    intArray1[1] = 6;
    intArray1[2] = 10;
    // fill in numbers in intArray2
    intArray2[0] = 3;
    intArray2[1] = 7;
    intArray2[2] = 9;
    
    // print out elements in intArray1
    cout << "First 3 elements in intArray1: ";
    for (int i = 0; i != 3; ++i)
    {
        cout << intArray1[i] << " ";
    }
    
    // print out elements in intArray1
    cout << "\nFirst 3 elements in intArray2: ";
    for (int i = 0; i != 3; ++i)
    {
        cout << intArray2[i] << " ";
    }
    cout << endl;

  
    // test try catch and throw in the NumericArray class
    try
    {
        // this is supposed to be OK since these two arrays have the same size
        NumericArray<int> intArray4 = intArray1 + intArray2;
        cout << "\nintArray4 = intArray1 + intArray2; First 3 elements in intArray4: ";
        for (int i = 0; i !=3; ++i)
        {
            cout << intArray4[i] << " ";
        }
        cout << endl;
    }
    catch(ArrayException& ae)
    {
        cout << ae.GetMessage() << endl;
    }
    
    try
    {
        // this is supposed to get an error because size does not match
        cout << "intArray5 = intArray1 + intArray3; ";
        NumericArray<int> intArray5 = intArray1 + intArray3;
    }
    catch(ArrayException& ae)
    {
        cout << ae.GetMessage() << endl;
    }
    
    // test * operator 
     cout << "\nintarray6 = intArray1 * 8; ";
     NumericArray<int> intArray6 = intArray1 * 8;

     // print out the first 3 elements
     cout << "First 3 elements in intArray6: ";
    for (int i = 0; i != 3; ++i)
    {
        cout << intArray6[i] << " ";
    }
    cout << endl;

    // test dot product function
    cout << "\nAll elements in intArray1: ";  // print all elements in intArray1
    for (int i = 0; i != intArray1.Size(); ++i)
    {
        cout << intArray1[i] << " ";
    }
    cout << "\nAll elements in intArray2: ";
    for (int i = 0; i != intArray2.Size(); ++i) // print all elements in intArray2
    {
        cout << intArray2[i] << " ";
    }
    cout << endl;

    int res = intArray1.dotProduct(intArray2);  // call the dotProduct function
    cout << "The dot product of intArray1 and intArray2 is: " << res << endl;   // display the result

    return 0;
}
