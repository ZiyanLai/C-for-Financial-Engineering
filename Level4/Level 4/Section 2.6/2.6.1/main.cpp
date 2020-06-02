/*
 * fileName:          main.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-01
 * @lastModifiedDate: 2020-06-01
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Test namespaces */


#include <iostream>
#include "point.hpp"
#include "line.hpp"
#include "circle.hpp"
#include "array.hpp"
using namespace std;

int main()
{
    // use the full namespace for Point class
    // create two objects of Point
    ZiyanLai::CAD::Point point1(5,6), point2(10,20);
    // print the two Points created
    cout << "point1: " << point1 << ";\npoint2: " << point2 << "\n\n";

    // declaration for using a Line class
    using ZiyanLai::CAD::Line;
    // create a Line object after the declaration
    Line line(point1, point2);
    // print the Line 
    cout << "line: " << line << endl;

    // declaration for using the complete ZiyanLai::Containers class
    using namespace ZiyanLai::Containers;

    // after declaration, we can create object of Array without further 
    // inclusion of namespace
    Array array(5);
    // use [] operator to set a Point into the first place in the Array
    // here we create a Point using the full namespace
    array[0] = ZiyanLai::CAD::Point(20, -20);
    // print out the first Point in the Array
    cout << "The first Point in array: " << array[0] << endl;

    // create an Alias of the namespace ZiyanLai::CAD
    namespace ZC = ZiyanLai::CAD;
    // declartion for using a Circle class with the Alias
    using ZC::Circle;
    // create a Circle object with constructor
    // here we create the Point object with the Alias ZC we declared
    Circle circle(ZC::Point(30,-30), 5);
    // print the circle
    cout << "\ncircle: " << circle << endl;

    return 0;
    
}