//
//  main.cpp
//  2.3.1
//
//  Created by Ziyan Lai on 5/29/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//


#include "point.hpp"

int main(){
    double xCor1, yCor1;
    std::cout << "Please enter an X coordinate and a Y coordinate for point 1: " << std::endl;
    std::cin >> xCor1 >> yCor1;
    
//    Point p1;
//    p1.SetX(xCor1);
//    p1.SetY(yCor1);
    Point p1(xCor1, yCor1);
    
    p1.ToString();
    std::cout << "X coordinate is: " << p1.GetX() << ", Y coordiante is: " << p1.GetY() << std::endl;
//    std::cout << "Distance from origin to point 1 is: " << p1.DistanceOrigin() << "\n" <<std::endl;
    
    double xCor2, yCor2;
    std::cout << "Please enter an X coordinate and a Y coordinate for point 2: " << std::endl;
    std::cin >> xCor2 >> yCor2;
    
//    Point p2;
//    p2.SetX(xCor2);
//    p2.SetY(yCor2);
    Point p2(xCor2, yCor2);
    double distance = p1.Distance(p2);
    std::cout << "Distance from point 1 to point 2 is: " << distance << std::endl;

    return 0;
}

// Before adding the copy constructor and the constructor that takes value:
// There were 2 constructor calls and 3 descturcor calls. This means when calling the 'Distance' function, the value of point is copied by value (since the Distance function is pass in by value), and we got a copy constructor for free when we do not define one.

// Now:
// The copy constructor is called once.
// The constructor that takes value is called 2 times.
// The destructor is called 3 times.
// The total number of constructor calls and destructor calls are the same.
