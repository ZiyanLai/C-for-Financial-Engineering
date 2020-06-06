/*
 * fileName:          stackException.hpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-05
 * @lastModifiedDate: 2020-06-05
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Stack Exception classes*/

#ifndef STACK_EXCEPTION_HPP
#define STACK_EXCEPTION_HPP

#include <sstream>
#include <iostream>
using namespace std;

// base class
class StackException
{
public:
    // default constructor
    StackException(){}
    // destructor
    virtual ~StackException(){}
    // pure virtual function that get a message
    virtual string GetMessage() const = 0;
};

// exception class for Full Stack situation
class StackFullException : public StackException
{
public:
    // default constructor
    StackFullException() : StackException() {}
    // destructor
    virtual ~StackFullException(){}
    // function to return a message
    string GetMessage() const 
    {
        stringstream ss;
        ss << "Index is not valid because array is full! \n";
        return ss.str();
    }
};

// exception class for Empty Stack situation
class StackEmptyException : public StackException
{
public:
    // default constructor
    StackEmptyException() : StackException() {}
    // destructor
    virtual ~StackEmptyException(){}
    // functino to return a message
    string GetMessage() const 
    {
        stringstream ss;
        ss << "Index is not valid because array is empty! \n";
        return ss.str();
    }
};

#endif