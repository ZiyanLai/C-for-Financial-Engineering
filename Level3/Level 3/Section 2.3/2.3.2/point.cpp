//
//  point.cpp
//  2.3.2
//
//  Created by Ziyan Lai on 5/29/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//  Change the Distance to pass by const reference


#include "point.hpp"
#include <iostream>
#include <cmath>
#include <sstream>

// Default Constructor
Point::Point() 
{
    // print out a message
    std::cout << "HELLO POINT\n"; 
} 

// Copy Constructor
Point::Point(const Point& anotherP) : m_x(anotherP.m_x), m_y(anotherP.m_y)  // copy over X and Y coordinates  
{                          
    // print out a message 
    std::cout << "HELLO POINT (Copy Constructor)\n";    
}

// Constructor that takes value
Point::Point(double x, double y) : m_x(x), m_y(y)
{     
    // print out a message
    std::cout << "HELLO POINT (Constructor that takes value)\n";
}

// Destructor
Point::~Point() 
{
    // print out a message
    std::cout << "BYE POINT\n"; 
}          

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

// Function to calculate the distance between the Point and the origin
double Point::DistanceOrigin()
{
    // use the sqrt() and pow() functions to calculate the distance
    return std::sqrt(pow(m_x, 2) + pow(m_y, 2));
}

// Function to calculate the distance between two points
// Now the function is pass in by reference to prevent making copies
// also we add a const to make sure the function does not change the value of input Point
double Point::Distance(const Point& p)
{
    // use the sqrt() and pow() functinos to calculate the distance 
    // if we do p.SetX(3) here, it will generate a compile error because the argument is const
    return std::sqrt(pow(m_x - p.m_x, 2) + pow(m_y-p.m_y, 2));
}

