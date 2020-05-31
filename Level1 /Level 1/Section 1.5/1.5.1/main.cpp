//
//  main.cpp
//  1.5.1
//
//  Created by Ziyan Lai on 5/27/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//  Calculate the regular difference between 2 numbers

#include <stdio.h>

// define finction that returns the regular difference 
double minus(double num1, double num2){
    return num1 - num2;
}

int main() 
{
    double result;                          // declare a variable tha stores result
    double num1 = 20;                       // initialzie number 1
    double num2 = 5;                        // initialize numebr 2
    result = minus(num1, num2);             // call "minus" function to calculate the difference
    printf("%.1f minus %.1f is: %.1f\n", num1, num2, result);    // print out the result
    return 0;
}
