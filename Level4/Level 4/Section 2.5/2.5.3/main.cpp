/*
 * fileName:          main.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-01
 * @lastModifiedDate: 2020-06-01
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Create Array class to handle copy control */

#include "point.hpp"
#include "array.hpp"

int main()
{
    // use default constructor to create an Array of size 10
    Array array1;           
    // used constructor that takes value to create and Array of size 20
    Array array2(20);
    
    // test the Size() function
    cout << "array1's size: " << array1.Size() << "; array2's size: " << array2.Size() << endl;

    // test SetElement by assigning array1 index 3 with a Point
    array1.SetElement(3, Point(5,9));

    // test [] operator that supports both read and write
    // by assigning array1 index 1 with another Point
    array1[1] = Point(0,2);

    // print out array1's index 1 and 3 to see if the value is assigned
    cout << "array1 index 1: " << array1.GetElement(1) <<  "; array1 index 3: "<< array1.GetElement(3) << endl;
    
    // create array3 with copy constructor
    Array array3(array1);
    // create array4 with assignment operator
    Array array4 = array1;

    // print out index 1 and 3 in both array 3 and array 4 to see if the values are the same as array1
    cout << "array3 index 1: " << array3[1] <<  "; array3 index 3: " << array3[3] << endl;
    cout << "array4 index 1: " << array4[1] <<  "; array3 index 4: " << array4[3] << endl;

    // create a const Array and use copy constructor
    const Array array5(array1);
    // test the const version of [] operator and print the value of third index on screen
    cout << "const array5 index 3: " << array5[3] << endl;


}                   
