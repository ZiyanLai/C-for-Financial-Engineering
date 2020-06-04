/*
 * fileName:          line.hpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-01
 * @lastModifiedDate: 2020-06-01
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Add Line class into namespace ZiyanLai::CAD */

#ifndef LINE_HPP
#define LINE_HPP
#include "point.hpp"
using namespace std; 

namespace ZiyanLai
{
    namespace CAD
    {
        class Line
        {
        private:
            Point p1; // Start Point    
            Point p2; // End Point
        public:
            // Default Constructor
            Line(); 

            // Constructor takes value
            Line(const Point& startP, const Point& endP);   

            // Copy Constructor
            Line(const Line& anotherLine);                  
            
            // Destructor
            ~Line();                                        

            // Assignment Operator
            Line& operator = (const Line& anotherLine);     

            // Getter for start point 
            const Point& startPoint() const;                       

            // Getter for end point
            const Point& endPoint() const;                         

            // Setter for start point 
            void startPoint(const Point& anotherP);           

            // Setter for end point
            void endPoint(const Point& anotherP);           

            // Function to display the attributes of line
            string ToString() const;                          
            
            // Function to calculate the length of line
            double Length() const;                          

        };
        ostream& operator << (ostream& os, const Line& l); // Ostream operator 
    }
}
#endif