//
//  main.c
//  1.9.1
//
//  Created by Ziyan Lai on 5/28/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#ifndef MAXLEN
#define MAXLEN 1000
#endif

void print(int array[], int startInd, int endInd){
    for (int i = startInd; i<= endInd; ++i){
        putchar(array[i]);
        putchar(' ');
    }
    putchar('\n');
}

int main() {
    int c;
    int array[MAXLEN];
    int ind = 0;
    int startInd = 0;
    printf("Please start input characters: \n");
    while ((c = getchar() )!= 1){
        if (c == 10){
            print(array, startInd, ind-1);
            startInd = ind;
            continue;
        }
        if (c != 32){
            array[ind] = c;
            ind++;
        }
    }
    printf("CTRL + A is a correct ending.\n");
    return 0;
}


