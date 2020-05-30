//
//  main.c
//  1.7.2
//
//  Created by Ziyan Lai on 5/28/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//

#include <stdio.h>
#define MAXLINE 30

int Length(char str[]);

int main(){
    char string[MAXLINE + 1]; // Line of maxium 30 chars + \0
    int c;   // The input character
    int i = 0; // The counter

    // Print intro text
    printf("Type up to %d chars. Exit with ^Z\n", MAXLINE);
     // Get the characters
    while ((c = getchar())!= EOF && i < MAXLINE)
        {
            string[i++] = (char)c;
        }
    string[i] = '\0'; // String must be closed with \0
    printf("String length is %d\n", Length(string));
    return 0;
}


int Length(char str[]){
    int i = 0;
    int len = 0;
    while (str[i] != '\0'){
        len++;
        i++;
    }
    len -= 1;
    return len;
}
