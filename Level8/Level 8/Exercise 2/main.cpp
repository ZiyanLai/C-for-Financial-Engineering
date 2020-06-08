/*
 * fileName:          main.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-07
 * @lastModifiedDate: 2020-06-07
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

#include <iostream>
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <string>
using namespace std;



// define a tuple consisting of string, int, double as a type Person
typedef boost::tuple<string, int, double> Person;


// helper function to print out the element in Person
void PrintTuple(const Person& aPerson)
{
    // retrive the first element
    string name = aPerson.get<0>();
    
    // retrive the second element
    int age = aPerson.get<1>();
    
    // retrive the third element
    double length = aPerson.get<2>();

    // print out the values in the tuple
    cout << "This person's name is " << name << ", age is " << age << ", and length is " << length << endl;
}


int main()
{   
    // create 3 instances of type Person 
    Person personA(string("Bob"), 25, 178.5);
    Person personB(string("Amy"), 32, 167.2);
    Person personC(string("Jack"), 65, 175.3);

    // for each Person, call the PrintTuple function to print out the values inside
    PrintTuple(personA);
    PrintTuple(personB);
    PrintTuple(personC);

    // Change values inside the tuple
    cout << "Now Bob has grown older, " << endl;
    // use the same get function to change the value
    personA.get<1>() = 27;
    // print out the new value
    cout << "Bob's age is now " << personA.get<1>() << endl;


    return 0;
}

