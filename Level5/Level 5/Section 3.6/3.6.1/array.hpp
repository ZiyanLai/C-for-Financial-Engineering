/*
 * fileName:          array.hpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-03
 * @lastModifiedDate: 2020-06-03
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Add functionality to throw exceptions */


#ifndef ARRAY_HPP
#define ARRAY_HPP 
#include "point.hpp"
using namespace std;

// define out Array class
class Array
{
private:    
    // Private member datas
    Point* m_data;          // array to store Point on heap
    unsigned int m_size;    // size of the array
public:
    // Default Constructor
    Array();

    // Constructor that takes a value of size
    Array(const unsigned int size);

    // Copy Constructor
    Array(const Array& anotherA);

    // Desctructor
    ~Array();
    
    // Assignment Operator
    Array& operator = (const Array& rhs);

    // Getter of the size of Array
    unsigned int Size() const;

    // Setter of the element in Array
    // here we assume the index can be negative integer
    void SetElement(int index, const Point& newP);

    // Getter of the element in Array
    // here we assume the index can be negative integer
    const Point& GetElement(int index) const;

    // index operator to get element in Array
    // here we assume the index can be negative integer
    Point& operator [] (int index);

    // const version of index operator to get element in Array
    // here we assume the index can be negative
    const Point& operator [] (int index) const;

};

#endif