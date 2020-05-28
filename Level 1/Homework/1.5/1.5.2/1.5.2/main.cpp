//
//  main.cpp
//  1.5.2
//
//  Created by Ziyan Lai on 5/27/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//

#include <stdio.h>


int factorial(int n){
    if (n == 1){
        return 1;
    }
    return n * factorial(n-1);
}

int main() {
    int res;
    int n = 5;
    res = factorial(n);
    printf("Result is %d. \n", res);
    return 0;
}
