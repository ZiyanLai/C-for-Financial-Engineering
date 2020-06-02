//
//  point.hpp
//  2.3.7
//
//  Created by Ziyan Lai on 5/29/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//  Made Point Getter Normal Inline and Point Setter Default Inline

#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>
using namespace std;


class Point
{
private:
    double m_x;     // X coordinate
    double m_y;     // Y coordinate

public:
    // Default Constructor
    Point();             
    // Copy Constructor       
    Point(const Point& anotherP);     
    // Constructor that takes value
    Point(double x, double y);  
    // Destructor
    ~Point();

    // Getter of coordinates (Normal Inline)
    double X() const;
    double Y() const;

    // Setter of coordinates (Default Inline)
    void X(double newX){ m_x = newX; }
    void Y(double newY){ m_y = newY; }

    // Fucntion to display the X and Y coordinate and return a string
    string ToString() const;

    // Function to calculate the distance between the Point and the origin
    double Distance() const;
    // Function to calculate distance between 2 poitns
    double Distance(const Point& p) const;
};

// Getter for X and Y coordinates (Normal Inline)
inline double Point::X() const { return m_x; }
inline double Point::Y() const { return m_y; }

#endif
