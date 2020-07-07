//
//  main.cpp
//  1.3.5
//
//  Created by Ziyan Lai on 5/27/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//  Showcase the difference between --i and i--

#include <stdio.h>

int main()
{
    int i = 10;     // intialize variable
    int j = --i;    // pre-decrement
    
    i = 10;         // reset the value of i
    int k = i--;    // post-decrement

    // print out the result to see the difference
    printf("j = %d\nk = %d\n", j, k);
    
    return 0;
}
