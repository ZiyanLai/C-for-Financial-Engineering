//
//  point.cpp
//  2.3.3
//
//  Created by Ziyan Lai on 5/29/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//  Overload function of Setters & Getters and Distance & DistanceOrigin


#include "point.hpp"
#include <iostream>
#include <cmath>
#include <sstream>

// Default Constructor
Point::Point(){}

// Copy Constructor
Point::Point(const Point& anotherP) : m_x(anotherP.m_x), m_y(anotherP.m_y){}  // copy over X and Y coordinates  

// Constructor that takes value
Point::Point(double x, double y) : m_x(x), m_y(y){}

// Destructor
Point::~Point(){}          


// Getter of the X coordinate
double Point::X()
{ 
    return m_x; 
}

// Getter of the Y coordinate
double Point::Y()
{ 
    return m_y; 
}

// Setter of the X coordinate
void Point::X(double newX)
{
     m_x = newX; 
}

// Setter of the X coordinate
void Point::Y(double newY)
{
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

// Function to calculate the distance between the Point and the origin
double Point::Distance()
{
    // use the sqrt() and pow() functions to calculate the distance
    return std::sqrt(pow(m_x, 2) + pow(m_y, 2));
}

// Function to calculate the distance between two points
double Point::Distance(const Point& p)
{
    // use the sqrt() and pow() functions to calculate the distance
    return std::sqrt(pow(m_x - p.m_x, 2) + pow(m_y-p.m_y, 2));
}

