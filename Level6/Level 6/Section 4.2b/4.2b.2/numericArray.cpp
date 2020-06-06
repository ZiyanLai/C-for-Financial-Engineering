/*
 * fileName:          numericArray.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-04
 * @lastModifiedDate: 2020-06-04
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Implementation of NumericArray class that is generic inherit from Array class*/

#ifndef NUMERIC_ARRAY_CPP
#define NUMERIC_ARRAY_CPP

#include "numericArray.hpp"
#include "array.hpp"
#include "differentSizeException.hpp"
#include <iostream>
using namespace std;

// default constructor
template<typename T>
NumericArray<T>::NumericArray() : Array<T>() {}

// constructor that takes one value
template<typename T>
NumericArray<T>::NumericArray(unsigned int size) : Array<T>(size) {}

// copy constructor
template<typename T>
NumericArray<T>::NumericArray(const NumericArray<T>& source) : Array<T>(source) {}

// destructor
template<typename T>
NumericArray<T>::~NumericArray(){}

// assignment operator
template<typename T>
NumericArray<T>& NumericArray<T>::operator = (const NumericArray<T>& rhs)
{
    // if self assignment then return itself
    if (this == &rhs) {return *this; }

    // assign the base portion
    Array<T>::operator = (rhs);

    return *this;
}

// + operator
template<typename T>
NumericArray<T> NumericArray<T>::operator + (const NumericArray<T>& rhs) const
{
    // check if this array has the same size as rhs array
    if (this->Size() != rhs.Size())
    {
        // if not, throw an exception object
        throw DifferentSizeException(this->Size(), rhs.Size());
    }

    // create a sum array to store the summation 
    // using the copy constructor of NumericArray
    NumericArray<T> sumArray(*this);

    for (int i = 0; i != rhs.Size(); ++i)
    {
        // add right hand to the copy of left hand side
        sumArray[i] += rhs[i];
    }
    // return this array
    return sumArray;
}   

// * operator
template<typename T>
NumericArray<T> NumericArray<T>::operator * (T factor) const
{
    // create a multiplicated array to store the multiplication result 
    // using the copy constructor of NumericArray
    NumericArray<T> mulArray(*this);

    for (int i = 0; i != this->Size(); ++i)
    {
        // scale the number
        mulArray[i] *= factor;
    }

    return mulArray;
}

// dot product function that calculates the dot product between two numeric arrays
template<typename T>
T NumericArray<T>::dotProduct(const NumericArray<T>& rhs) const
{
    // initialize a type T variable as result
    T res(0);
    // check if this array has the same size as rhs array
    if (this->Size() != rhs.Size())
    {
        // if not, throw an exception object
        throw DifferentSizeException(this->Size(), rhs.Size());
    }
    
    // in each index:
    for (int i = 0; i != this->Size(); ++i)
    {
        // calculate the dot product element wise and then add to res
        res += (*this)[i] * rhs[i];
    }
    return res;
}

#endif