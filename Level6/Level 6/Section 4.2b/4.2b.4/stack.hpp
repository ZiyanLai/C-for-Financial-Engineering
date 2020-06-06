/*
 * fileName:          stack.hpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-05
 * @lastModifiedDate: 2020-06-05
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Stack Class (Composed of Array)*/

#ifndef STACK_HPP
#define STACK_HPP
#include <iostream>
#include "array.cpp"
using namespace std;

// declare using template
template <typename T>
class Stack
{
private:
    unsigned int m_current;     // current index
    Array<T> m_array;           // array

public:
    // default constructor
    Stack();

    // constructor that takes a size value
    Stack(unsigned int size);

    // copy constructor
    Stack(const Stack<T>& anotherS);

    // destructor
    ~Stack();

    // assignment operator
    Stack<T>& operator = (const Stack<T>& rhs);

    // push to the last index
    void Push(const T& source);

    // pop the element in the last index
    T Pop();
};

#ifndef STACK_CPP
#include "stack.cpp"
#endif
#endif