/*
 * fileName:          pointArray.hpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-05
 * @lastModifiedDate: 2020-06-05
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* PointArray class that is concrete inherit from Array class*/

#ifndef POINTARRAY_HPP
#define POINTARRAY_HPP

#include "array.hpp"
#include "point.hpp"
#include <iostream>
using namespace std;

// Concrete inherit from Array<Point>
class PointArray : public Array<Point>
{
public:
    // default constructor
    PointArray();

    // constructor that takes a size value
    PointArray(unsigned int size);

    // copy constructor
    PointArray(const PointArray& anotherPA);

    // destructor
    virtual ~PointArray();

    // assignment operator
    PointArray& operator = (const PointArray& rhs);

    // Length() function that returns the total length between points
    double Length() const;
};


#endif
