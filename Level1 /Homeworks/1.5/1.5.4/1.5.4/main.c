//
//  main.c
//  1.5.4
//
//  Created by Ziyan Lai on 5/27/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//

#include <stdio.h>


void printnumber(int n){
    if (n < 0){
        putchar('-');
        putchar(10);
        n = -n;
    }
    if (n / 10 == 0){
        putchar(n + 48);
        putchar(10);
        return;
    }
    printnumber(n/10);
    putchar(n % 10 + 48);
    putchar(10);
}


int main() {
    int n;
    printf("Please input a integer: \n");

    scanf("%d", &n);
    printnumber(n);
    return 0;
}


