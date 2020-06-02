//
//  point.hpp
//  2.3.1
//
//  Created by Ziyan Lai on 5/29/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//  Add Copy Constructor and Constructor that takes 2 values

#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>

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
    
    // Getter of X coordinate
    double GetX();
    // Getter of Y coordinate
    double GetY();
    // Setter of X coordinate
    void SetX(double newX);
    // Setter of Y coordinate
    void SetY(double newY);
    // Fucntion to display the X and Y coordinate and return a string
    std::string ToString();
    // Function to calculate the distance between the Point and the origin
    double DistanceOrigin();
    // Function to calculate the distance between two points
    double Distance(Point p);

};

#endif
