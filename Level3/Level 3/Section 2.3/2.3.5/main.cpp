//
//  main.cpp
//  2.3.5
//
//  Created by Ziyan Lai on 5/30/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//

#include "line.hpp"
#include "point.hpp"
#include <iostream>
using namespace std;

int main() 
{
    // initialize a Line with default constructor
    Line line1;
    // print the line1 
    cout << "\nline1 (created by the default constructor): ";
    cout << line1.ToString() << endl;

    // initialize X and Y coordinates for Point P1
    double xCor1, yCor1;
    // ask for user input
    cout << "\nPlease enter an X coordinate and a Y coordinate for point 1: " << endl;
    // read user input
    cin >> xCor1 >> yCor1;

    // initialize X and Y coordinates for Point P2
    double xCor2, yCor2;
    // ask for user input
    cout << "Please enter an X coordinate and a Y coordinate for point 2: " << endl;
    // read user input
    cin >> xCor2 >> yCor2;

    // initialize P1 and P2
    Point P1(xCor1, yCor1);
    Point P2(xCor2, yCor2);

    // initialize Line line2 with the two points 
    Line line2(P1,P2);
    // print line2
    cout << "\nline2: (created by constructor that takes values with the previous two points)\n";
    cout << line2.ToString() << endl;

    // initialize Line line3 with copy constructor by copying line2
    Line line3(line2);
    cout << "\nline3: (created with copy constructor by copying line2)\n";
    cout << line3.ToString() << endl;

    // use Length() function to calculate the length of line2
    double len2 = line2.Length();
    // print line2's length
    cout << "\nLine 2's length is " << len2 << endl;

    // use Length() function to calculate the length of line2
    double len3 = line3.Length();
    // print line3's length
    cout << "Line 3's length is " << len3 << endl;

    return 0;
}
