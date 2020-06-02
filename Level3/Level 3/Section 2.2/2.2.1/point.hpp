//
//  point.hpp
//  2.2.1
//
//  Created by Ziyan Lai on 5/29/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//  Header file of Point class

#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>


class Point
{
private:
    double m_x;     // X coordinate
    double m_y;     // Y coordinate

public:
    // Default Constructor
    Point();
    // Destructor
    ~Point();
    // Getter of X coordinate
    double GetX();
    // Getter of Y coordinate
    double GetY();
    // Setter of X coordinate
    void SetX(double newX);
    // Setter of Y coordinate
    void SetY(double newY);
    // Fucntion to display the X and Y coordinate and return a string
    std::string ToString();

};

#endif
