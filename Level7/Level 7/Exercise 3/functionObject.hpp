/*
 * fileName:          functionObject.hpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-06
 * @lastModifiedDate: 2020-06-06
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Header file of the Function Object */
#ifndef FUNCTIONOBJECT_HPP
#define FUNCTIONOBJECT_HPP
#include <iostream>
using namespace std;

// declare to use a template
template<typename T>
class FunctionObject
{
private:
    T m_standard;       // data member of a standard value
public:
    // default constructor
    FunctionObject();

    // constructor that takes a value
    FunctionObject(T standard);

    // destructor
    ~FunctionObject();

    // copy constructor
    FunctionObject(const FunctionObject<T>& source);

    // assignment operator
    FunctionObject<T>& operator = (const FunctionObject<T>& rhs);

    // overload () operator
    bool operator() (T input) const;   
};

#ifndef FUNCTIONOBJECT_CPP
#include "functionObject.cpp"
#endif
#endif