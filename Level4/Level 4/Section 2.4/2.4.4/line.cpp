/*
 * fileName:          line.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-05-31
 * @lastModifiedDate: 2020-05-31
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Make Ostream Opeartors as a friend in addition to the previous Line class */

#include "line.hpp"
using namespace std;

Line::Line() : p1(0, 0), p2(0, 0) {} // Default Constructor

Line::Line(const Point& startP, const Point& endP) : p1(startP), p2(endP) {} // Constructor that takes value

Line::Line(const Line& anotherLine) : p1(anotherLine.p1), p2(anotherLine.p2) {} // Copy Constructor

// Destructor
Line::~Line() {}

// Assignment Operator
Line& Line::operator=(const Line& anotherLine)
{
    // check if self assignment
    if (this == &anotherLine)
    {
        // if self assignment, return the line itself
        return *this;
    }

    // if not self assignment
    p1 = anotherLine.p1;    // assign the start point
    p2 = anotherLine.p2;    // assign the end point
    return *this;           // return this line
}

// Getter of start point
const Point& Line::startPoint() const { return p1; } 

// Getter of end point
const Point& Line::endPoint() const { return p2; }

// Setter of start point
void Line::startPoint(const Point& anotherP){ p1 = anotherP; }

// Setter of end point
void Line::endPoint(const Point& anotherP) { p2 = anotherP; }

// Function to store the attribute into a string for diaplay
string Line::ToString() const{
    stringstream ss;
    ss << "Start " << p1.ToString() << " End " << p2.ToString();
    return ss.str(); 
}

// Function to calculate the length of Line
double Line::Length() const {
    return p1.Distance(p2);
}

// Ostream operator as a friend of Line class
ostream& operator << (ostream&os, const Line& l)
{
// Now we don't need to call ToString() function
// but instead directly access the private members
 os << "Start Point: " << l.p1 << "; End Point: " << l.p2;
 return os;
}