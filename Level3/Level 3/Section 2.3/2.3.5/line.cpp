//
//  line.cpp
//  2.3.5
//
//  Created by Ziyan Lai on 5/30/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//

#include "line.hpp"
#include <iostream>
#include <sstream>
using namespace std;

// Default Constructor
Line::Line() : p1(0, 0), p2(0, 0) {} 

// Constructor that takes value
Line::Line(const Point& startP, const Point& endP) : p1(startP), p2(endP) {} 

// Copy Constructor
Line::Line(const Line& anotherLine) : p1(anotherLine.p1), p2(anotherLine.p2) {} 

// Desstructor
Line::~Line() {}

// Getter of start point
Point Line::startPoint() const 
{ 
    return p1; 
} 

// Getter of end point
Point Line::endPoint() const 
{ 
    return p2; 
}

// Setter of start point
void Line::startPoint(const Point& anotherP)
{ 
    p1 = anotherP; 
}

// Setter of end point
void Line::endPoint(const Point& anotherP) 
{ 
    p2 = anotherP; 
}

// Function to store the attribute into a string for diaplay
string Line::ToString() const
{
    stringstream ss;
    ss << "Start " << p1.ToString() << " End " << p2.ToString();
    return ss.str(); 
}

// Function to calculate the length of Line
double Line::Length() const 
{
    // delegate Point class's Distance function
    return p1.Distance(p2);
}