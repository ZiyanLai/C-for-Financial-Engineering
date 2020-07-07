//
//  main.cpp
//  1.3.8
//
//  Created by Ziyan Lai on 5/27/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//  Predict what will be printed with the assignment operator

#include <stdio.h>
int main()
{
    int x = 2;
    int y;
    int z;
    x *= 3 + 2;
    printf("x=%d\n", x); // x=10
    x *= y = z = 4;
    printf("x=%d\n", x); // x=40
    x = y == z;
    printf("x=%d\n", x); // x=1
    return 0;
    
}
