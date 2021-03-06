//
//  def.h
//  1.6.1
//
//  Created by Ziyan Lai on 5/28/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//  This is the header file that includes the MACRO implementation

#ifndef DEFS_H
#define DEFS_H

// avoid multiple inclusion
#ifndef PRITN1
// define MACRO to print a variable
#define PRINT1(var) printf("%d\n", var)
#endif

// avoid multiple inclusion
#ifndef PRINT2
// define MACRO to print both variables
#define PRINT2(var1, var2) printf("%d %c\n", var1, var2)
#endif


#endif 
