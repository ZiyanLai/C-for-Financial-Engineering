/*
 * fileName:          pointArray.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-05
 * @lastModifiedDate: 2020-06-05
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* PointArray class that is concrete inherit from Array class*/


#include "pointArray.hpp"
#include "point.hpp"
#include <iostream>
using namespace std;

// default constructor
PointArray::PointArray() : Array() {}

// constructor that takes one value
PointArray::PointArray(unsigned int size) : Array(size){}

// copy constructor
PointArray::PointArray(const PointArray& anotherPA) : Array(anotherPA){}  // copy the base part

// destructor
PointArray::~PointArray(){}

// assignment operator
PointArray& PointArray::operator = (const PointArray& rhs)
{
    // if self assignment
    if (this == &rhs)
    {
        // return this PointArray
        return *this;
    }
    // assign base part
    Array<Point>::operator=(rhs);
    return *this;
}

// Length() function that returns the total length between points
double PointArray::Length() const 
{
    double res;
    for (int i = 0; i != this->Size() - 1; ++i)
    {
        // calculate the distance between current and next Point
        // then add to res
        res += (*this)[i].Distance( (*this)[i+1] ) ;
    }

    return res;
}
