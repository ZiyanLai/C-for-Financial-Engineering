/*
 * fileName:          functionObject.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-06
 * @lastModifiedDate: 2020-06-06
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Implementation of Function Object */

#ifndef FUNCTIONOBJECT_CPP
#define FUNCTIONOBJECT_CPP
#include "functionObject.hpp"
#include <iostream>
using namespace std;

// default constructor
template<typename T>
FunctionObject<T>::FunctionObject(){}

// constructor that takes a value
template<typename T>
FunctionObject<T>::FunctionObject(T standard) : m_standard(standard){}

// copy constructor
template<typename T>
FunctionObject<T>::FunctionObject(const FunctionObject<T>& source) : m_standard(source.m_standard){}

// destructor
template<typename T>
FunctionObject<T>::~FunctionObject(){}

// assignment operator
template<typename T>
FunctionObject<T>& FunctionObject<T>::operator = (const FunctionObject<T>& rhs)
{
    // if self assignment
    if (this == &rhs)
    {
        // return this object
        return *this;
    }
    // if not self assignment
    // assign value from right hand side
    m_standard = rhs.m_standard;
    // return this object
    return *this;
}

// () operator overloade and return a bool type
template<typename T>
bool FunctionObject<T>::operator() (T input) const
{
    // check if the input is smaller than the standard
    return input < m_standard;
}

#endif