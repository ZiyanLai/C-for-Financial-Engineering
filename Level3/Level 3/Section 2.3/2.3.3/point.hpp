//
//  point.hpp
//  2.3.3
//
//  Created by Ziyan Lai on 5/29/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//  Overload function of Setters & Getters and Distance & DistanceOrigin


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
    
    // Getter of the coordinate
    double X();
    double Y();
    
    // Setter of the coordinate
    void X(double newX);
    void Y(double newY);

    // Fucntion to display the X and Y coordinate and return a string
    std::string ToString();

    // Function to calculate the distance between the Point and the origin
    double Distance();                
    // Function to calculate distance between 2 poitns
    double Distance(const Point& p);  

};

#endif
