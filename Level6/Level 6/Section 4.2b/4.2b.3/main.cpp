/*
 * fileName:          main.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-03
 * @lastModifiedDate: 2020-06-03
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Test the PointArray class */
#include <iostream>
#include "array.cpp"
#include "pointArray.hpp"
#include "point.hpp"
#include "shape.hpp"
#include "arrayException.hpp"
using namespace std;

int main()
{
    // test default constructor
    PointArray ptArray0;

    // test constructor that takes size
    PointArray ptArray1(10);

    // store Point objects into ptArray1
    cout << "ptArray1: \n";
    for (int i = 0; i != ptArray1.Size(); ++i)
    {
        // store Point in each index
        ptArray1[i] = Point(i,i);
        // print the current Point
        cout << "index" << i << ": " << ptArray1[i].ToString() << " ";
    }
    cout << endl;

    double res1 = ptArray1.Length();
    cout << "Length between Points in ptArray1 is: " << res1 << endl;

    // test copy constructor
    cout << "\nUse copy constructor to construct ptArray2.\n";
    PointArray ptArray2(ptArray1);
    
    double res2 = ptArray2.Length();
    cout << "Length between Points in ptArray2 is: " << res2 << endl;

    // test assignment operator
    cout << "\nUse assignment operator to construct ptArray3.\n";
    PointArray ptArray3 = ptArray1;
    
    double res3 = ptArray3.Length();
    cout << "Length between Points in ptArray3 is: " << res3 << endl;

    // test exception handling
    try
    {
        // use a index that ptArray1 does not have
        cout << "\ntry to access index 100\n";
        ptArray1[100];
    }
    catch(ArrayException& ae)
    {
        cout << ae.GetMessage();
    }

    return 0;
}
