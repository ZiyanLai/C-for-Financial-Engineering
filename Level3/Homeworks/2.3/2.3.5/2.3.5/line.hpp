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
    Line(); // Default Constructor

    Line(const Point& startP, const Point& endP); // Constructor takes value

    Line(const Line& anotherLine); // Copy Constructor
       
    ~Line(); // Destructor

    Point startPoint() const; // Setter for start point 

    Point endPoint() const;  // Setter for end point

    void startPoint(const Point& anotherP); // Getter for start point   

    void endPoint(const Point& anotherP);   // Getter for end point

    void ToString() const;

    double Length() const;


};

#endif /* line_hpp */
