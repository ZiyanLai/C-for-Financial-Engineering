//
//  Header.h
//  1.6.2
//
//  Created by Ziyan Lai on 5/28/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//

#ifndef DEFS_H
#define DEFS_H

#ifndef MAX2
#define MAX2(x,y) ((x > y) ? x : y)
#endif

#ifndef MAX3
#define MAX3(x,y,z) ((MAX2(x,y) > z) ? MAX2(x,y) : z)
#endif

#endif /* Header_h */
