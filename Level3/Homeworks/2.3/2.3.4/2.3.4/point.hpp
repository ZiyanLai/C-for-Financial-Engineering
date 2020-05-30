//
//  point.hpp
//  2.3.4
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
    
    // Getter of coordinates
    double X() const;
    double Y() const;
    
    // Setter of coordinates
    void X(double newX);
    void Y(double newY);
    
    void ToString() const;
    
    double Distance() const;
    double Distance(const Point& p) const;

};

#endif
