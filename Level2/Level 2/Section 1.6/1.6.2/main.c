//
//  main.c
//  1.6.2
//
//  Created by Ziyan Lai on 5/28/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//  Use MACRO to compare different variables

#include <stdio.h>
#include "Defs.h"

int main() 
{
    // define three variables to be used and a 'res' variable to store the result
    double x, y, z, res;

    // ask the user to input numbers
    printf("Please input three numbers and then press enter: \n");

    // read the input
    scanf("%lf %lf %lf", &x, &y, &z);

    // assign the result value to the variable
    res = MAX2(x,y);

    // print the biggest number between X and Y 
    printf("The biggest number between %.2lf, %.2lf is: %.2lf\n", x, y, res);

    // re-assign the new result value to the variable
    res = MAX3(x,y,z);
    
    // print the biggest number between X, Y, Z 
    printf("The biggest number between %.2lf, %.2lf, %.2lf is: %.2lf\n", x, y, z, res);
    return 0;
}
