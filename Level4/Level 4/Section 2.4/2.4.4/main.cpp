/*
 * fileName:          main.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-05-31
 * @lastModifiedDate: 2020-05-31
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

// Test operators

#include "point.hpp"
#include "line.hpp"
#include <iostream>
using namespace std;



int main()
{   
    // ask the user to input the X and Y coordinates of the first point
    double xCor1, yCor1;
    cout << "\nPlease enter an X coordinate and a Y coordinate for point 1: " << endl;
    cin >> xCor1 >> yCor1;
    
    // create point 1
    Point p1(xCor1, yCor1);
    
    // display the attributes of point 1
    cout << "p1 = " << p1.ToString() << endl;
    
    // ask the user to input the X and Y coordinates of the second point
    double xCor2, yCor2;
    cout << "\nPlease enter an X coordinate and a Y coordinate for point 2: " << endl;
    cin >> xCor2 >> yCor2;
    
    // create point 2
    Point p2(xCor2, yCor2);

    // display the attributes of point 2
    cout << "p2 = " << p2.ToString() << endl;
    

    // Create an object of class Line and assign it the value of two Points 
    Line line(p1, p2);


    // Test the Ostream Operators for different class
    cout << "\nNow let's test the Ostream Operators made as a friend: \n\n";

    // Test the Ostream Operator for Point
    cout << "Ostream Operator for Point:\n" << "p1: " << p1 << "\n\n";
    // Test the Ostream Operator for Line
    cout << "Ostream Operator for Line:\n" << "line:\n" << line << "\n";
    

    return 0;
}