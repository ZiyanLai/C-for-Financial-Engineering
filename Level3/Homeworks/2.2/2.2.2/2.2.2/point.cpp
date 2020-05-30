//
//  point.cpp
//  2.2.2
//
//  Created by Ziyan Lai on 5/29/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//


#include "point.hpp"

Point::Point() {}
Point::~Point() {}

double Point::GetX(){ return m_x; }
double Point::GetY(){ return m_y; }

void Point::SetX(double newX){ m_x = newX; }
void Point::SetY(double newY){ m_y = newY; }

void Point::ToString(){
    std::stringstream ss;
    ss << "Point(" << m_x << "," << m_y << ")\n";
    std::cout << ss.str();
}

double Point::DistanceOrigin(){
    double res = std::sqrt(pow(m_x, 2) + pow(m_y, 2));
    return res;
}

double Point::Distance(Point p){
    double res = std::sqrt(pow(m_x - p.m_x, 2) + pow(m_y - p.m_y, 2));
    return res;
}

