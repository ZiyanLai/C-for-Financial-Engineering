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
    printf("Please input:\n");
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
    
    switch(num3){
        case 0:
            printf("\nNumber three appreas zero time\n");
            break;
        case 1:
            printf("\nNumber three appreas one time\n");
            break;
        case 2:
            printf("\nNumber three appreas two times\n");
            break;
        default:
            printf("\nNumber three appreas more than two times\n");
            break;
    }
    return 0;
}
