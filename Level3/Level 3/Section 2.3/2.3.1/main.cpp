//
//  main.cpp
//  2.3.1
//
//  Created by Ziyan Lai on 5/29/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//  Examine the Distance function that pass by value


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
    
    // Point p1;
    // p1.SetX(xCor1);
    // p1.SetY(yCor1);
    // use the constructor that takes 2 values to directly construct Point
    Point p1(xCor1, yCor1);
    // display with ToString function
    std::cout << "p1: " << p1.ToString() << std::endl;
    // display with Getter function
    std::cout << "X coordinate is: " << p1.GetX() << ", Y coordiante is: " << p1.GetY() << std::endl;
//    std::cout << "Distance from origin to point 1 is: " << p1.DistanceOrigin() << "\n" <<std::endl;
    

    // initialize X and Y coordinates for Point p2
    double xCor2, yCor2;
    // ask for user input
    std::cout << "Please enter an X coordinate and a Y coordinate for point 2: " << std::endl;
    // read user input
    std::cin >> xCor2 >> yCor2;
    
    // Point p2;
    // p2.SetX(xCor2);
    // p2.SetY(yCor2);
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

// Before adding the copy constructor and the constructor that takes value:
// There were 2 constructor calls and 3 descturcor calls. This means when calling the 'Distance' function, 
// the value of point is copied by value (since the Distance function is pass in by value), 
// and we got a copy constructor for free when we do not define one.

// Now:
// The copy constructor is called once.
// The constructor that takes value is called 2 times.
// The destructor is called 3 times.
// The total number of constructor calls and destructor calls are the same.
