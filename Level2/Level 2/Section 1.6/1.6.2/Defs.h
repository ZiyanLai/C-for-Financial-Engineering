//
//  Header.h
//  1.6.2
//
//  Created by Ziyan Lai on 5/28/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//  Header file that defines the MACRO of MAX2 and MAX3

#ifndef DEFS_H
#define DEFS_H

// handle multiple inclusion
#ifndef MAX2
// define the MACRO MAX2 that returns the max between 2 numbers
#define MAX2(x,y) ((x > y) ? x : y)
#endif

// handle multiple inclusion
#ifndef MAX3
// define the MACRO MAX3 that use MAX2 to return the max between 3 numbers
#define MAX3(x,y,z) ((MAX2(x,y) > z) ? MAX2(x,y) : z)
#endif

#endif 
