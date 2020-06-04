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
    Shape* shapes[10];
    
    // store Derived class objects define on heap in the array
	shapes[0] = new Line;
	shapes[1] = new Point;
	shapes[2] = new Line(Point(1.0, 2.5), Point(3.4, 5.2));
    shapes[3] = new Circle;
	shapes[4] = new Circle(Point(5.0, 6.5), 5.0);
    shapes[5] = new Point(2.0, 1.0);

    // for each object, use polymorphic to call their own Draw function
	for (int i = 0; i != 6; i++) shapes[i]->Draw();
	for (int i = 0; i != 6; i++) delete shapes[i];
    // Shape shape; We cannot create a Shape instance because Shape class is an abstract class
    return 0;
}
