//
//  main.c
//  1.6.2
//
//  Created by Ziyan Lai on 5/28/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//

#include <stdio.h>
#include "Defs.h"

int main() {
    double x, y, z, res;
    printf("Please input three numbers and then press enter: \n");
    scanf("%lf %lf %lf", &x, &y, &z);
    res = MAX3(x,y,z);
    
    printf("The biggest number is: %.2lf\n", res);
    return 0;
}
