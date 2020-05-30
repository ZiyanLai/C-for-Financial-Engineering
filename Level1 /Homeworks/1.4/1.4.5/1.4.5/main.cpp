//
//  main.cpp
//  1.4.4
//
//  Created by Ziyan Lai on 5/27/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//

#include <stdio.h>

int main() {
    double startF = 0;
    double endF = 300;
    double stepF = 20;
    double tempC;
    printf("%11s  %11s\n", "Celsius", "Fahrenheit");
    for (double i = startF; i <= endF; i+= stepF){
        tempC = (5.0/9.0) * (i - 32);
        printf("%10.1f  %10.1f\n", tempC, i);
    }
    return 0;
}
