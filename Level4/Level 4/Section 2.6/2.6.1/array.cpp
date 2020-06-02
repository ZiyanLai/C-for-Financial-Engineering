/*
 * fileName:          array.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-01
 * @lastModifiedDate: 2020-06-01
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Add Array class into namespace ZiyanLai::Containers */

#include "array.hpp"
using namespace std;

namespace ZiyanLai
{
    namespace Containers
    {
        // Default Constructor to create an array of size 10
        Array::Array() : m_data(new CAD::Point[10]), m_size(10) {}

        // Constructor that takes a value of size 
        Array::Array(const unsigned int size) : m_data(new CAD::Point[size]), m_size(size) {}

        // Copy Constructor 
        Array::Array(const Array& anotherA)
        {   
            // copy over the size
            m_size = anotherA.m_size;
            // assign new array with copied size on heap
            m_data = new CAD::Point[m_size];
        
            // for each element in the another Array
            for (int i = 0; i < anotherA.m_size; i++)
            {
                // copy over each element
                m_data[i] = anotherA.m_data[i];
            }
        }

        // Destructor
        Array::~Array()
        {
            // free the memory allocated on heap, using [] syntax
            delete[] m_data;
        }

        // Assignment Operator
        Array& Array::operator = (const Array& rhs)
        {
            // if the right hand side is the Array itself
            if (this == &rhs)
            {
                // return the Array it self
                return *this;
            }
            // free up resources
            delete[] m_data;

            // make the size equals to the size of right hand side Array
            m_size = rhs.m_size;
            // allocate new array with the size equals to the right hand side Array
            m_data = new CAD::Point[m_size];
            
            // for each element in the right hand side Array
            for (int i = 0; i < rhs.m_size; i++)
            {
                // copy over the data into this Array
                m_data[i] = rhs.m_data[i];
            }
            // return the this Array
            return *this;
        }

        // Getter of the size of the Array
        unsigned int Array::Size() const
        {
            // return the member data m_size
            return m_size;
        }

        // Setter of the element in Array
        void Array::SetElement(int index, const CAD::Point& newP)
        {
            // if the index is out of bound
            if (index > m_size - 1)
            {
                // ignore this operation
                return;
            }
            // otherwise, return the corresponding Point 
            m_data[index] = newP;
        }

        // Getter of the element in Array
        CAD::Point& Array::GetElement(int index) const
        {   
            // if the index is out of bound
            if (index > m_size - 1)
            {
                // return the first Point in Array
                return m_data[0];
            }
            // otherwise, return the corresponding Point
            return m_data[index];
        }

        // index operator
        // here we return a reference of Point
        // so we allow both read and write of Point
        CAD::Point& Array::operator [] (int index)
        {
            // if index is out of bound
            if (index > m_size - 1)
            {
                // return the first element in the Array
                return m_data[0];
            }
            // otherwise return the corresponding Point
            return m_data[index];
        }

        // const version of index operator
        // here we return a const reference of Point and make the function const
        // the purpose is:
        // 1. restrict to read only
        // 2. allow to return by reference but not allow to change on the reference
        // 3. allow to operate on const Array type
        const CAD::Point& Array::operator [] (int index) const
        {
            // if the index is out of bound
            if (index > m_size - 1)
            {
                // return the first element in Array
                return m_data[0];
            }
            // otherwise, return the corresponding Point
            return m_data[index];
        }
    }
}