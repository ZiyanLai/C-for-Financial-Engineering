//
//  point.hpp
//  2.2.1
//
//  Created by Ziyan Lai on 5/29/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//

#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>
#include "sstream"

class Point{
private:
    double m_x;
    double m_y;

public:
    Point();
    ~Point();
    double GetX();
    double GetY();
    void SetX(double newX);
    void SetY(double newY);
    void ToString();

};

#endif