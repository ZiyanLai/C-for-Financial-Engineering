/*
 * fileName:          line.hpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-05-31
 * @lastModifiedDate: 2020-05-31
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Add Ostream Opeartors in addition to the previous Line class */

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

    // Assignment Operator
    Line& operator = (const Line& anotherLine);     

    // Setter for start point 
    Point startPoint() const;                       

    // Setter for end point
    Point endPoint() const;                         

    // Getter for start point 
    void startPoint(const Point& anotherP);           

    // Getter for end point
    void endPoint(const Point& anotherP);           

    // Function to display the attributes of line
    string ToString() const;                          
    
    // Function to calculate the length of line
    double Length() const;                          

};

ostream& operator << (ostream& os, const Line& l); // Ostream operator 
#endif