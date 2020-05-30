//
//  main.cpp
//  1.5.1
//
//  Created by Ziyan Lai on 5/27/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//

#include <stdio.h>

double minus(double num1, double num2){
    return num1 - num2;
}

int main() {
    double res;
    double num1 = 20;
    double num2 = 5;
    res = minus(num1, num2);
    printf("Result is: %.1f\n", res);


    return 0;
}
