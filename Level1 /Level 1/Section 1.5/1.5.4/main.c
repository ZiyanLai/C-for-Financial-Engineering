//
//  main.c
//  1.5.4
//
//  Created by Ziyan Lai on 5/27/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//  Recursive function print a integer digit by digit

#include <stdio.h>

// implementation of the recursive function 
void printnumber(int n)
{
    if (n < 0) // handle negative number 
    {   
        putchar('-');     // print a negative sign
        putchar(10);      // print next line
        n = -n;           // set the number to positive
    }
    if (n / 10 == 0)      // base case that now the number is single digit
    {
        putchar(n + 48);  // print the digit in decimal
        putchar(10);      // print next line
        return;
    }
    
    printnumber(n/10);    // recurse

    putchar(n % 10 + 48); // print digits of resursive calls

    putchar(10);          // print next line
}


int main() 
{   
    // declare a integer number
    int number;                             

    // ask the user to input this integer
    printf("Please input a integer: \n");   

    // read the input
    scanf("%d", &number);   

    // call the recursive function to print digit by digit
    printnumber(number);
    
    return 0;
}


