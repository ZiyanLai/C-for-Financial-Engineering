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
    // store the element in current index
    // if the index is invalid, Array class will throw an exception
    m_array[m_current] = source;
    // if Array does not throw an error, increment current index
    m_current +=1;

}

// Pop function
template<typename T> 
T Stack<T>::Pop()
{
    // use the array to access the index first
    // if the index is not valid, an exception will be thrown
    T popElem = m_array[m_current - 1];
    // if there is no exception, we decrement the index
    m_current -= 1;    

    // return the Pop element
    return popElem;
}

#endif