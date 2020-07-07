//
//  main.cpp
//  1.3.3
//
//  Created by Ziyan Lai on 5/27/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//  Predict the values that will be printed 




#include <stdio.h>

int main()
{
    int x;
    x=-3+4*5-6;
    printf("x=%d\n", x); // x=11
    
    x=3+4%5-6;
    printf("x=%d\n", x); // x=1
    
    x=-3*4%-6/5;
    printf("x=%d\n", x); // x=0
    
    x=(7+6)%5/2;
    printf("x=%d\n", x); // x=1

    return 0;
}

