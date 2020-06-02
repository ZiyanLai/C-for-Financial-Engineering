/*
 * fileName:          main.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-05-31
 * @lastModifiedDate: 2020-05-31
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Create array to store Point pointers */

#include "point.hpp"
#include <iostream>
using namespace std;

int main()
{   
    
    // Create an array of size 3 on heap to store Point pointers
    Point** pointArrayPtr = new Point* [3];
    
    // Use constructor that takes values instead of default constructor
    // Initialize 3 Point objects with other constructor using new on heap,
    // and then store into the Point pointer array
    pointArrayPtr[0] = new Point(1,2);
    pointArrayPtr[1] = new Point(3,4);
    pointArrayPtr[2] = new Point(5,6);

    // Iterate through the Point pointer array 
    for (int i = 0; i < 3; ++i)
    {
        // dereference the Point pointer and then use the Ostream Operator
        // to print out the X and Y coordinates for each Point
        cout << *pointArrayPtr[i] << endl;
    }

    // Iterate through the Point pointer array
    for (int i = 0; i < 3; ++i)
    {
        // delete each Point pointer that was created on heap from the array
        delete pointArrayPtr[i];
        // print out a delete message
        cout << "deleted Point" << i << endl;
    }

    // delete the array on heap that was used to store the Point pointers
    delete[] pointArrayPtr;

    return 0;
}