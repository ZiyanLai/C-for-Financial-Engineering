/*
 * fileName:          array.hpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-03
 * @lastModifiedDate: 2020-06-03
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Add static function to Setter and Getter of default size */


#ifndef ARRAY_HPP
#define ARRAY_HPP 
#include "outOfBoundException.hpp"
#include "differentSizeException.hpp"
using namespace std;

// declare a template for Array class
template <typename T>

// define Array class
class Array
{
private:    
    // Private member datas
    T* m_data;                          // array to store T on heap
    unsigned int m_size;                // size of the array
    static unsigned int m_defaultSize;  // default size of Array

public:
    // static function to Set the default array size
    static void DefaultSize(unsigned int defaultSize);

    // static function to Get the default array size
    static unsigned int DefaultSize();

    // Default Constructor
    Array();

    // Constructor that takes a value of size
    Array(unsigned int size);

    // Copy Constructor
    Array(const Array<T>& anotherA);

    // Desctructor
    virtual ~Array();
    
    // Assignment Operator
    Array<T>& operator = (const Array<T>& source);

    // Getter of the size of Array
    unsigned int Size() const;

    // Setter of the element in Array
    // here we assume the index can be negative integer
    void SetElement(int index, const T& newP);

    // Getter of the element in Array
    // here we assume the index can be negative integer
    const T& GetElement(int index) const;

    // index operator to get element in Array
    // here we assume the index can be negative integer
    T& operator [] (int index);

    // const version of index operator to get element in Array
    // here we assume the index can be negative
    const T& operator [] (int index) const;

    

};
#ifndef ARRAY_CPP
#include "array.cpp"    // By doing this, we can make sure to include the array.cpp source file 
#endif                  // even if the user forget to include it and only include the array.hpp header file
                        // in the main() program.
#endif