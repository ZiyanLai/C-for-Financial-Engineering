/*
 * fileName:          arrayException.hpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-03
 * @lastModifiedDate: 2020-06-03
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Array Exception and its implementation */

#ifndef ARRAY_EXCEPTION_HPP
#define ARRAY_EXCEPTION_HPP
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class ArrayException
{
public:
    // default constructor
    ArrayException(){}

    // virtual destructor
    virtual ~ArrayException(){}

    // pure virtual place holder for GetMessage
    virtual string GetMessage() const = 0;

};


#endif



