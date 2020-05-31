//
//  point.cpp
//  2.3.3
//
//  Created by Ziyan Lai on 5/29/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//


#include "point.hpp"

Point::Point() {std::cout << "HELLO POINT\n"; }         // Default Constructor

Point::Point(Point& anotherP){                          // Copy Constructor
    m_x = anotherP.m_x;
    m_y = anotherP.m_y;
    std::cout << "HELLO POINT (Copy Constructor)\n";
}
Point::Point(double x, double y) : m_x(x), m_y(y){      // Constructor that takes value
    std::cout << "HELLO POINT (Constructor that takes value)\n";
}

Point::~Point() {std::cout << "BYE POINT\n"; }          // Destructor

// Getter
double Point::X(){ return m_x; }
double Point::Y(){ return m_y; }

// Setter
void Point::X(double newX){ m_x = newX; }
void Point::Y(double newY){ m_y = newY; }

void Point::ToString(){
    std::stringstream ss;
    ss << "Point(" << m_x << "," << m_y << ")\n";
    std::cout << ss.str();
}

double Point::Distance(){
    double res = std::sqrt(pow(m_x, 2) + pow(m_y, 2));
    return res;
}

double Point::Distance(const Point& p){
    double res = std::sqrt(pow(m_x - p.m_x, 2) + pow(m_y-p.m_y, 2));
    return res;
}
