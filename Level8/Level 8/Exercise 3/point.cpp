/*
 * fileName:          point.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-03
 * @lastModifiedDate: 2020-06-03
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* No changes from the previous Point class */


#include "point.hpp"
#include <iostream>
using namespace std;

// Default Constructor
Point::Point() :  Shape(), m_x(0.0), m_y(0.0) {} 
              // call Shape default constructor and then set the X and Y coordinates to 0 by default

// Copy Constructor
Point::Point(const Point& anotherP) :  Shape(anotherP), m_x(anotherP.m_x), m_y(anotherP.m_y){}  
                                    // copy the base portion and then copy Point's own member data
                        
// Constructor that takes 2 value
Point::Point(double x, double y) : Shape(), m_x(x), m_y(y) {}
                                // call Shape default constructor and then set the X and Y coordinates

// Constructor that takes 1 value
Point::Point(double value) : Shape(), m_x(value), m_y(value) {}
                          // call Shape default constructor and then set the X and Y coordinates

// Destructor
Point::~Point(){}                                      

// Getter of X coordinate
double Point::X() const { return m_x; }

// Getter of Y coordinate
double Point::Y() const { return m_y; }

// Setter of X coordinate
void Point::X(double newX){ m_x = newX; }

// Setter of Y coordinate
void Point::Y(double newY){ m_y = newY; }

// Fucntion to display the X and Y coordinate 
string Point::ToString() const 
{
    stringstream ss;
    ss << "Point(" << m_x << "," << m_y << ")";
    string s = Shape::ToString();
    ss << " "<< s;
    return ss.str();
}

// Function to calculate the distance between a point to origin
double Point::Distance() const { return sqrt(pow(m_x, 2) + pow(m_y, 2)); }

// Function to calculate the distance between two points
double Point::Distance(const Point& p) const { return sqrt(pow(m_x - p.m_x, 2) + pow(m_y-p.m_y, 2)); }


// Implementations of member opeartors overloading

// Negate the coordinate 
Point Point::operator - () const { return Point(-m_x, -m_y); }

// Scale the coordinate
Point Point::operator * (double factor) const { return Point(m_x * factor, m_y * factor); }

// Add the coordinate
Point Point::operator + (const Point& p) const { return Point(m_x + p.m_x, m_y + p.m_y); }

// Equally compare operator
bool Point::operator == (const Point& p) const    
{ return (m_x == p.m_x && m_y == p.m_y); }

// Assignment operator
Point& Point::operator = (const Point& source)    
{
    if (this == &source)    // check self assignment
    {
        return *this;       // if self assignment, return itself
    }

    // if not self assignment
    m_x = source.m_x; // assign X coordinate from source's X coordinate
    m_y = source.m_y; // assign Y coordinate from source's Y coordinate
    
    // assign the portion in base class 
    Shape::operator = (source);
    
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

void Point::Draw() const
{
    cout << "Drawing a Point\n";
}