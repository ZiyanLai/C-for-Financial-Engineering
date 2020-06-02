//
//  main.cpp
//  2.2.2
//
//  Created by Ziyan Lai on 5/29/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//  Test 2 Distance functions


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
    
    // initialize Point p1
    Point p1;
    // set X and Y coordinates for p1
    p1.SetX(xCor1);
    p1.SetY(yCor1);
    // display with ToString funtcion
    std::cout << "p1: " << p1.ToString() << std::endl;
    // display with Getter functions
    std::cout << "X coordinate is: " << p1.GetX() << ", Y coordiante is: " << p1.GetY() << std::endl;
    // use the function to calculate the distance from origin and print
    std::cout << "Distance from origin to point 1 is: " << p1.DistanceOrigin() << "\n" <<std::endl;
    
    // initialize X and Y coordinates for Point p2
    double xCor2, yCor2;
    // ask for user input
    std::cout << "Please enter an X coordinate and a Y coordinate for point 2: " << std::endl;
    // read user input
    std::cin >> xCor2 >> yCor2;
    
    // initialize Point p2
    Point p2;
    // set X and Y coordiantes for p2
    p2.SetX(xCor2);
    p2.SetY(yCor2);
    // display with ToString funtcion
    std::cout << "p2: " << p2.ToString() << std::endl;
    // calculate the distance between p1 and p2 using the Distance function
    double distance = p1.Distance(p2);
    // print out the result
    std::cout << "Distance from point 1 to point 2 is: " << distance << std::endl;


    return 0;
}
