//
//  main.cpp
//  1.4.1
//
//  Created by Ziyan Lai on 5/27/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//  Use a do while loop to do the task

#include <stdio.h>

int main()
{
    char currentCharacter = NULL;   // initialize the current buffer character
    char prevCharacter = NULL;      // initialize the previous character inputted
    int numCharacter = 0;           // initialize number of character inputted
    int numWord = 0;                // initialize number of word inputted
    int numLine = 0;                // initialize number of new line inputted

    // aks the user to input
    printf("please input characters and hit CTRL + D to stop: \n");
    
    do
    {
        // because the do loop excecute at least once
        // check if current character exists at inception
        if (currentCharacter != 10 && currentCharacter!= 32 && currentCharacter)
        {
            numCharacter++;
        }

        // if the current is a space and the previous is not a space nor a new line
        // then there must be a word
        if (currentCharacter == 32 && prevCharacter != 32 && prevCharacter)
        {
            numWord++;
        }

        // if current is a new line
        if (currentCharacter == 10)
        {
            // if there is a previous character and it is not a space nor a new line
            // then there must be a word
            if (prevCharacter && prevCharacter != 10 && prevCharacter != 32)
            {
                numWord++;
            }
            // increment the number of new line
            numLine++;
        }

        // update the previous character to become the current character
        prevCharacter = currentCharacter;
    }

    // while not detecting ASCII 4, keep looping
    while( (currentCharacter = getchar()) != 4 && currentCharacter != EOF);

    // after the loop, check if the last input is a word
    if (prevCharacter && prevCharacter != 32 and prevCharacter != 10)
    {
        numWord++;
    }

    // print out the result
    printf("\nWords: %d, Characters: %d, New Lines: %d\n", numWord, numCharacter, numLine);
    return 0;
}

