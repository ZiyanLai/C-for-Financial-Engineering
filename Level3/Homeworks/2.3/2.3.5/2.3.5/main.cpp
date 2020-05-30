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
    line1.ToString();

    double xCor1, yCor1;
    cout << "Please enter an X coordinate and a Y coordinate for point 1: " << endl;
    cin >> xCor1 >> yCor1;

    double xCor2, yCor2;
    cout << "Please enter an X coordinate and a Y coordinate for point 2: " << endl;
    cin >> xCor2 >> yCor2;

    Point P1(xCor1, yCor1);
    Point P2(xCor2, yCor2);

    Line line2(P1,P2);

    line2.ToString();

    double len = line2.Length();
    cout << "Line's length is " << len << endl;

    return 0;
}
