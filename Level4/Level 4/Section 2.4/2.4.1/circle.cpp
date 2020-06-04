/*
 * fileName:          circle.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-05-31
 * @lastModifiedDate: 2020-05-31
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Add assignment operator in addition to the previous Circle class */

#include "circle.hpp"
using namespace std;

// Default Constructor 
Circle::Circle(){}

// Constructor that takes value
Circle::Circle(const Point& cent, const double& rad) : center(cent), m_radius(rad){}

// Copy Constructor
Circle::Circle(const Circle& anotherC) : center(anotherC.center), m_radius(anotherC.m_radius){}

// Destructor
Circle::~Circle(){}

// Assignment Operator
Circle& Circle::operator = (const Circle& anotherC)
{
    // check if self assignment
    if (this == &anotherC)
    {
        // if self assignment, return the circle itself
        return *this;
    }
    // if not self assignment
    center = anotherC.center;       // assign the center 
    m_radius = anotherC.m_radius;   // assign the radius
    return *this;                   // return this circle
}

// Getter of the center point
const Point& Circle::CenterPoint() const { return center; }

// Getter of the radius
double Circle::Radius() const { return m_radius; }

//  Setter of the center
void Circle::CenterPoint(const Point& anotherP){ center = anotherP; }

//  Setter of the radius
void Circle::Radius(double anotherR){ m_radius = anotherR; }

// Calculate the diameter of circle
double Circle::Diameter() const {return 2 * m_radius; }

// Calculate the circumference 
double Circle::Circumference() const { return 2 * m_radius * M_PI; }

//  Calculate the area of circle
double Circle::Area() const  { return M_PI * pow(m_radius, 2); }

// Report the circle
string Circle::ToString() const {
    stringstream ss;
    ss << "Center: " << center.ToString() << " Radius: " << m_radius;
    return ss.str();
}
