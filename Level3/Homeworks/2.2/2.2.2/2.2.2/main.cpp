//
//  main.cpp
//  2.2.2
//
//  Created by Ziyan Lai on 5/29/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//


#include "point.hpp"

int main(){
    double xCor1, yCor1;
    std::cout << "Please enter an X coordinate and a Y coordinate for point 1: " << std::endl;
    std::cin >> xCor1 >> yCor1;
    
    Point p1;
    p1.SetX(xCor1);
    p1.SetY(yCor1);
    p1.ToString();
    std::cout << "X coordinate is: " << p1.GetX() << ", Y coordiante is: " << p1.GetY() << std::endl;
    std::cout << "Distance from origin to point 1 is: " << p1.DistanceOrigin() << "\n" <<std::endl;
    
    double xCor2, yCor2;
    std::cout << "Please enter an X coordinate and a Y coordinate for point 2: " << std::endl;
    std::cin >> xCor2 >> yCor2;
    
    Point p2;
    p2.SetX(xCor2);
    p2.SetY(yCor2);
    
    double distance = p1.Distance(p2);
    std::cout << "Distance from point 1 to point 2 is: " << distance << std::endl;

    return 0;
}
