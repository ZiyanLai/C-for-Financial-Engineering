//
//  main.cpp
//  1.3.4
//
//  Created by Ziyan Lai on 5/27/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//  Use ternary operator to generate output

#include <stdio.h>

int main()
{
    int married; // define variable to indicate whether married; 
                 // 0 means not married and 1 means married

    // take input from user
    printf("If you are married, please input 1, else please input 0: \n");

    // read the user input
    scanf("%d", &married);

    // check if the input is 0 or 1
    if (married == 0 || married == 1)
    {
        // use the ternary operator to print the result
        printf("%s\n", married ?  "married" : "not married");
    }
    // print error message if the input is not valid 
    else
    {
        printf("Invalid input.\n");
    }
    return 0;
}
