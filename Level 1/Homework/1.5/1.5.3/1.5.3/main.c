//
//  main.c
//  1.5.3
//
//  Created by Ziyan Lai on 5/27/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//

#include <stdio.h>

double multiplyByTwo(int i);

int main() {
    double i;
    printf("Please input a number:\n");
    scanf("%lf", &i);
    multiplyByTwo(i);
    return 0;
}
