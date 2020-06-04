/*
 * fileName:          shape.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-03
 * @lastModifiedDate: 2020-06-03
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Add pure virtual Draw() function */


#include <iostream>
#include "shape.hpp"
using namespace std;

// Default Constructor
// initialize m_id with a random number 
Shape::Shape() : m_id(rand()){}

// Constructor that takes a value
Shape::Shape(const Shape& anotherP) : m_id(anotherP.m_id){}

// virtual Destructor
Shape::~Shape(){}

// assignment operator
Shape& Shape::operator = (const Shape& source)
{
    // check if self assignment, then return itself
    if (this == &source) { return *this; }

    // if not self assignment, copy over the data
    m_id = source.m_id;
    // return this Shape
    return *this;
}

// virtual function to display the ID
string Shape::ToString() const
{
    stringstream ss;
    ss << "ID: " << m_id;
    return ss.str();
}

// Getter to get the ID
int Shape::ID() const { return m_id; }

// pure virtual Draw() function has no implementation in source file
// void Draw() { cout << "Shape Drawing\n";}