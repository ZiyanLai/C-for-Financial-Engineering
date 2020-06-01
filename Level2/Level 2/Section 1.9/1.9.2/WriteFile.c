//
//  main.c
//  1.9.1
//
//  Created by Ziyan Lai on 5/28/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//  Modify the last script to write the output into a file

#include <stdio.h>
#include <string.h>
// avoid multiple inclusion
#ifndef MAXLEN
// MACRO define a max length for the array
#define MAXLEN 1000
#endif
// MACRO define a max length for the name of the file
#ifndef MAXNAME
#define MAXNAME 20
#endif

// define a helper function to write the output into a file
void writeToFile(int array[], int startInd, int endInd, char filename[])
{
    // initialize a FILE pointer handle
    FILE* fp;

    // define the type of operation
    // in this case we want to append to the existing file and create one if there is no file
    fp = fopen(filename, "a+");

    // handle the error
    if (fp == NULL)
    {
        // print out an error message
        printf("Failed to open file");
    }
    // for each character in the given section of the array
    for (int i = startInd; i<= endInd; ++i)
    {
        // write them one by one and seperate with a space
        fputc(array[i], fp);
        // seperate characters with a space
        fputc(' ', fp);
    }
    // after we are done with the current section of the array
    // print a new line
    fputc('\n', fp);

    // close the file
    fclose(fp);
}


int main() 
{
    int c;                  // initialize a buffer variable to store user's input character
    int array[MAXLEN];      // initialize an array to store all the user's input
    int ind = 0;            // initialize a master index to track the end point of the array
    int startInd = 0;       // initialize a start index that will be updated once the user hits Enter
    char filename[MAXNAME]; // initialize a variable to store the file name
    
    // ask the user to input a file name
    printf("Please input the file name without typing '.txt': ");
    // read the input
    scanf("%s", filename);
    // create a buffer for the file name
    strcat(filename, ".txt");
    
    // ask the user to start input the characters
    printf("Please start input characters and hit CTRL + A to stop: \n");
    // while the user has not hit CTRL + A
    while ((c = getchar() )!= 1)
    {
        // if the user hit Enter
        if (c == 10)
        {
            // write the current portion of input into the file
            writeToFile(array, startInd, ind-1, filename);
            // update the start index to be the current index
            startInd = ind;
            // go to the next iteration
            continue;
        }
        // if the current character is not a space nor a tab
        if (c != 32 && c != 9)
        {
            // store the actual character into the array
            array[ind] = c;
            // increment the master index
            ind++;
        }
    }
    // After the user has entered CTRL + A, print out a message to indicate this is the correct ending
    printf("CTRL + A is a correct ending.\n");
    return 0;
}


