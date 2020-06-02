/*
 * fileName:          main.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-05-31
 * @lastModifiedDate: 2020-05-31
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Experiment with new to create objects on heap */

#include "point.hpp"
#include <iostream>
using namespace std;

int main()
{   
    // Create objects on stack using new

    // create with default constructor
    Point* pointPtr1 = new Point;
    // create with constructor that takes two values
    Point* pointPtr2 = new Point(3, 5);
    // create with copy constructor
    Point* pointPtr3 = new Point(*pointPtr2);

    // initialize a variable to store the distance between point 1 and point 2
    // and assign it to a value calculated by the Distance function of Point class
    double distanceBetweenP1andP2 = pointPtr1->Distance(*pointPtr2);

    // print the X and Y coordiantes of all 3 points using their overloaded Ostream Operators
    cout << "Point 1: " << *pointPtr1 << "\nPoint 2: " << *pointPtr2 << "\nPoint 3: " << *pointPtr3 << endl;
    
    // print the calculated distance between point 1 and point 2
    cout << "Distance between Point 1 and Point 2 is: " << distanceBetweenP1andP2 << endl;

    // delete all pointers created with new
    delete pointPtr1;
    delete pointPtr2;
    delete pointPtr3;

    // initialize a non-negative integer varaible for the array size
    unsigned int arraySize;
    // ask the user to input a value
    cout << "Pleae input an non-negative integer as the array size: " << endl;
    // read the user's input 
    cin >> arraySize;


    // create Point array using new on heap

    // Point pointArray[arraySize]; Compile Error
    // Since creating on stack doesn't work, we use new to create on heap
    Point* pointArray = new Point[arraySize]; // Cannot use other constructors other than default constructor when initializing an Point array
    
    // print out the first Point in the array using the Ostream Operator
    cout << "First Point in the array: " << *pointArray << endl;
    // delete the array pointer created with new
    delete[] pointArray;

    return 0;
}