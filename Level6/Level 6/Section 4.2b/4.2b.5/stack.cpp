/*
 * fileName:          stack.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-05
 * @lastModifiedDate: 2020-06-05
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Stack Class (Composed of Array)*/

#ifndef STACK_CPP
#define STACK_CPP

#include "stack.hpp"
#include "array.hpp"
#include "stackException.hpp"
#include <iostream>
using namespace std;

// default constructor
template<typename T> 
Stack<T>::Stack() : m_current(0) {}

// constructor that takes a size value
template<typename T> 
Stack<T>::Stack(unsigned int size) : m_current(0), m_array(size) {}

// copy constructor
template<typename T> 
Stack<T>::Stack(const Stack<T>& anotherS) : m_current(anotherS.m_current), m_array(anotherS.m_array) {}

// destructor
template<typename T> 
Stack<T>::~Stack(){}

// assignment operator
template<typename T> 
Stack<T>& Stack<T>::operator = (const Stack<T>& source)
{
    // if self assignment, return this Stack
    if (this == &source) { return *this; }

    // else, assign components
    m_current = source.m_current;
    m_array = source.m_array;

    // return this Stack
    return *this;
}

// Push function
template<typename T> 
void Stack<T>::Push(const T& source)
{
    try
    {
        // try to add element to current index
        m_array[m_current] = source;
    }
    // if the index is not valid
    // array will throw an OutOfBoundException, which inherit from ArrayException class
    catch(ArrayException& ae)
    {
        // throw a Stack exception
        throw StackFullException();
    }

    // if there is no error, increment the index
    m_current += 1;
}

// Pop function
template<typename T> 
T Stack<T>::Pop()
{
    T popElem;

    try
    {
        // try to pop the element on current index - 1
        popElem = m_array[m_current - 1];
    }
    // if the index is not valid
    // array will throw an OutOfBoundException, which inherit from ArrayException class
    catch(ArrayException& ae)
    {
        // throw a Stack exception
        throw StackEmptyException();
    }
    
    // if there is no error, decrement the index
    m_current -= 1;    
    // and return the poped element
    return popElem;
}
#endif