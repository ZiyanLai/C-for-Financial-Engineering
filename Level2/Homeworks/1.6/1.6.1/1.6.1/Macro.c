//
//  Macro.c
//  1.6.1
//
//  Created by Ziyan Lai on 5/28/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//

#include "Defs.h"
#include <stdio.h>


int main(){
    int a;
    char b;

    printf("Please first input a number then a character, seperated by space. And then please press enter: \n");
    scanf("%d %c", &a, &b);
    
    PRINT1(a);
    
    PRINT2(a, b);
    
    return 0;
}
