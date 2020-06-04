/*
 * fileName:          main.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-03
 * @lastModifiedDate: 2020-06-03
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Test the Array Exception hierarchy */
#include <iostream>
#include "array.hpp"
#include "point.hpp"
#include "shape.hpp"
#include "arrayException.hpp"
using namespace std;

int main()
{
    Point p1(1.0,1.0);
    Array array(5);
    // array[-1] = p1;  If we don't use try and catch, the program will terminate because of the exception 
    //                  So we need to add try and catch to make the program to actual handle the error

    try     // try to access the index that does not exist or negative
    {
        array[-1] = p1;
    }
    catch(ArrayException& ae)  // catch the ArrayException base class
    {
        // use polymorphism to call OutOfBoundException GetMessage()
        cout << ae.GetMessage();
    }

    try     // try to access the index that does not exist or negative
    {
        array.SetElement(100, p1);
    }
    catch(ArrayException& ae)   // catch the ArrayException base class
    {
        cout << ae.GetMessage();
    }

    try     // try to access the index that does not exist or negative
    {
        array.GetElement(-20);
    }
    catch(ArrayException& ae)   // catch the ArrayException base class
    {
        cout << ae.GetMessage();
    }
    

    return 0;
}