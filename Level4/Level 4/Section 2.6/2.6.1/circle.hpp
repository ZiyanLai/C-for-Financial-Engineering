/*
 * fileName:          circle.hpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-01
 * @lastModifiedDate: 2020-06-01
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Add Circle class into namespace ZiyanLai::CAD */

#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include <iostream>
#include "point.hpp"
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

namespace ZiyanLai
{
    namespace CAD
    {
        class Circle{
        private:
            Point center;
            double m_radius;

        public:
        //  Default Constructor
            Circle(); 

        //  Constructor that take value
            Circle(const Point& cent, const double& rad); 

        //  Copy Constructor
            Circle(const Circle& anotherC); 

        //  Destructor
            ~Circle(); 

        //  Assignment Operator
            Circle& operator = (const Circle& anotherC);

        //  Getter of the center
            Point CenterPoint() const; 

        //  Getter of the radius
            double Radius() const; 

        //  Setter of the center
            void CenterPoint(const Point& anotherP); 

        //  Setter of the radius
            void Radius(const double& anotherR); 

        //  Calculate the diameter
            double Diameter() const; 

        // Calculate the circumference 
            double Circumference() const;

        //  Calculate the area of circle
            double Area() const; 

        // Report the circle
            string ToString() const; 
            
        };
        ostream& operator << (ostream& os, const Circle& c); // Ostream operator 
    }
}
#endif