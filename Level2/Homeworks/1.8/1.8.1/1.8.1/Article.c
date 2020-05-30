//
//  main.c
//  1.8.1
//
//  Created by Ziyan Lai on 5/28/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define LENGTH 20

struct Article{
    int ArticleNumber;
    int Quantity;
    char Discription[LENGTH];
};

void print(struct Article* art){
    printf("This article's number is: %d\nquantity is: %d\nand its discription is: %s\n", art->ArticleNumber, art->Quantity, art->Discription);
};

int main() {
    struct Article a;
    a.ArticleNumber = 3;
    a.Quantity = 5;
    char discription[LENGTH] = "A good article!";
    strcpy(a.Discription, discription);
    print(&a);
    
    return 0;
}
