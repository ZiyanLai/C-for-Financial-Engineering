/*
 * fileName:          array.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-03
 * @lastModifiedDate: 2020-06-03
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Add functionality to throw exceptions */

#include <iostream>
#include "array.hpp"
using namespace std;

// Default Constructor to create an array of size 10
Array::Array() : m_data(new Point[10]), m_size(10) {}

// Constructor that takes a value of size 
Array::Array(const unsigned int size) : m_data(new Point[size]), m_size(size) {}

// Copy Constructor 
Array::Array(const Array& anotherA)
{   
    // copy over the size
    m_size = anotherA.m_size;
    // assign new array with copied size on heap
    m_data = new Point[m_size];
   
    // for each element in the another Array
    for (int i = 0; i < anotherA.m_size; i++)
    {
        // copy over each element
        m_data[i] = anotherA.m_data[i];
    }
}

// Destructor
Array::~Array()
{
    // free the memory allocated on heap, using [] syntax
    delete[] m_data;
}

// Assignment Operator
Array& Array::operator = (const Array& rhs)
{
    // if the right hand side is the Array itself
    if (this == &rhs)
    {
        // return the Array it self
        return *this;
    }
    // free up resources
    delete[] m_data;

    // make the size equals to the size of right hand side Array
    m_size = rhs.m_size;
    // allocate new array with the size equals to the right hand side Array
    m_data = new Point[m_size];
    
    // for each element in the right hand side Array
    for (int i = 0; i < rhs.m_size; i++)
    {
        // copy over the data into this Array
        m_data[i] = rhs.m_data[i];
    }
    // return the this Array
    return *this;
}

// Getter of the size of the Array
unsigned int Array::Size() const
{
    // return the member data m_size
    return m_size;
}

// Setter of the element in Array
void Array::SetElement(int index, const Point& newP)
{
    // if the index is out of bound or negative
    if (index > m_size - 1 || index < 0)
    {
        // throw an int exception
        throw -1;
    }
    // otherwise, return the corresponding Point 
    m_data[index] = newP;
}

// Getter of the element in Array
const Point& Array::GetElement(int index) const
{   
    // if the index is out of bound or negative
    if (index > m_size - 1 || index < 0)
    {
        // throw int exception
        throw -1;
    }
    // otherwise, return the corresponding Point
    return m_data[index];
}

// index operator
// here we return a reference of Point
// so we allow both read and write of Point
Point& Array::operator [] (int index)
{
    // if index is out of bound
    if (index > m_size - 1 || index < 0)
    {
        // throw int error
        throw -1;
    }
    // otherwise return the corresponding Point
    return m_data[index];
}

// const version of index operator
// here we return a const reference of Point and make the function const
const Point& Array::operator [] (int index) const
{
    // if the index is out of bound
    if (index > m_size - 1 || index < 0)
    {
        // throw int error
        throw -1;
    }
    // otherwise, return the corresponding Point
    return m_data[index];
}