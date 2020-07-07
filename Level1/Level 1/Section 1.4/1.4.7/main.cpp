//
//  main.cpp
//  1.4.6
//
//  Created by Ziyan Lai on 5/27/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//  Extend the last program by showing the frequency of 3 recorded in words

#include <stdio.h>

int main() 
{
    char input;     // declare the input varaible as char
    int num0 = 0;   // number of 0
    int num1 = 0;   // number of 1
    int num2 = 0;   // number of 2
    int num3 = 0;   // number of 3
    int num4 = 0;   // number of 4

    // ask the user to input numbers
    printf("Please input numbers from 0 to 4, and hit CTRL + Z to stop:\n");

    // while ^Z (EOF) has not been typed:
    while ((input = getchar()) != EOF)
    {
        switch(input)
        {
            // '0' been typed
            case '0':
                // increment 0 counter
                num0++;
                // break current switch 
                break;

            // '1' been typed
            case '1':
                // increment 1 counter
                num1++;
                // break current switch
                break;

            // '2' been typed
            case '2':
                // increment 2 counter
                num2++;
                // break current switch 
                break;

            // '3' been typed
            case '3':
                // increment 3 counter
                num3++;
                // break current swtich
                break;
            
            // '4' been typed
            case '4':
                // increment 4 counter
                num4++;
                // break current switch
                break;
        }
    }
    
    // add switch for the occurence of 3
    switch(num3)
    {
        // if num3 equals to 0
        case 0:
            printf("\nNumber three appreas zero time.\n");
            // break the switch
            break;

        // if num3 equals to 1
        case 1:
            printf("\nNumber three appreas one time.\n");
            // break the switch
            break;
        // if num3 equals to 2
        case 2:
            printf("\nNumber three appreas two times.\n");
            //break the swtich
            break;

        // add a default case to detect if the num3 is more than 2
        default:
            printf("\nNumber three appreas more than two times.\n");
            // break the swtich
            break;
    }
    return 0;
}
