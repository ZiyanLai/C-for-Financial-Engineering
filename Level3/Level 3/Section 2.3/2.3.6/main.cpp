//
//  main.cpp
//  2.3.6
//
//  Created by Ziyan Lai on 5/30/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//

#include "circle.hpp"
#include "point.hpp"
using namespace std;

int main() 
{
    // define X and Y coordinates for Point
    double xCor1, yCor1;
    // ask for user input
    cout << "Please enter an X coordinate and a Y coordinate for the center of circle: " << endl;
    // read user input
    cin >> xCor1 >> yCor1;

    // define radius for Circle
    double radius;
    // ask for user input
    cout << "Please enter a radius for the circle: " << endl;
    // read user input
    cin >> radius;

    // create Point using the previous point, and use this Point as center of the Circle
    Point center(xCor1, yCor1);

    // create Circle using the Point and the radius
    Circle circle1(center, radius);

    // create Circle using Copy Constructor
    Circle circle2(circle1);

    // print the Circle 1
    cout << "\nCircle 1: " << circle1.ToString() << endl;

    // print the Circle 2
    cout << "\nCircle 2(Created by Copy Constructor): " << circle2.ToString() << endl;

    // calculate the circumference and print
    double circum = circle1.Circumference();
    cout << "\nCircle 1's circumference is " << circum << endl;

    //calculate the area and print
    double area = circle1.Area();
    cout << "\nCircle 1's area is " << area << endl;

    // calculate the diameter and print
    double diam = circle1.Diameter();
    cout << "\nCircle 1's diameter is " << diam << endl;

    return 0;
}