/*
 * fileName:          main.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-02
 * @lastModifiedDate: 2020-06-02
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

#include <iostream>
#include "point.hpp"
#include "line.hpp"
using namespace std;

int main()
{
    Line l1;    // Without using the colon syntax for Line default constructor, 
                // this will call the Point Default Constructor 2 times
                // Point Constructor that takes two values 2 times,
                // and will call the Point Destructor 4 times.
                // In this order: 
                // Point Default Constructor
                // Point Default Constructor
                // Point Constructor that takes 2 values
                // Point destructor
                // Point Constructor that takes 2 values
                // Point destructor
                // Point destructor
                // Point destructor


                // Now using the colon syntax for Line default constructor,
                // this will call the Point Constructor that takes values 2 times,
                // and Point destructor 2 times
                // In this order:
                // Point Constructor that takes 2 values
                // Point Constructor that takes 2 values
                // Point destructor
                // Point destructor

                // Therefore, using colon syntax is more efficient


    return 0;
}

