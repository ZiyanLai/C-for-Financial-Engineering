/*
 * fileName:          variantVisitors.hpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-07
 * @lastModifiedDate: 2020-06-07
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Header file of Variant Visitor, which inherit from boost::static_visitor<T> */

#ifndef VARIANT_VISITORS_HPP
#define VARIANT_VISITORS_HPP
#include <iostream>
#include <boost/variant/static_visitor.hpp>
#include "point.hpp"
#include "circle.hpp"
#include "line.hpp"
using namespace std;

class VariantVisitors : public boost::static_visitor<void>
{
private:
    double m_dx;    // X coordinate
    double m_dy;    // y coordinate

public:
    // default constructor
    VariantVisitors();
    
    // constructor that takes two values
    VariantVisitors(double xCor, double yCor);

    // copy constructor 
    VariantVisitors(const VariantVisitors& source);

    // destructor
    virtual ~VariantVisitors();

    // assignment operator
    VariantVisitors& operator = (const VariantVisitors& rhs);

    // overload operator to visit a Point
    void operator()(Point& p) const;

    // overload operator to visit a Line
    void operator()(Line& l) const;

    // overload opeartor to visit a Circle
    void operator() (Circle& c) const;

};

#endif