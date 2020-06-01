/*
 * fileName:          line.hpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-05-31
 * @lastModifiedDate: 2020-05-31
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Add assignment operator in addition to the previous Line class */

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
    Line(); // Default Constructor

    Line(const Point& startP, const Point& endP);   // Constructor takes value

    Line(const Line& anotherLine);                  // Copy Constructor
       
    ~Line();                                        // Destructor

    Line& operator = (const Line& anotherLine);     // Assignment Operator

    Point startPoint() const;                       // Setter for start point 

    Point endPoint() const;                         // Setter for end point

    void startPoint(const Point& anotherP);         // Getter for start point   

    void endPoint(const Point& anotherP);           // Getter for end point

    string ToString() const;                          // Function to display the attributes of line

    double Length() const;                          // Function to calculate the length of line


};

#endif