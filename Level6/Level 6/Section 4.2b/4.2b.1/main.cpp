/*
 * fileName:          main.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-03
 * @lastModifiedDate: 2020-06-03
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Test the static variable for Array class */
#include <iostream>
#include "array.cpp"
#include "point.hpp"
#include "shape.hpp"
#include "arrayException.hpp"
using namespace std;

int main()
{
    
    Array<int> intArray1;
    Array<int> intArray2;
    Array<double> doubleArray;
    cout << intArray1.DefaultSize() << endl; 
    cout << intArray2.DefaultSize() << endl; 
    cout << doubleArray.DefaultSize() << endl;
    intArray1.DefaultSize(15);
    cout << intArray1.DefaultSize() << endl; 
    cout << intArray2.DefaultSize() << endl; 
    cout << doubleArray.DefaultSize() << endl;

    
    return 0;
}

// The main() function will print the following:
// 10
// 10
// 10
// 15
// 15
// 10
// This is because first of all, static members are shared among all objects from the same class.
// So after we set intArray1's default size to 15, intArray2's default size will change accordingly.
// The reason why doubleArray's default size is still 10 is that doubleArray belongs to class Array<double>,
// not Array<int>. So doubleArray is not the same class as intArray1 or intArray2, and therefore when we change
// the static member in Array<int>, the objects in Array<double> remains unaffected.