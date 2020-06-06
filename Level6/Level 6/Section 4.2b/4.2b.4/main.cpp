/*
 * fileName:          main.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-03
 * @lastModifiedDate: 2020-06-03
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Test the Stack class */
#include <iostream>
#include "array.cpp"
#include "stack.hpp"
#include "point.hpp"
#include "shape.hpp"
#include "arrayException.hpp"
using namespace std;

int main()
{
    // test default constructor
    Stack<int> stack0;
    // test constructor that takes a size value
    Stack<int> stack1(2);
    // test Push function
    cout << "Push integer 4 \n";
    stack1.Push(4);
    cout << "Push integer 5 \n";
    stack1.Push(5);


    // test Pop function
    // cout << stack1.Pop() << endl;

    // test exception handeling
    try
    {
        // now the Stack is full
        // try to push when the index not valid
        cout << "try to push another integer\n";
        stack1.Push(3);
    }
    catch(ArrayException& ae)
    {
        cout << ae.GetMessage();
    }
    
    // pop the 2 integers in the stack
    cout << "Pop element " << stack1.Pop() << endl;
    cout << "Pop element " << stack1.Pop() << endl;

    // now the stack is empty
    try
    {
        // try to Pop an empty stack
        // meaning that the index is not valid
        cout << "try to pop another integer\n";
        stack1.Pop();
    }
    catch(ArrayException& ae)
    {
        cout << ae.GetMessage();
    }

    // test other Types
    Stack<Point> pointStack(2);
    Point p1(1,1);
    Point p2(2,2);

    // push Point objects into the Point Stack
    cout << "Push Point with " << p1 << endl;
    pointStack.Push(p1);

    cout << "Push Point with" << p2 << endl;
    pointStack.Push(p2);

    // pop Point objects and print
    cout << "Pop Point with " << pointStack.Pop() << endl;
    cout << "Pop Point with " << pointStack.Pop() << endl;

    return 0;
}
