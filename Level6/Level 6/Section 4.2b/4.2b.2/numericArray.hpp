/*
 * fileName:          numericArray.hpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-04
 * @lastModifiedDate: 2020-06-04
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* header file of Numeric Array that is generic inherit from Array class*/

#ifndef NUMERIC_ARRAY_HPP
#define NUMERIC_ARRAY_HPP
#include "array.hpp"
#include <iostream>
using namespace std;

// declare a template
template<typename T>
// generic inherit from Array<T>
class NumericArray : public Array<T>
{
public:
    // default constructor
    NumericArray();
    
    // constructor that takes a size value 
    NumericArray(unsigned int size);

    // copy constructor
    NumericArray(const NumericArray<T>& source);

    // destructor
    virtual ~NumericArray();

    // assignment operator
    NumericArray<T>& operator = (const NumericArray<T>& rhs);

    // + operator that add element by element in two numeric arrays
    NumericArray<T> operator + (const NumericArray<T>& rhs) const;

    // * operator that scales each elements in the numeric array
    NumericArray<T> operator * (T fac) const;

    // dot product function that calculates the dot product between two numeric arrays
    T dotProduct(const NumericArray<T>& rhs) const;
};



#ifndef NUMERIC_ARRAY_CPP
#include "numericArray.cpp"
#endif

#endif