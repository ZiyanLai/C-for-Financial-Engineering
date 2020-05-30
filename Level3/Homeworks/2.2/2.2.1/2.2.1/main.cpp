//
//  main.cpp
//  2.2.1
//
//  Created by Ziyan Lai on 5/29/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//


#include "point.hpp"

int main(){
    double xCor, yCor;
    std::cout << "Please enter an X coordinate and a Y coordinate: " << std::endl;
    std::cin >> xCor >> yCor;
    Point p;
    p.SetX(xCor);
    p.SetY(yCor);
    p.ToString();
    std::cout << "X coordinate is: " << p.GetX() << ", Y coordiante is: " << p.GetY() << std::endl;

    return 0;
}
