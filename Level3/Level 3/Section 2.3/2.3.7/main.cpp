//
//  main.cpp
//  2.3.7
//
//  Created by Ziyan Lai on 5/29/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//  Test Normal Inline and Default Inline


#include "point.hpp"
using namespace std;

int main()
{
    // define X and Y coordiantes for point 1
    double xCor1, yCor1;
    // ask for user input
    cout << "Please enter an X coordinate and a Y coordinate for point: " << endl;
    // read user input
    cin >> xCor1 >> yCor1;
    
    // initialize Point p1 with the user inputs
    Point p1(xCor1, yCor1);
    
    // display p1
    cout << "point: " << p1.ToString() << endl;
    cout << "X coordinate is: " << p1.X() << ", Y coordiante is: " << p1.Y() << endl;
    

    // test the default inline Setters
    p1.X(100);
    p1.Y(-100);
    // display the changes after Setter
    cout << "\nSetting X coordinate to 100 and Y coordinate to -100; now, point: " << p1.ToString() << endl;

    // test normal inline Getters;
    cout << "X coordinate is: " << p1.X() << ", Y coordiante is: " << p1.Y() << endl;

    return 0;
}
