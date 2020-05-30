//
//  point.hpp
//  2.3.2
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
    
    
    double GetX();
    double GetY();
    
    void SetX(double newX);
    void SetY(double newY);
    
    void ToString();
    
    double DistanceOrigin();
    double Distance(const Point& p);

};

#endif
