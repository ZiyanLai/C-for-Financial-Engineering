//
//  main.cpp
//  1.5.2
//
//  Created by Ziyan Lai on 5/27/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//  Print the factorial of a number using recursion

#include <stdio.h>

// function that calculate the factorial using recursion
int factorial(int n)
{
    if (n == 1)
    {   
        return 1; // base case
    }
    return n * factorial(n-1);
}

int main() 
{
    int result;                             // declare a variable that stores result
    int number = 5;                         // initialize the number to calculate its factorial
    result = factorial(number);             // call the function to calculate
    printf("The factorial of %d is %d. \n", number, result);    // print out the result
    return 0;
}
