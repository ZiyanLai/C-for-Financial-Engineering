/*
 * fileName:          main.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-03
 * @lastModifiedDate: 2020-06-03
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Test derived class overridden functions */

#include <iostream>
#include "point.hpp"
#include "line.hpp"
#include "circle.hpp"
#include "shape.hpp"
using namespace std;

int main()
{
    Shape s;                                // Create shape.
    Point p(10, 20);                        // Create point.
    Line l(Point(1,2), Point(3, 4));        // Create line.
    cout << s.ToString() << endl;           // Print shape. 
    cout << p.ToString() << endl;           // Print point.
    cout << l.ToString() << endl;           // Print line
    
    cout << "Shape ID: " << s.ID() << endl; // ID of the shape.
    cout << "Point ID: "<< p.ID() << endl;  // ID of the point. Does this work? Yes, it works.
    cout << "Line ID: "<< l.ID() << endl;   // ID of the line. Does this work? Yes, it works.
                                            // Each will print their own IDs. This is because Point and Line are inherited from Shape, and since the ID function is public,
                                            // they can both use the ID function to access the private field in Shape, which is m_id.


    Shape* sp;                              // Create pointer to a shape variable.
    sp = &p;                                // Point in a shape variable. Possible? Yes this is possible. 
                                            // This is because it is allowed to use a base class pointer point to a derived class,
                                            // base on the fact that a derived class object IS A base class object.

    cout << sp -> ToString() << endl;       // What is printed?
                                            // Since we now have keyword 'virtual' in the ToString function in Shape class,
                                            // when we dereference the pointer, it will call the Point ToString() correctly.
                                            
    // Create and copy Point p to new point.
    Point p2;                               
    p2 = p;
    cout << p2 << ", " << p2.ID() << endl;  // Is the ID copied if you do not call
                                            // the base class assignment in point?
                                            // The ID will not be copied if we do not call the base class assignment operator 
                                            // in Point's assignment operator.
                                            // This is becausae ID is a member in the base class,
                                            // and it is essential to copy the base portion of data when doing assignment operator in derived class.
    return 0;
}

// Since now we call the Shape's ToString() in each Derived class's ToString(),  everytime we call the ToString() function on a Derived class,
// its corresponding ID will also be pritned.

