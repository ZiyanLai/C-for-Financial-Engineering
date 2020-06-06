/*
 * fileName:          array.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-03
 * @lastModifiedDate: 2020-06-03
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Add static function to Setter and Getter of default size */

#ifndef ARRAY_CPP
#define ARRAY_CPP
#include <iostream>
#include "array.hpp"
#include "outOfBoundException.hpp"
using namespace std;

// initialize m_defaultSize
template <typename T>
unsigned int Array<T>::m_defaultSize = 10;

// static function to Set the default array size
template <typename T>
void Array<T>::DefaultSize(unsigned int defaultSize) { m_defaultSize = defaultSize; }

// static function to Get the default array size
template <typename T>
unsigned int Array<T>::DefaultSize() { return m_defaultSize; }

// Default Constructor to create an array of size 10
template <typename T>
Array<T>::Array() : m_data(new T[m_defaultSize]), m_size(m_defaultSize){}

// Constructor that takes a value of size 
template <typename T>
Array<T>::Array(unsigned int size) : m_data(new T[size]), m_size(size) {}

// Copy Constructor 
template <typename T>
Array<T>::Array(const Array<T>& anotherA)
{   
    // copy over the size
    m_size = anotherA.m_size;
    // assign new array with copied size on heap
    m_data = new T[m_size];
   
    // for each element in the another Array
    for (int i = 0; i < anotherA.m_size; i++)
    {
        // copy over each element
        m_data[i] = anotherA.m_data[i];
    }
}

// Destructor
template <typename T>
Array<T>::~Array()
{
    // free the memory allocated on heap, using [] syntax
    delete[] m_data;
}

// Assignment Operator
template <typename T>
Array<T>& Array<T>::operator = (const Array<T>& source)
{
    // if the right hand side is the Array itself
    if (this == &source)
    {
        // return the Array it self
        return *this;
    }
    // free up resources
    delete[] m_data;

    // make the size equals to the size of right hand side Array
    m_size = source.m_size;
    // allocate new array with the size equals to the right hand side Array
    m_data = new T[m_size];
    
    // for each element in the right hand side Array
    for (int i = 0; i < source.m_size; i++)
    {
        // copy over the data into this Array
        m_data[i] = source.m_data[i];
    }
    // return the this Array
    return *this;
}

// Getter of the size of the Array
template <typename T>
unsigned int Array<T>::Size() const
{
    // return the member data m_size
    return m_size;
}

// Setter of the element in Array
template <typename T>
void Array<T>::SetElement(int index, const T& newSource)
{
    // if the index is out of bound or negative
    if (index > m_size - 1 || index < 0)
    {
        // throw an OutOfBoundException
        throw OutOfBoundException(index);
    }
    // otherwise, set the corresponding T 
    m_data[index] = newSource;
}

// Getter of the element in Array
template <typename T>
const T& Array<T>::GetElement(int index) const
{   
    // if the index is out of bound or negative
    if (index > m_size - 1 || index < 0)
    {
        // throw int exception
        throw OutOfBoundException(index);
    }
    // otherwise, return the corresponding T
    return m_data[index];
}

// index operator
// here we return a reference of T
// so we allow both read and write of T
template <typename T>
T& Array<T>::operator [] (int index)
{
    // if index is out of bound
    if (index > m_size - 1 || index < 0)
    {
        // throw int error
        throw OutOfBoundException(index);
    }
    // otherwise return the corresponding T
    return m_data[index];
}

// const version of index operator
// here we return a const reference of T and make the function const
template <typename T>
const T& Array<T>::operator [] (int index) const
{
    // if the index is out of bound
    if (index > m_size - 1 || index < 0)
    {
        // throw int error
        throw OutOfBoundException(index);
    }
    // otherwise, return the corresponding T
    return m_data[index];
}

#endif
