/*
 * fileName:          main.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-03
 * @lastModifiedDate: 2020-06-03
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Test the template */

#include <iostream>
#include "array.cpp"
#include "point.hpp"
#include "shape.hpp"
#include "arrayException.hpp"
using namespace std;

int main()
{
    // create Point instance
    Point p1(1.0,1.0);

    // use template initialize Array<Point> class
    Array<Point> array1(5);
    cout << "Size of array1 is " << array1.Size() << endl;

    // test the SetElement() function
    array1.SetElement(0, Point(1.0, 1.0));
    // test the GetElement() function
    cout << "Retriving using the GetElement(), the first element in array1 is: " << array1.GetElement(0) << endl;
    // test the [] operator
    cout << "Retriving using the [] operator, the first element in array1 is: " << array1[0] << endl;

    // create a const Array instance to test the const [] operator
    cout << "\ncreate const arrat2 by copying array1;\n";
    const Array<Point> array2(array1);
    // array2[2] = Point(10,10);    this is invalid because array2 is const

    // test the const [] operator
    cout << "Retriving using the const [] operator, the first element in array2 is: " << array2[0] << endl;

    // test the Size() function
    cout << "Size of array2 is " << array2.Size() << endl;

    try     // try to access the index that does not exist or negative
    {
        cout << "try to access array1 with index -20\n";
        array1.GetElement(-20);
    }
    catch(ArrayException& ae)   // catch the ArrayException base class
    {
        cout << ae.GetMessage();
    }
    
    return 0;
}