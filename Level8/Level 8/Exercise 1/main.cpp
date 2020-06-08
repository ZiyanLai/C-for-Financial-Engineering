/*
 * fileName:          main.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-07
 * @lastModifiedDate: 2020-06-07
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Test Boost shared pointers */

#include <iostream>
#include "shape.hpp"
#include "array.hpp"
#include "point.hpp"
#include "line.hpp"
#include "circle.hpp"
#include <boost/shared_ptr.hpp>
using namespace std;


int main()
{
    // Typedef for a shared pointer to shape and
    // a typedef for an array with shapes stored as shared pointers.
    typedef boost::shared_ptr<Shape> shapePtr;

    typedef Array<shapePtr> shapeArray;

    // create several shapePtr for difference shapes
    shapePtr pointPtr = shapePtr(new Point(1,1));

    shapePtr linePtr = shapePtr(new Line(Point(1,1), Point(10,10)));

    shapePtr circlePtr = shapePtr(new Circle(Point(3,3), 5));

    
    // inner scope
    {
        // initialize a shape array
        shapeArray myShapeArray(1);
        // store a point pointer 
        myShapeArray[0] = pointPtr;
        // print out the Point
        cout << "Point: " << pointPtr->ToString() << endl;
        // print out the point pointer reference count  (2)
        cout << "Point reference: " << pointPtr.use_count() << endl;    
    }

    // print out the point reference count when it goes out of scope  (1)
    cout << "Point reference: " << pointPtr.use_count() << endl;
    cout << endl;

    // inner scope
    {
        // initialize a shape array of size 2
        shapeArray myShapeArray(2);
        // store a line pointer and a circle pointer
        myShapeArray[0] = linePtr;
        myShapeArray[1] = circlePtr;

        // print out the Line
        cout << "Line: " << linePtr->ToString() << endl;
        // print out the line pointer reference count   (2)
        cout << "Line reference: " << linePtr.use_count() << endl;  
        // print out the Circle
        cout << "Circle: " << circlePtr->ToString() << endl;    
        // print out the circle pointer reference count (2)
        cout << "Circle reference: " << circlePtr.use_count() << endl;
    }
    cout << endl;
    // print out the line reference count when it goes out of scope (1)
    cout << "Line reference : " << linePtr.use_count() << endl;
    // print out the circle reference count when it goes out of scope (1)
    cout << "Circle reference: " << circlePtr.use_count() << endl;

    return 0;
}
