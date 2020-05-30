//
//  main.c
//  1.7.4
//
//  Created by Ziyan Lai on 5/28/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//

#include <stdio.h>

int main() {
    int i;
    char day[7][15] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    printf("Please input a number between 1 and 7 to indicate a day: \n");
    scanf("%d", &i);
    printf("The number you put is equivalent to %s\n", day[i-1]);
    return 0;
}
