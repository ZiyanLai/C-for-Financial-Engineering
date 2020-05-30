//
//  main.cpp
//  1.3.4
//
//  Created by Ziyan Lai on 5/27/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//

#include <stdio.h>

int main()
{
    int married;
    printf("If you are married, please input 1, else please input 0: \n");
    scanf("%d", &married);
    if (married == 0 || married == 1){
        printf("%s\n", married ?  "married" : "not married");
    }
    else{
        printf("Invalid input.\n");
    }
    return 0;
}
