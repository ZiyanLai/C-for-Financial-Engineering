//
//  main.cpp
//  2.3.2
//
//  Created by Ziyan Lai on 5/29/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//  Change the Distance to pass by const reference


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
    
    // display with ToString function
    std::cout << "p1: " << p1.ToString() << std::endl;
    // display with Getter function
    std::cout << "X coordinate is: " << p1.GetX() << ", Y coordiante is: " << p1.GetY() << std::endl;
    
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
    // call the Distance function
    double distance = p1.Distance(p2);
    // print the distance between p1 and p2
    std::cout << "Distance from point 1 to point 2 is: " << distance << std::endl;

    return 0;
}

// Now we have 2 constructor that takes value calls and 2 destructor calls, and no calls from the copy constructor.
// Also, we cannot modify the value from the argument in Distance, since the argument is const.
