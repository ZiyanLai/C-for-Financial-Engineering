//
//  point.cpp
//  2.3.6
//
//  Created by Ziyan Lai on 5/30/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//


#include "point.hpp"

// Default Constructor
Point::Point() {}         

// Copy Constructor
Point::Point(const Point& anotherP){                    
    m_x = anotherP.m_x;
    m_y = anotherP.m_y;
}

// Constructor that takes value
Point::Point(double x, double y) : m_x(x), m_y(y){}     

// Destructor
Point::~Point() {}                                      

double Point::X() const { return m_x; }
double Point::Y() const { return m_y; }

void Point::X(double newX){ m_x = newX; }
void Point::Y(double newY){ m_y = newY; }

void Point::ToString() const {
    std::stringstream ss;
    ss << "Point(" << m_x << "," << m_y << ")\n";
    std::cout << ss.str();
}

double Point::Distance() const {
    double res = std::sqrt(pow(m_x, 2) + pow(m_y, 2));
    return res;
}

double Point::Distance(const Point& p) const {
    double res = std::sqrt(pow(m_x - p.m_x, 2) + pow(m_y-p.m_y, 2));
    return res;
}

