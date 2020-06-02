/*
 * fileName:          main.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-05-31
 * @lastModifiedDate: 2020-05-31
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Adding a constructor and making it explicit */

#include "point.hpp"
#include <iostream>
using namespace std;

int main()
{   
    // Constructors as conversion operator
    Point p(1.0, 1.0);
    // if (p == 1.0) cout << "Equal!" << endl; 

    // Now that the Constructor which takes 1 value is 'explict' 
    // We can only used it explicitly
    if (p == Point(1.0)) cout << "Equal!" << endl; 
    else cout << "Not equal" << endl;

    return 0;
}

// Before adding 'explicit', the argument '1' get to implicitly use the constructor that takes 1 value.
// After making the constructor that takes 1 value explicit, we will need to explicitly define Point(1)
// to make the code work.