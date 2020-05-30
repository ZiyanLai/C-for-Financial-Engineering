//
//  main.c
//  1.7.1
//
//  Created by Ziyan Lai on 5/28/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//

#include <stdio.h>


void Swap(double* i, double* j){
    double copyI = *i;
    *i = *j;
    *j = copyI;
}


int main() {
    double i = 123, j = 456;
    printf("i = %.1lf, j = %.1lf\n", i, j);
    Swap(&i, &j);
    printf("Now i = %.1lf, j = %.1lf\n", i, j);

    return 0;
}


