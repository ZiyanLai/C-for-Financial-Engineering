//
//  point.hpp
//  2.3.7
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
    
    // Getter of coordinates (Normal Inline)
    inline double X() const;
    inline double Y() const;
    
    
    // Setter of coordinates (Default Inline)
    void X(double newX);
    void Y(double newY);
    
    void ToString() const;
    
    // Calculate distance from point to origin
    double Distance() const;

    // Calculate distance between 2 points
    double Distance(const Point& p) const;

};
// Getter for X and Y coordinates (Normal Inline)
inline double Point::X() const { return m_x; }
inline double Point::Y() const { return m_y; }

#endif
