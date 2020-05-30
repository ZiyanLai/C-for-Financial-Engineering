//
//  main.cpp
//  1.3.5
//
//  Created by Ziyan Lai on 5/27/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//

#include <stdio.h>

int main()
{
    int i = 10;
    int j = --i;
    
    i = 10;
    int k = i--;
    printf("j = %d\nk = %d\n", j, k);
    return 0;
}
