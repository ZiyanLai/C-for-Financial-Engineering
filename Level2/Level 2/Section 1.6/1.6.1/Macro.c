//
//  Macro.c
//  1.6.1
//
//  Created by Ziyan Lai on 5/28/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//  Print the variables using MACRO
//  This is the main function that defines variables and call the MACRO

#include "Defs.h"
#include <stdio.h>


int main()
{
    int a;  // define the first variable 'a' as an int
    char b; // define the second variable 'b' as an char

    // ask the user the type in inputs
    printf("Please first input a number then a character, seperated by space. And then please press enter: \n");
    // read the user's input
    scanf("%d %c", &a, &b);
    
    // call the MACRO to print a
    PRINT1(a);
    
    // call the MACRO to print a and b
    PRINT2(a, b);
    
    return 0;
}
