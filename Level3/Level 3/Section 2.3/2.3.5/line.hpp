//
//  line.hpp
//  2.3.5
//
//  Created by Ziyan Lai on 5/30/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//

#ifndef LINE_HPP
#define LINE_HPP
#include <iostream>
#include "point.hpp"
using namespace std; 

class Line{
private:
    Point p1; // Start Point    
    Point p2; // End Point
public:

    // Default Constructor
    Line(); 

    // Constructor takes value
    Line(const Point& startP, const Point& endP); 

    // Copy Constructor
    Line(const Line& anotherLine); 

    // Destructor     
    ~Line(); 

    // Getter for start point   
    Point startPoint() const; 

    // Getter for end point
    Point endPoint() const;  

    // Setter for start point 
    void startPoint(const Point& anotherP);   

    // Setter for end point
    void endPoint(const Point& anotherP);   

    // Function to store the attribute into a string for diaplay
    string ToString() const;

    // Function to calculate the length of Line
    double Length() const;
};

#endif
