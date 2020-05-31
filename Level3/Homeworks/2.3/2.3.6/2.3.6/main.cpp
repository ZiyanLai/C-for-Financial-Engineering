//
//  main.cpp
//  2.3.6
//
//  Created by Ziyan Lai on 5/30/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//

#include "circle.hpp"

int main() {
    
    
    double xCor1, yCor1;
    cout << "Please enter an X coordinate and a Y coordinate for the center of circle: " << endl;
    cin >> xCor1 >> yCor1;

    double radius;
    cout << "Please enter a radius for the circle: " << endl;
    cin >> radius;

    Point center(xCor1, yCor1);

    Circle circle(center, radius);

    cout << "\ncircle: \n";
    circle.ToString();

    double circum = circle.Circumference();
    cout << "\nCircle's circumference is " << circum << endl;

    double area = circle.Area();
    cout << "\nCircle's area is " << area << endl;

    double diam = circle.Diameter();
    cout << "\nCircle's diameter is " << diam << endl;



    return 0;
}