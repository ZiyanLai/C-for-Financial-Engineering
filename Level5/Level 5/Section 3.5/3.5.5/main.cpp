/*
 * fileName:          main.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-03
 * @lastModifiedDate: 2020-06-03
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/
/* Test Template Method Pattern */

#include <iostream>
#include "point.hpp"
#include "line.hpp"
#include "circle.hpp"
#include "shape.hpp"
using namespace std;

int main()
{
	// create a Point object
    Point p(5.0, 5.0);

	// create a Line object
	Line l(Point(1.0, 1.0), Point(2.0,2.0));

	// use the Base class function that they inherit to call ToString() function
	p.Print();
	l.Print();
    return 0;
}

// Yes, each objects print their own information and ID.
// This is because both Point and Line inherit the function Print(), so they can use it even they don't have Print() defined.
// In Print(), the function delegate derived class's own ToString() (since we override the base class's ToString in both Point and Line).
// Therefore, each object get to print the correct corresponding information.
