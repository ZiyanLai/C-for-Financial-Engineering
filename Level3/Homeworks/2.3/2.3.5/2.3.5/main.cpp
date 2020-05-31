//
//  main.cpp
//  2.3.5
//
//  Created by Ziyan Lai on 5/30/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//

#include "line.hpp"

int main() {
    
    Line line1;
    cout << "line1 (created by the default constructor): ";
    line1.ToString();

    double xCor1, yCor1;
    cout << "\nPlease enter an X coordinate and a Y coordinate for point 1: " << endl;
    cin >> xCor1 >> yCor1;

    double xCor2, yCor2;
    cout << "\nPlease enter an X coordinate and a Y coordinate for point 2: " << endl;
    cin >> xCor2 >> yCor2;

    Point P1(xCor1, yCor1);
    Point P2(xCor2, yCor2);

    Line line2(P1,P2);
    cout << "\nline2: ";
    line2.ToString();

    Line line3(line2);
    cout << "\nline3 (created by copy constructor to copy line2 to line3): ";
    line3.ToString();

    double len2 = line2.Length();
    cout << "Line 2's length is " << len2 << endl;

    double len3 = line3.Length();
    cout << "Line 3's length is " << len3 << endl;

    return 0;
}
