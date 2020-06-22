/*
 * fileName:          quiz.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-18
 * @lastModifiedDate: 2020-06-18
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

#include <stdio.h>
int main()
{
    int a=0, b=0;

    if (a<b) a=10; b=20;

    printf("%d, %d\n", a, b);

     int x=4.6;
    printf("%d\n", x);

    double y = 5.6;
    printf("%d\n", y);

    

    int i=0;
    while (i<2);
    {
    printf("%d ", i);
    }
}

// int main()
// {
//   int i=2; int j=4;
//   printf("%d^%d=%d\n", i, j, Power(i,j));
// }

// int Power(int a, int b)
// {
//   int result=a;
//   for (int i=1; i!=b; i++) result*=a;
//   return result;
// }