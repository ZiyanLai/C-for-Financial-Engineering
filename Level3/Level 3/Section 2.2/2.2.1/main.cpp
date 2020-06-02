//
//  main.cpp
//  2.2.1
//
//  Created by Ziyan Lai on 5/29/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//  main function to test the Point class


#include "point.hpp"
#include <iostream>


int main()
{   
    // define X and Y coordinate
    double xCor, yCor;
    // ask for user input
    std::cout << "Please enter an X coordinate and a Y coordinate: " << std::endl;
    // read the input
    std::cin >> xCor >> yCor;
    // initialize a Point object
    Point p;
    // set the X coordiante
    p.SetX(xCor);
    // set the Y coordinate
    p.SetY(yCor);
    // use the ToString functino to display the Point
    std::cout << "point: " << p.ToString() << std::endl;
    // use the Getter functions to display the Point
    std::cout << "X coordinate is: " << p.GetX() << ", Y coordiante is: " << p.GetY() << std::endl;

    return 0;
}
