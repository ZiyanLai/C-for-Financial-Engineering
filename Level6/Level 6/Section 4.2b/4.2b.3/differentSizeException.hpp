/*
 * fileName:          differentSizeException.hpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-04
 * @lastModifiedDate: 2020-06-04
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* DifferentSizeException class that is derived from ArrayException classand its implementation */

#ifndef DIFFERENTSIZE_EXCEPTION_HPP
#define DIFFERENTSIZE_EXCEPTION_HPP

#include "arrayException.hpp"
#include <iostream>
#include <sstream>
using namespace std;

class DifferentSizeException : public ArrayException
{
private:
    unsigned int lfsSize;   // left hand array size
    unsigned int rhsSize;   // right hand array size

public:
    //  default constructor
    DifferentSizeException() : ArrayException() {}     

    // constructor that takes two sizes
    DifferentSizeException(unsigned int size1, unsigned int size2) : lfsSize(size1), rhsSize(size2), ArrayException() {} 

    // destructor
    virtual ~DifferentSizeException(){}

    // override base class function
    string GetMessage() const
    {
        stringstream ss;
        ss << "Left hand side size " << lfsSize << " and right hand size " << rhsSize << " are not equal";
        return ss.str();
    }
};

#endif