//
//  main.cpp
//  1.3.6
//
//  Created by Ziyan Lai on 5/27/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//

#include <stdio.h>

int main() {
    int i;
    int shifted;
    printf("Please input an integer: ");
    scanf("%d", &i);
    shifted = i >> 2;
    printf("Input number: %d, Output number: %d \n", i, shifted);
    printf("%s \n", i != shifted ? "shifted" : "not shifted");
    return 0;
}
