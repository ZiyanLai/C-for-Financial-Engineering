//
//  main.cpp
//  2.3.3
//
//  Created by Ziyan Lai on 5/29/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//  Test Function Overloading


#include "point.hpp"
#include <iostream>

int main()
{
    // initialize X and Y coordinates for Point p1
    double xCor1, yCor1;
    
    // ask for user input
    std::cout << "Please enter an X coordinate and a Y coordinate for point 1: " << std::endl;
    // read user input
    std::cin >> xCor1 >> yCor1;
    
    // use the constructor that takes 2 values to directly construct Point
    Point p1(xCor1, yCor1);
    
    // display with Getter function
    std::cout << "X coordinate is: " << p1.X() << ", Y coordiante is: " << p1.Y() << std::endl;

    // test the overloaded Setter function
    p1.X(25);
    p1.Y(30);
    // display the new p1 with Getter function
    std::cout << "Set p1's X coordinate to 25, Y coordinate to 30.\nNow " << "X coordinate is: " << p1.X() << ", Y coordiante is: " << p1.Y() << std::endl;
    
    // initialize X and Y coordinates for Point p2
    double xCor2, yCor2;
    // ask for user input
    std::cout << "Please enter an X coordinate and a Y coordinate for point 2: " << std::endl;
    // read user input
    std::cin >> xCor2 >> yCor2;
    
    // use the constructor that takes 2 values to directly construct Point      
    Point p2(xCor2, yCor2);

    // display with ToString function
    std::cout << "p2: " << p2.ToString() << std::endl;


    // call the Distance function between Point and origin
    double distance1 = p1.Distance();
    std::cout << "Distance from point 1 to origin is: " << distance1 << std::endl;

    // call the Distance function for 2 points
    double distance2 = p1.Distance(p2);
    // print the distance between p1 and p2
    std::cout << "Distance from point 1 to point 2 is: " << distance2 << std::endl;


    return 0;
}

