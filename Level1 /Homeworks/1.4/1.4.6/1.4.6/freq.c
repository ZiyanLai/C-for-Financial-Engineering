//
//  main.cpp
//  1.4.6
//
//  Created by Ziyan Lai on 5/27/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//

#include <stdio.h>

int main() {
    char c;
    int num0 = 0;
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    int num4 = 0;
    printf("Please input numbers from 0 to 4:\n");
    while ((c=getchar()) != EOF){
        switch(c){
            case '0':
                num0++;
                break;
            case '1':
                num1++;
                break;
            case '2':
                num2++;
                break;
            case '3':
                num3++;
                break;
            case '4':
                num4++;
                break;
        }
    }
    printf("number of 0: %d\nnumber of 1: %d\nnumber of 2: %d\nnumber of 3: %d\nnumber of 4: %d\n", num0, num1, num2, num3, num4);
    return 0;
}
