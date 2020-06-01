//
//  main.c
//  1.9.1
//
//  Created by Ziyan Lai on 5/28/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//  Display the user input once they hit Enter

#include <stdio.h>
#include <string.h>
// avoid multiple inclusion
#ifndef MAXLEN
// MACRO define a max length for the array
#define MAXLEN 1000
#endif

// helper function to print part of the string, given a start index and an end index
void print(int array[], int startInd, int endInd)
{
    // print out each character between the given start index and end index
    for (int i = startInd; i<= endInd; ++i)
    {
        // print the current character
        putchar(array[i]);
        // print a space in between
        putchar(' ');
    }
    // after printed the current sub-string, print a new line
    putchar('\n');
}

int main() 
{
    int c;              // initialize a buffer variable to store user's input character
    int array[MAXLEN];  // initialize an array to store all the user's input
    int ind = 0;        // initialize a master index to track the end point of the array
    int startInd = 0;   // initialize a start index that will be updated once the user hits Enter

    // ask the user to input
    printf("Please start input characters and hit CTRL + A to stop: \n");
    // while the user does not hit Enter
    while ((c = getchar() )!= 1)
    {
        // if the user hit Enter
        if (c == 10)
        {
            // call the print function to print out the characters from now till the last time the user hit Enter
            print(array, startInd, ind-1);
            // update the start index to the current index
            startInd = ind;
            // go to the next iteration
            continue;
        }

        // if the input is not a space not a tab
        if (c != 32 && c != 9)
        {
            // put the actual character into the array
            array[ind] = c;
            // increment the master index
            ind++;
        }
    }

    // After the user has entered CTRL + A, print out a message to indicate this is the correct ending
    printf("CTRL + A is a correct ending.\n");
    return 0;
}


