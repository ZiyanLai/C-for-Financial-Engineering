//
//  main.cpp
//  1.3.6
//
//  Created by Ziyan Lai on 5/27/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//  Perform logical shift on an integer by two places to the right 

#include <stdio.h>

int main() 
{
    int originalNumber; // declare the original number
    int shiftedNumber;  // declare the shifted number

    // ask the user to input a integer
    printf("Please input an integer: ");

    // read the input integer 
    scanf("%d", &originalNumber);

    // use the right shift operator to shift the number 
    shiftedNumber = originalNumber >> 2;

    // print out both the original number and the shifted number 
    printf("Original number: %d, Shifted number: %d \n", originalNumber, shiftedNumber);

    // use the ternary operator to determine whether the input is being shifted
    printf("%s \n", originalNumber != shiftedNumber ? "Shifted" : "Not Shifted");
    return 0;
}
