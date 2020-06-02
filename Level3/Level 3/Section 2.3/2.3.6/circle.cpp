//
//  circle.cpp
//  2.3.6
//
//  Created by Ziyan Lai on 5/30/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//  Implementation of Circle class

#include "circle.hpp"
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <sstream>

// Default Constructor 
Circle::Circle(){}

// Constructor that takes value
Circle::Circle(const Point& cent, double rad) : center(cent), m_radius(rad){}

// Copy Constructor
Circle::Circle(const Circle& anotherC) : center(anotherC.center), m_radius(anotherC.m_radius){}

// Destructor
Circle::~Circle(){}

// Getter of the center point
Point Circle::CentrePoint() const 
{ 
    return center; 
}

// Getter of the radius
double Circle::Radius() const 
{ 
    return m_radius; 
}

//  Setter of the center
void Circle::CentrePoint(const Point& anotherP)
{ 
    center = anotherP; 
}

//  Setter of the radius
void Circle::Radius(double anotherR)
{ 
    m_radius = anotherR; 
}

// Calculate the diameter of circle
double Circle::Diameter() const 
{
    return 2 * m_radius;
}

// Calculate the circumference 
double Circle::Circumference() const 
{ 
    return 2 * m_radius * M_PI; 
}

//  Calculate the area of circle
double Circle::Area() const  
{ 
    return M_PI * pow(m_radius, 2); 
}

// Report the circle
string Circle::ToString() const 
{
    stringstream ss;
    ss << "Center: " << center.ToString() << " Radius: " << m_radius;
    return ss.str();
}
