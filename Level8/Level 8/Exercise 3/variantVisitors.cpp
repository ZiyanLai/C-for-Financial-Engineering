/*
 * fileName:          variantVisitors.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-07
 * @lastModifiedDate: 2020-06-07
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/
/* Implementation of Variant Visitor, which inherit from boost::static_visitor<T> */

#include "variantVisitors.hpp"
#include <iostream>
using namespace std;

// default constructor
VariantVisitors::VariantVisitors() : boost::static_visitor<void>(), m_dx(0), m_dy(0) {}
    
// constructor that takes two values
VariantVisitors::VariantVisitors(double xCor, double yCor) :  boost::static_visitor<void>(), m_dx(xCor), m_dy(yCor) {}

// copy constructor 
VariantVisitors::VariantVisitors(const VariantVisitors& source) :  boost::static_visitor<void>(source), m_dx(source.m_dx), m_dy(source.m_dy) {}
                                                                   // copy the base portion and then copy derived class's own data member
// destructor   
VariantVisitors::~VariantVisitors(){}

// assignment operator
VariantVisitors& VariantVisitors::operator = (const VariantVisitors& rhs)
{
    // check if self assignment
    if (this == &rhs)
    {
        // if self assignment, return this object
        return *this;
    }

    // otherwise
    // assign base portion of data
    boost::static_visitor<void>::operator = (rhs);
    // assign data members with new value from right hand side
    m_dx = rhs.m_dx;
    m_dy = rhs.m_dy;

    // return this object
    return *this;
}

// overload operator to visit a Point
void VariantVisitors::operator() (Point& p) const
{
    // use Getter and Setter from Point class to add value
    p.X(p.X() + m_dx);
    p.Y(p.Y() + m_dy);
}

// overload operator to visit a Line
void VariantVisitors::operator() (Line& l) const
{
    // use Getter from Line class to get original Point value
    Point startP = l.startPoint();
    Point endP = l.endPoint();

    // use Getter and Setter from Point class to add value to both start Point
    startP.X(startP.X() + m_dx);
    startP.Y(startP.Y() + m_dy);
    // use Getter and Setter from Point class to add value to both end Point
    endP.X(endP.X() + m_dx);
    endP.Y(endP.Y() + m_dy);

    // use Setter from Line class to assign new Point value
    l.startPoint(startP);
    l.endPoint(endP);
}

// overload opeartor to visit a Circle
void VariantVisitors::operator() (Circle& c) const
{
    // use Getter from Circle class to get center point
    Point center = c.CenterPoint();

    // use Setter from Point class to add value
    center.X(center.X() + m_dx);
    center.Y(center.Y() + m_dy);

    // use Setter from Circle class to assign new Point value
    c.CenterPoint(center);
}