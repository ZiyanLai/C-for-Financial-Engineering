/*
 * fileName:          point.hpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-05-31
 * @lastModifiedDate: 2020-05-31
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Add Ostream Opeartors in addition to the previous Point class */

#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>
#include <cmath>
#include "sstream"
using namespace std;

// Point class
class Point
{
private:
    double m_x;                       // X coordinate
    double m_y;                       // Y coordinate 

public:
    Point();                          // Default Constructor
    Point(const Point& anotherP);     // Copy Constructor
    Point(double x, double y);        // Constructor that takes 2 value
    explicit Point(double value);     // Constructor that takes 1 value
    ~Point();                         // Destructor
    
    // Getter of coordinate X and Y 
    double X() const;
    double Y() const;
    
    // Setter of coordinate X and Y
    void X(double newX);
    void Y(double newY);
    
    // Function to display the Point attribute 
    string ToString() const;
    
    // Calculate the distance between a point to origin
    double Distance() const;

    // Calculate the distance between two points
    double Distance(const Point& p) const;

    // Member Operators Overloading
    Point operator - () const;                  // Negate the coordinate 
    Point operator * (double factor) const;     // Scale the coordinate
    Point operator + (const Point& p) const;    // Add the coordinate
    bool operator == (const Point& p) const;    // Equally compare operator
    Point& operator = (const Point& source);    // Assignment operator
    Point& operator *= (double factor);         // Scale and assign the coordinate

    friend ostream& operator << (ostream& os, const Point& p); // Ostream operator as a friend of Point class
};




#endif
