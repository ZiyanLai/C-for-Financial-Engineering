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
#ifndef MAXNAME
#define MAXNAME 20
#endif

void writeToFile(int array[], int startInd, int endInd, char filename[]){
    FILE* fp;
    fp = fopen(filename, "a+");
    if (fp == NULL){
        printf("Failed to open file");
    }
    for (int i = startInd; i<= endInd; ++i){
        fputc(array[i], fp);
        fputc(' ', fp);
    }
    fputc('\n', fp);
    fclose(fp);
}


int main() {
    int c;
    int array[MAXLEN];
    int ind = 0;
    int startInd = 0;
    char filename[MAXNAME];
    
    printf("Please input the file name without typing '.txt': ");
    scanf("%s", filename);
    strcat(filename, ".txt");
    
    printf("Please start input characters: \n");
    while ((c = getchar() )!= 1){
        if (c == 10){
            writeToFile(array, startInd, ind-1, filename);
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


