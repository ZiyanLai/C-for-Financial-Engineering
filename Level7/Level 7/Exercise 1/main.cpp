/*
 * fileName:          main.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-06
 * @lastModifiedDate: 2020-06-06
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* STL Containers */

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main()
{   
    // test List
    cout << "\nNow testing List:" << endl;

    // initialize a list of double
    list<double> doubleList;
    for (int i = 0; i < 10; ++i)
    {
        // push elements into the list
        doubleList.push_back(i);
    }
    // print the front and back element
    cout << "the first element in the double List is: " << doubleList.front() << "\nthe last element in the double List is: " << doubleList.back() << endl;





    // test Vector
    cout << "\nNow testing Vector:" << endl;

    // initialize a numer of elements 
    int numElem = 10;
    // initialize a vector of double
    vector<double> doubleVector;
    for (int i = 0; i < numElem; ++i)
    {
        // push elements into the vector
        doubleVector.push_back(i + 0.5);
    }
    // print the first and the last element using index operator
    cout << "the first element in the double Vector is: " << doubleVector[0] << "\nthe last element in the double Vector is: " << doubleVector[9] << endl;
    // print the capacity and size of the vector
    cout << "the capacity of the Vector is: " << doubleVector.capacity() << "; the size of the Vector is: " << doubleVector.size() << endl;
    
    // continue to add elements and see if the size increases
    cout << "Now continue to push doubles into the vector;\n";
    // continue to push element to see if the size will grow
    doubleVector.push_back(10); 
    doubleVector.push_back(11);
    // print the added elements
    cout << "the 11th element is: " << doubleVector[10] << "\nthe 12th element is: " << doubleVector[11] << endl;

    // print the new capacity and size of the vector
    cout << "now the capacity of the Vector is: " << doubleVector.capacity() << "; the size of the Vector is: " << doubleVector.size() << endl;





    // Test Map
    cout << "\nNow testing Map:" << endl;

    // initialize a map of key with type string and value with type double
    map<string, double> myMap;
    // initialize a key list of string
    string str[5] = {"a", "b", "c", "d", "e"};

    // fill the map
    for (int i = 0; i != 5; ++i)
    {
        myMap[str[i]] = i + 0.5;
    }

    // access the map using square bracket
    for (int i = 0; i != myMap.size(); ++i)
    {
        // print the key and its corresponding value
        cout << "Key: " << str[i] << ", Value: " << myMap[str[i]] << endl;
    }

    return 0;
}