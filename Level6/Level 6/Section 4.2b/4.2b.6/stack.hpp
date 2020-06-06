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
template <typename T, int size>
class Stack
{
private:
    unsigned int m_current; // current index
    Array<T> m_array;       // array

public:
    // default constructor
    Stack();

    // Stack(unsigned int size);    we don't need this constructor anymore because we speficied a size in template

    // copy constructor
    Stack(const Stack<T, size>& anotherS);

    // destructor
    ~Stack();

    // assignment operator
    Stack<T, size>& operator = (const Stack<T, size>& rhs);

    // Push function to add an element to current index
    void Push(const T& source);

    // Pop function to return the last element
    T Pop();
};

#ifndef STACK_CPP
#include "stack.cpp"
#endif
#endif