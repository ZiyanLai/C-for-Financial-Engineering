//
//  main.c
//  1.8.1
//
//  Created by Ziyan Lai on 5/28/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//  Create a struct and then print out its members

#include <stdio.h>
#include <string.h>
// avoid multiple inclusion
#ifndef LENGTH
#define LENGTH 20   // MACRO define a max length for the description
#endif

// implementation of the struct
struct Article
{
    int ArticleNumber;          // define the variable for article number. Here I assume the number could be negative for some reason
    unsigned int Quantity;      // define the variable for an non-negative quantity. 
    char Description[LENGTH];   // define a string of length 20 
};

// implementation of the function to print out the attributes
void print(struct Article* art)
{
    // print out the arrtibutes using -> to assess members of structer pointer
    printf("This article's number is: %d\nquantity is: %u\nand its description is: %s\n", art->ArticleNumber, art->Quantity, art->Description);
};

int main() 
{
    // define a struct
    struct Article article;

    // assign values to each member of this struct
    article.ArticleNumber = 3;
    article.Quantity = 5;
    char description[LENGTH] = "A good article!";
    // use the strcpy to copy the string over into the Description member  
    strcpy(article.Description, description);

    // call the print function to print out the results
    // here we pass in the address of the article 
    print(&article);
    
    return 0;
}