//
//  point.hpp
//  2.3.3
//
//  Created by Ziyan Lai on 5/29/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//

#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>
#include <cmath>
#include "sstream"


class Point{
private:
    double m_x;
    double m_y;

public:
    Point();                    // Default Constructor
    Point(Point& anotherP);     // Copy Constructor
    Point(double x, double y);  // Constructor that takes value
    ~Point();
    
//  getter of the coordinate
    double X();
    double Y();
    
//  setter of the coordinate
    void X(double newX);
    void Y(double newY);
    
    void ToString();

    double Distance();                // Distance from point to origin
    double Distance(const Point& p);  // Distance between two points

};

#endif