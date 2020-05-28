//
//  main.cpp
//  1.4.1
//
//  Created by Ziyan Lai on 5/27/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//

#include <stdio.h>

int main(){
    char c;
    char prevC = NULL;
    int numChar = 0;
    int numWord = 0;
    int numLine = 0;
    printf("please input: ");
    while( (c = getchar()) != 4 && c != EOF){
        if (c != 10 && c != 32){
            numChar++;
        }
        
        if (c == 32 && prevC != 32 && prevC){
            numWord++;
        }
        
        if (c == 10){
            numLine++;
        }
        prevC = c;
    
    }
    if (prevC != 32){
        numWord += 1;
    }
    
    printf("\nWords: %d, Characters: %d, New Lines: %d\n", numWord, numChar, numLine);
    return 0;
}

