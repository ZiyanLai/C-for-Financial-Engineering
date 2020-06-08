/*
 * fileName:          main.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-07
 * @lastModifiedDate: 2020-06-07
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/
/* Test boost variant and visitors */

#include <iostream>
#include "point.hpp"
#include "line.hpp"
#include "circle.hpp"
#include <boost/variant.hpp>
#include "variantVisitors.hpp"
using namespace std;


// declare to use variant from boost
using boost::variant;
// define a type ShapeType for convinience
typedef variant<Point, Line, Circle> ShapeType;


// function to return a ShapeType
ShapeType createVariant()
{
    // initiate instances 
    char choice;
    ShapeType shapeVariant;
    // ask for user input
    cout << "Please enter a letter of which shape you want to build:\na. Point; b. Circle; c. Line" << endl;
    // read user input
    cin >> choice;

    // use switch to handle different inputs
    switch (choice)
    {
    case 'a':
        // assign shapeVariant to a Point object
        shapeVariant = Point(1.0, 1.0);
        break;
    case 'b':
        // assign shapeVariant to a Circle object
        shapeVariant = Circle(Point(1.0, 1.0), 1);
        break;
    case 'c':
        // assign shapeVariant to a Line object
        shapeVariant = Line(Point(0.0, 0.0), Point(2.0, 2.0));
        break;
    }
    // return the result
    return shapeVariant;
}


int main()
{
    // create an an ShapeType isntance and assign to the function returned value
    ShapeType userShape = createVariant();
    // print this shape the user selected
    cout << userShape << endl;

    try
    {
        // try to get a Line object out of variant
        boost::get<Line>(userShape);
    }

    // if there is no Line instance
    // catch with bad_get 
    catch(boost::bad_get& err)
    {
        // print the error
        cout << "\n" << err.what() << endl;
    }

    // initiate a vistor with constructor 
    VariantVisitors visitor(5.0, 5.0);
    // use boost library to use apply visitor
    boost::apply_visitor(visitor, userShape);

    // print the shifted result
    cout << "\nAfter shifting X and Y coordinates by 5.0:\n" << userShape << endl;

    return 0;

}