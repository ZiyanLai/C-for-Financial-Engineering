/*
 * fileName:          circle.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-03
 * @lastModifiedDate: 2020-06-03
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Also call Base ToString in Circle's ToString */

#include "circle.hpp"
using namespace std;

// Default Constructor 
// Assign the center at origin and radius to be 0.
// here we use the Point constructor that takes 1 value
Circle::Circle()      // here the Default Constructor of Shape class will be called
                      // so we don't need to explicitly write it 
{
    center = Point(0.0, 0.0);
    m_radius = 0.0;
}

// Constructor that takes value
Circle::Circle(const Point& cent, const double& rad)    // here the Default Constructor of Shape class will be called
                                                        // so we don't need to explicitly write it 
{
    center = cent;
    m_radius = rad;
}

// Copy Constructor
Circle::Circle(const Circle& anotherC) : Shape(anotherC)    // copy the base portion
{
    center = anotherC.center;
    m_radius = anotherC.m_radius;
}

// Destructor
Circle::~Circle(){cout << "Bye Circle\n";}

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

    // assign the portion in base class
    Shape::operator = (anotherC);

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
    string s = Shape::ToString();
    ss << " "<<s;
    return ss.str();
}

// Ostream operator for Circle class
ostream& operator << (ostream&os, const Circle& c)
{
 os << c.ToString() << endl;
 return os;
}