//
//  main.cpp
//  1.4.6
//
//  Created by Ziyan Lai on 5/27/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//  Using switch & case: 
//  Count how many times number from 0 - 4 has been typed and print it out

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
        // use switch to differentiate cases
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
    // print out the result of the occurence of each number 
    printf("number of 0: %d\nnumber of 1: %d\nnumber of 2: %d\nnumber of 3: %d\nnumber of 4: %d\n", num0, num1, num2, num3, num4);
    return 0;
}
