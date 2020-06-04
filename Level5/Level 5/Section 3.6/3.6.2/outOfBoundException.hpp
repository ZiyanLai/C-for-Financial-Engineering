/*
 * fileName:          outOfBoundException.hpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-03
 * @lastModifiedDate: 2020-06-03
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* OutOfBoundsException class that is derived from ArrayException classand its implementation */

#ifndef OUTOFBOUND_EXCEPTION_HPP
#define OUTOFBOUND_EXCEPTION_HPP

#include "arrayException.hpp"
#include <iostream>
#include <sstream>
using namespace std;

class OutOfBoundException : public ArrayException
{
private:
    int m_index;

public:
    //  default constructor
    OutOfBoundException(){}

    // constructor that takes an index
    OutOfBoundException(int errInd)
    {
        m_index = errInd;
    }

    // destructor
    virtual ~OutOfBoundException(){}

    // override base class function
    string GetMessage() const
    {
        stringstream ss;
        ss << "Index is not Valid! \n";
        return ss.str();
    }
};





#endif