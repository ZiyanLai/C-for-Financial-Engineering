//
//  point.cpp
//  2.2.1
//
//  Created by Ziyan Lai on 5/29/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//  Function implementation of Point class


#include "point.hpp"
#include <sstream>
#include <iostream>

// Default Constructor
Point::Point(){}

// Destructor
Point::~Point(){}

// Getter of the X coordinate
double Point::GetX()
{ 
    return m_x; 
}

// Getter of the Y coordinate
double Point::GetY()
{ 
    return m_y; 
}

// Setter of the X coordinate
void Point::SetX(double newX)
{ 
    // set the new X coordinate
    m_x = newX; 
}

// Setter of the Y coordinate
void Point::SetY(double newY)
{ 
    // set the new Y coordinate
    m_y = newY; 
}

// Fucntion to display the X and Y coordinate and return a string
std::string Point::ToString() 
{
    // create a stringstream handle
    std::stringstream ss;
    // push the string into the buffer
    ss << "Point(" << m_x << "," << m_y << ")";
    // return the retrived string
    return ss.str();
}

