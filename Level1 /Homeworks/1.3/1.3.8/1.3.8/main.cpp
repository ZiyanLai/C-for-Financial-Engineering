//
//  main.cpp
//  1.3.8
//
//  Created by Ziyan Lai on 5/27/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//

#include <stdio.h>
int main()
{
    int x = 2;
    int y;
    int z;
    x *= 3 + 2;
    printf("x=%d\n", x); // 10
    x *= y = z = 4;
    printf("x=%d\n", x); // 40
    x = y == z;
    printf("x=%d\n", x); // 1
    return 0;
    
}
