//
//  main.cpp
//  1.3.2
//
//  Created by Ziyan Lai on 5/26/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//

#include <stdio.h>



int main()
{
    double height;
    double base;
    double surface;
    printf("Please input values of base and height: ");
    if(scanf("%lf %lf",  &height, &base)){
        if(height >= 0 && base >= 0)
        {
            surface = 0.5 * base * height;
            printf("The surface is: %lf \n", surface);
        }
        else
        {
            printf("Your input is invalid\n");
        }
    }
    else
    {
        printf("Input Error\n");
    }
    
    return 0;
}
