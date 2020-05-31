//
//  Main.c
//  1.5.3
//
//  Created by Ziyan Lai on 5/27/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//  Multiply a number by 2 and print it out

#include <stdio.h>

// foward declaration of the function
double multiplyByTwo(int input);

int main() 
{
    double input;                         // declare a varaible input
    printf("Please input a number:\n");   // ask the user to input a number
    scanf("%lf", &input);                 // read the user input 
    multiplyByTwo(input);                 // call the function to calculate and print the result
    return 0;
}
