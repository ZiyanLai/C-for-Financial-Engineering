//
//  main.cpp
//  1.4.1
//
//  Created by Ziyan Lai on 5/27/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//  Using a switch & case to to the task

#include <stdio.h>

int main()
{
    char currentCharacter;          // declare the current buffer character
    char prevCharacter = NULL;      // initialize the previous character inputted
    int numCharacter = 0;           // initialize number of character inputted
    int numWord = 0;                // initialize number of word inputted
    int numLine = 0;                // initialize number of new line inputted

    // ask the user the input 
    printf("please input characters and hit CTRL + D to stop: \n");

    // while CTRL + D is not detected
    // ASCII 4 does not work for me, so I added EOF
    while( (currentCharacter = getchar()) != 4 && currentCharacter != EOF){

        // add switch cases
        switch(currentCharacter){

            // if current character is a space
            case 32:
                // if previous is not a space and previous exists, then there must be a word
                if (prevCharacter != 32 && prevCharacter){
                    numWord++;
                }
                break;
            
            // if current character is a new line
            case 10:
                // if there is a previous character and it is not a space nor a new line
                // then there must be a word
                if (prevCharacter && prevCharacter != 32 && prevCharacter != 10){
                    numWord++;
                }
                // increment line number when detected 10
                numLine++;
                break;

            // if current character is not a new line nor a space
            // then by default, it must be a character
            default:
                numCharacter++;
                break;
        }
        // update previous character to be the current one
        prevCharacter = currentCharacter;
    }
    
    // after the loop, determine if the last input is a word
    if (prevCharacter && prevCharacter != 32 && prevCharacter != 10){
        numWord += 1;
    }
    
    // print out the result
    printf("\nWords: %d, Characters: %d, New Lines: %d\n", numWord, numCharacter, numLine);
    return 0;
}

