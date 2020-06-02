/*
 * fileName:          main.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-05-31
 * @lastModifiedDate: 2020-05-31
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

// Test Ostream Operators

#include "point.hpp"
#include "line.hpp"
#include "circle.hpp"
#include <iostream>
using namespace std;

int main()
{   
    // ask the user to input the X and Y coordinates of the first point
    double xCor1, yCor1;
    cout << "\nPlease enter an X coordinate and a Y coordinate for point 1: " << endl;
    cin >> xCor1 >> yCor1;
    
    // create point 1
    Point p1(xCor1, yCor1);
    
    // display the attributes of point 1
    cout << "p1 = " << p1.ToString() << endl;
    
    // ask the user to input the X and Y coordinates of the second point
    double xCor2, yCor2;
    cout << "\nPlease enter an X coordinate and a Y coordinate for point 2: " << endl;
    cin >> xCor2 >> yCor2;
    
    // create point 2
    Point p2(xCor2, yCor2);

    // display the attributes of point 2
    cout << "p2 = " << p2.ToString() << endl;
    


    cout << "\nNow let's test the operators of Point class: \n";

    // create p3 to test - operator
    Point p3 = -p1;
    cout << "p3 = -p1 = " << p3.ToString() << endl;
    
    // create p4 to test + operator
    Point p4 = p1 + p2;
    cout << "p4 = (p1 + p2) = " << p4.ToString() << endl;
    
    // create p5 to test * operator
    Point p5 = p1 * 4;
    cout << "(p1 * 4) = " << p5.ToString() << endl;

    // test assignment operator
    p3 = p4;
    cout << "After (p3 == p4), p3 = " << p3.ToString() << endl;
    
    // test == operator
    // use ternary operator to print if p3 = p4 or not after assigning p3 = p4
    cout << "Is p3 equals to p4 now? " << ((p3 == p4) ? "Yes, p3 equals to p4" : "No, p3 is not equals to p4") << endl;

    // test *= operator 
    p1 *= 3;
    cout << "p1 *= 3, p1 = " << p1.ToString() << endl ;



    // start to test assignment operator of Line class
    cout << "\nNow let's test the assignment operator of Line class: \n";
    
    // initialize line1 with point p1 & p2; 
    //            line2 with point p3 & p5; 
    Line line1 = Line(p1, p2);
    Line line2 = Line(p3, p5);

    // display line1
    cout << "line1:\n" << line1.ToString() << endl;

    // display line2
    cout << "line2:\n" << line2.ToString() << endl;

    // use assignment operator to assign line1 = line2
    line1 = line2;

    // print line1 after assignment operator
    cout << "\nAfter assigning line1 = line2, \nnow line1 is:\n" << line1.ToString() << endl;



    // start to test assignment operator of Circle class
    cout << "\nNow let's test the assignment operator of Circle class: \n";

    double rad1 = 4.5;
    double rad2 = 5.0;
    // initialize circle1 with radius 4.5 and center p1
    Circle circle1 = Circle(p1, rad1);
     // display circle1
    cout << "circle1:\n" << circle1.ToString() << endl;
   
    // initialize circle1 with radius 5.0 and center p2
    Circle circle2 = Circle(p2, rad2);
    // display circle2
    cout << "circle2:\n" << circle2.ToString() << endl;
    
    // use assignment operator to assign circle1 = circle2
    circle1 = circle2;
    // print circle1 after assignment
    cout << "\nAfter assiging circle1 = circle2,\nnow circle1 is: " << circle1.ToString() << endl;



    // Test the Ostream Operators for different class
    cout << "\nNow let's test the Ostream Operators: \n\n";

    // Test the Ostream Operator for Point
    cout << "Ostream Operator for Point:\n"<<"point1: " << p1 << endl;
    // Test the Ostream Operator for Line
    cout << "Ostream Operator for Line:\n"<<"line1:\n" << line1 << endl;
    // Test the Ostream Operator for Circle
    cout << "Ostream Operator for Circle:\n"<<"circle1:\n" << circle1 << endl;

    return 0;
}