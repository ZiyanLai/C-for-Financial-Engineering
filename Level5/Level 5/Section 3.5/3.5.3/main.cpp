/*
 * fileName:          main.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-03
 * @lastModifiedDate: 2020-06-03
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/
/* Test virtual base class Destructor*/

#include <iostream>
#include "point.hpp"
#include "line.hpp"
#include "circle.hpp"
#include "shape.hpp"
using namespace std;

int main()
{
    // create a Shape pointer array
    Shape* shapes[3]; 

    // store Derived class objects define on heap in the array
    shapes[0] = new Shape; 
    shapes[1] = new Point; 
    shapes[2] = new Line;
    for (int i = 0; i != 3; i++) delete shapes[i];
    return 0;
}

// Before adding 'virtual' to the Shape Destructor, the destructors are like this:
// Bye Point
// Bye Shape
// Bye Point
// Bye Shape
// Bye Shape
// Bye Shape
// Bye Shape
// Note that the first 4 statements, "Bye Point" "Bye Shape" "Bye Point" "Bye Shape", are resulted from the default constructor in Line class,
// which temporarily constructed two Point inside the function and then is removed by calling the Point Destructor and then Shape Destructor.
// Then the rest 3 "Bye Shape" come from 3 delete. Since we don't have 'virtual' on Shape Destructor, all delete will only call the base class
// destructor, and will not call the derived class destructor when we delete.

// After adding 'virtual' to the Shape Destructor, the destructors are like this:
// Bye Point
// Bye Shape
// Bye Point
// Bye Shape
// Bye Shape
// Bye Point
// Bye Shape
// Bye Line
// Bye Point
// Bye Shape
// Bye Point
// Bye Shape
// Bye Shape
// The first 4 calls are the same from before we adding 'virtual', so let's focus on the rest calls.
// When deleting Shape, it will call itself's destructor. ("Bye Shape")
// When deleting Point, it will first call Point's destructor and then call Shape's destructor. ("Bye Point" + "Bye Shape")
// When deleting Line, it will first delete Line itself, and then delete its 2 Point members. When deleting 2 Points, each Point will delete itself and then call Shape destructor.
// Eventually, Line will also call Shape destructor.
// So that gives us "Bye Line" + "Bye Point" + "Bye Shape" + "Bye Point" + "Bye Shape" + "Bye Shape"
