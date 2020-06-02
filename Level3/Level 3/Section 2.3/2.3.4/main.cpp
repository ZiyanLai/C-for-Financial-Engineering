//
//  main.cpp
//  2.3.4
//
//  Created by Ziyan Lai on 5/29/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//


#include "point.hpp"
#include <iostream>
using namespace std;

int main()
{
    // initialize X and Y coordinates for Point p1
    double xCor1, yCor1;
    
    // ask for user input
    cout << "Please enter an X coordinate and a Y coordinate for point 1: " << endl;
    // read user input
    cin >> xCor1 >> yCor1;
    
    // use the constructor that takes 2 values to directly construct Point
    Point p1(xCor1, yCor1);
    
    // display with ToString function
    cout << "p1: " << p1.ToString() << endl;

    // display with Getter function
    cout << "p1: X coordinate is: " << p1.X() << ", Y coordiante is: " << p1.Y() << endl;

    // initialize X and Y coordinates for Point p2
    double xCor2, yCor2;
    // ask for user input
    cout << "Please enter an X coordinate and a Y coordinate for point 2: " << endl;
    // read user input
    cin >> xCor2 >> yCor2;
    
    // use the constructor that takes 2 values to directly construct Point      
    Point p2(xCor2, yCor2);

    // display with ToString function
    cout << "p2: " << p2.ToString() << endl;


    // call the Distance function between Point and origin
    double distance1 = p1.Distance();
    cout << "Distance from point 1 to origin is: " << distance1 << endl;

    // call the Distance function for 2 points
    double distance2 = p1.Distance(p2);
    // print the distance between p1 and p2
    cout << "Distance from point 1 to point 2 is: " << distance2 << endl;
    
    // Create a const Point and initialize it
    const Point cp(1.5, 3.9);
    // Only if we make the Getter function const, this can work
    cout << cp.X() << endl;
    
    return 0;
}

