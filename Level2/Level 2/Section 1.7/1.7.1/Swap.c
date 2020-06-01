//
//  main.c
//  1.7.1
//
//  Created by Ziyan Lai on 5/28/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//  Use pointer to swap the values between numbers

#include <stdio.h>


// implementation of the Swap function
void Swap(double* i, double* j)
// here we use pointers to operate on the actuall object, rather on their copies
{
    // create a copy of i's value and we will use later
    double copyI = *i;
    // assign the value of i with j
    *i = *j;
    // assign the value of j with the copied value of i
    *j = copyI;
}


int main() 
{
    // initialize two numbers
    double i = 123, j = 456;

    // print out the two numbers
    printf("i = %.1lf, j = %.1lf\n", i, j);

    // call the Swap fnuction to swap the values of these 2 numbers
    // here we pass in the reference of numbers so we don't swap the copy values
    Swap(&i, &j);

    // print out the value of the swapped numbers
    printf("Now i = %.1lf, j = %.1lf\n", i, j);

    return 0;
}


