//
//  line.cpp
//  2.3.5
//
//  Created by Ziyan Lai on 5/30/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//

#include "line.hpp"

Line::Line() : p1(0, 0), p2(0, 0) {} // Default Constructor

Line::Line(const Point& startP, const Point& endP) : p1(startP), p2(endP) {} // Constructor that takes value

Line::Line(const Line& anotherLine) : p1(anotherLine.p1), p2(anotherLine.p2) {} // Copy Constructor

Line::~Line() {}

// Getter of start point
Point Line::startPoint() const { return p1; } 

// Getter of end point
Point Line::endPoint() const { return p2; }

// Setter of start point
void Line::startPoint(const Point& anotherP){ p1 = anotherP; }

// Setter of end point
void Line::endPoint(const Point& anotherP) { p2 = anotherP; }

void Line::ToString() const{
    cout << "\nLine:\nStart ";
    p1.ToString();
    cout << "End ";
    p2.ToString();    
}

double Line::Length() const {
    return p1.Distance(p2);
}