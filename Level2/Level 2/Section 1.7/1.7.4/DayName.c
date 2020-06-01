//
//  main.c
//  1.7.4
//
//  Created by Ziyan Lai on 5/28/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//  Print the day with its cooresponding number

#include <stdio.h>

int main() 
{
    // initialize an non-negative number for the user input to represent a day
    unsigned int num;

    // create an array of string to hard code all the week day's name
    // an array of string is actually a matrix of char
    char day[7][15] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    // ask the user to input
    printf("Please input a number between 1 and 7 to indicate a day: \n");
    // read the input
    scanf("%u", &num);

    // print the equivalent week day
    printf("The number you put is equivalent to %s.\n", day[num-1]);
    return 0;
}
