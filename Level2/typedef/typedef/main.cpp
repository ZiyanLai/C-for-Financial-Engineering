//
//  main.cpp
//  dsadsad
//
//  Created by Ziyan Lai on 5/28/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//

#include <iostream>
using namespace std;


int main() {
    typedef int array[4];
    array a1;
    array a2;
    
    a1[3] = 6;
    a2[0] = 7;
    
    int array1[4];
    array1[1] = 5;
//    array1 a3; // Compile Error
    
    cout << a1[3] << "," << array1[1] << endl;
    
    return 0;
}
