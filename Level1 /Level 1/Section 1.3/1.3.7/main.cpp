//
//  main.cpp
//  1.3.7
//
//  Created by Ziyan Lai on 5/27/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//  Perform multiplication on a number by a factor 2 to the power n

#include <iostream>

int main() 
{
    long input = 5;      // initialize a number to be multiplied
    long power_n = 3;    // initialize the power 
    long result;         // declare the result

    // calculate the result with right shift operator
    result = input << power_n;

    // print out the result
    printf("%ld times 2 to the power of %ld is %ld. \n", input, power_n, result);
    return 0;
}
