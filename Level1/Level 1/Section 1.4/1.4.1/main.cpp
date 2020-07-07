//
//  main.cpp
//  1.4.1
//
//  Created by Ziyan Lai on 5/27/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//  Use a while loop to record the numer of character, word, and new line iputted

#include <stdio.h>

int main()
{
    char currentCharacter;          // declare the current buffer character
    char prevCharacter = NULL;      // initialize the previous character inputted
    int numCharacter = 0;           // initialize number of character inputted
    int numWord = 0;                // initialize number of word inputted
    int numLine = 0;                // initialize number of new line inputted

    // let the user start inputting character
    printf("please input characters and hit CTRL + D to stop: \n");

    // while not typing CTRL+D, keep inputting
    // ASCII 4 does not really work for me, so I added an additional condition of EOF
    while( (currentCharacter = getchar()) != 4 && currentCharacter != EOF)
    {
        // count the input as character if it is not a space not an new line
        if (currentCharacter != 10 && currentCharacter != 32)
        {
            numCharacter++;
        }

        // if there is a previous input that is not a space,
        // and the current input is a space, then there must be a previous word
        if (currentCharacter == 32 && prevCharacter != 32 && prevCharacter)
        {
            numWord++;
        }
        
        // if the ASCII value is 10, add as a new line
        if (currentCharacter == 10)
        {
            // if current is a new line and the previous is not a space nor a enter and previous exists
            // then there must be a new word
            if (prevCharacter && prevCharacter != 10 && prevCharacter != 32)
            {
                numWord++;
            }
            numLine++;
        }

        // update the current character to previous character
        prevCharacter = currentCharacter;
    
    }

    // after the loop, add the last input as a word
    // if the previous character exists and is not a space nor a new line
    if (prevCharacter && prevCharacter != 32 && prevCharacter != 10)
    {
        numWord += 1;
    }
    
    printf("\nWords: %d, Characters: %d, New Lines: %d\n", numWord, numCharacter, numLine);
    return 0;
}

