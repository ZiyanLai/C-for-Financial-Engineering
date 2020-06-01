//
//  main.c
//  1.7.2
//
//  Created by Ziyan Lai on 5/28/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//  Define function to return the length of a string

#include <stdio.h>
// avoid multiple inclusion
#ifndef MAXLINE
#define MAXLINE 30
#endif
// foward declaration of the function Length
int Length(char str[]);

int main()
{
    char string[MAXLINE + 1]; // Line of maxium 30 chars + \0
    int c;   // The input character
    int i = 0; // The counter

    // Print intro text
    printf("Type up to %d chars. Exit with ^Z\n", MAXLINE);
     // Get the characters
    while ((c = getchar())!= EOF && i < MAXLINE)
        {
            string[i++] = (char)c;
        }
    string[i] = '\0'; // String must be closed with \0
    printf("String length is %d\n", Length(string));
    return 0;
}

// implementation of the function that returns the length of string
int Length(char str[])
{
    // initialize an index variable
    int i = 0;               
    
    // initialize an variable to represent the length 
    // since the length can't be negative, we initialize the type to be unsigned
    unsigned int len = 0;

    // while the index has not reached the last element in the string
    while (str[i] != '\0'){
        len++;  // increment the length
        i++;    // increment the index
    }
    len -= 1;   // after the while loop, we need to decrement the length by 1
                // to get the correct actual string length
    return len;
}
