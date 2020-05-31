//
//  main.cpp
//  1.4.4
//
//  Created by Ziyan Lai on 5/27/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//  Print two column with the temperature of Celsius and Fahrenheit respectively using for loop


#include <stdio.h>

int main() 
{
    double startFahrenheit = 0;     // initialize a start temperature in Fahrenheit
    double endFahrenheit = 300;     // initialize a end temperature in Fahrenheit
    double stepFahrenheit = 20;     // initialize a step increment in Fahrenheit
    double temperatureCelsius;      // declare a temperature in Celsius that corresponds to Fahrenheit

    // print out the column head text
    printf("%11s  %11s\n", "Celsius", "Fahrenheit");

    // for each current value in Fahrenheit
    for (double i = startFahrenheit; i <= endFahrenheit; i+= stepFahrenheit)
    {
        // calculate the corresponding current Celsius temperature
        temperatureCelsius = (5.0/9.0) * (i - 32);

        // print both temperature in Celsius and in Fahrenheit
        printf("%10.1f  %10.1f\n", temperatureCelsius, i);
    }
    return 0;
}
