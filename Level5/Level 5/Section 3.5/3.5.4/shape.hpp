/*
 * fileName:          shape.hpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-03
 * @lastModifiedDate: 2020-06-03
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Add pure virtual Draw() function */

#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <iostream>
#include "stdlib.h"
#include <sstream>
using namespace std;

class Shape
{
private:
    int m_id;   // Shape's ID

public:
    // Default Constructor
    Shape();

    // Copy Constructor
    Shape(const Shape& anotherS);

    // virtual Destructor
    virtual ~Shape();

    // Assignment Operator
    Shape& operator = (const Shape& source); 

    // virtual function to display the ID
    virtual string ToString() const;

    // Getter to get thr ID
    int ID() const;

    // Draw function 
    // virtual void Draw();     // since Shape's Draw() is just and concept,
                                // we set it to pure virtual
    virtual void Draw() const = 0;

};

#endif