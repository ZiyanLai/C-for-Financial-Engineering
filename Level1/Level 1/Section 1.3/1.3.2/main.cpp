//
//  main.cpp
//  1.3.2
//
//  Created by Ziyan Lai on 5/26/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//  Calculate the surface area of a triangle

#include <stdio.h>



int main()
{
    double height; // height of triangle 
    double base;   // base of triangle
    double surface; // surface of the triangle

    // ask the user to input values for the triangle
    printf("Please input values of base and height of your triangle: ");

    // check if the input is valid
    if(scanf("%lf %lf",  &height, &base))
    {   
        // check if the values are greater than 0
        if(height >= 0 && base >= 0)
        {
            // calculate the surface area if the inputs are valid 
            surface = 0.5 * base * height;
            // print out the output
            printf("The surface is: %lf \n", surface);
        }
        else
        {
            // print the error message if the input is not greater than 0 
            printf("Your input is invalid\n");
        }
    }
    else
    {
        // print the error message if the iput is not numbers 
        printf("Input Error\n");
    }
    
    return 0;
}
