//
//  main.cpp
//  2.3.2
//
//  Created by Ziyan Lai on 5/29/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//


#include "point.hpp"

int main(){
    double xCor1, yCor1;
    std::cout << "Please enter an X coordinate and a Y coordinate for point 1: " << std::endl;
    std::cin >> xCor1 >> yCor1;
    

    Point p1(xCor1, yCor1);
    
    p1.ToString();
    std::cout << "X coordinate is: " << p1.GetX() << ", Y coordiante is: " << p1.GetY() << std::endl;
    
    double xCor2, yCor2;
    std::cout << "Please enter an X coordinate and a Y coordinate for point 2: " << std::endl;
    std::cin >> xCor2 >> yCor2;
    

    Point p2(xCor2, yCor2);
    double distance = p1.Distance(p2);
    std::cout << "Distance from point 1 to point 2 is: " << distance << std::endl;

    return 0;
}

// Now we have 2 constructor that takes value calls and 2 destructor calls, and no calls from the copy constructor.
// Also, we cannot modify the value from the argument in Distance, since the argument is const.
