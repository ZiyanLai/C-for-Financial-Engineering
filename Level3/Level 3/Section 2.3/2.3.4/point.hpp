//
//  point.hpp
//  2.3.4
//
//  Created by Ziyan Lai on 5/29/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//  set X(), Y(), Distance() and ToString() as const since they don't change input values

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
    
    // Getter of coordinates
    double X() const;
    double Y() const;
    
    // Setter of coordinates
    void X(double newX);
    void Y(double newY);
    
    // Fucntion to display the X and Y coordinate and return a string
    string ToString() const;


    // Function to calculate the distance between the Point and the origin
    double Distance() const;
    // Function to calculate distance between 2 poitns
    double Distance(const Point& p) const;

};

#endif
