/*
 * fileName:          point.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-05-31
 * @lastModifiedDate: 2020-05-31
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Add Ostream Opeartors in addition to the previous Point class */

#include "point.hpp"

// Default Constructor
Point::Point() {}         

// Copy Constructor
Point::Point(const Point& anotherP)
{                    
    m_x = anotherP.m_x;
    m_y = anotherP.m_y;
}

// Constructor that takes 2 value
Point::Point(double x, double y) : m_x(x), m_y(y){}     

// Constructor that takes 1 value
Point::Point(double value) : m_x(value), m_y(value){}

// Destructor
Point::~Point() {}                                      

// Getter of X coordinate
double Point::X() const { return m_x; }

// Getter of Y coordinate
double Point::Y() const { return m_y; }

// Setter of X coordinate
void Point::X(double newX){ m_x = newX; }

// Setter of Y coordinate
void Point::Y(double newY){ m_y = newY; }

// Fucntin to display the X and Y coordinate 
string Point::ToString() const 
{
    stringstream ss;
    ss << "Point(" << m_x << "," << m_y << ")";
    return ss.str();
}

// Function to calculate the distance between a point to origin
double Point::Distance() const 
{
    double res = sqrt(pow(m_x, 2) + pow(m_y, 2));
    return res;
}

// Function to calculate the distance between two points
double Point::Distance(const Point& p) const 
{
    double res = sqrt(pow(m_x - p.m_x, 2) + pow(m_y-p.m_y, 2));
    return res;
}

// Implementations of member opeartors overloading

// Negate the coordinate 
Point Point::operator - () const            
{
    return Point(-m_x, -m_y);
}

// Scale the coordinate
Point Point::operator * (double factor) const   
{
    return Point(m_x * factor, m_y * factor);
}

// Add the coordinate
Point Point::operator + (const Point& p) const                  
{
    return Point(m_x + p.m_x, m_y + p.m_y);
}

// Equally compare operator
bool Point::operator == (const Point& p) const    
{
    return (m_x == p.m_x && m_y == p.m_y);
}

// Assignment operator
Point& Point::operator = (const Point& source)    
{
    if (this == &source)    // check self assignment
    {
        return *this;       // if self assignment, return itself
    }

    // if not self assignment
    this->m_x = source.m_x; // assign X coordinate from source's X coordinate
    this->m_y = source.m_y; // assign Y coordinate from source's Y coordinate
    return *this;           // return this Point
}

// Scale and assign the coordinate
Point& Point::operator *= (double factor)
{
    m_x *= factor;  // scale and assign X coordinate
    m_y *= factor;  // scale and assign Y coordinate
    return *this;   // return this Point
}

// Ostream operator as a friend of Point class
ostream& operator << (ostream&os, const Point& p)
{
 os << "X coordinate: " << p.m_x << ", Y coordinate: " << p.m_y;
 return os;
}