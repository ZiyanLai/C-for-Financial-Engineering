//
//  main.cpp
//  quiz
//
//  Created by Ziyan Lai on 5/28/20.
//  Copyright © 2020 Ziyan Lai. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
//#define sqr(x) (x * x)
//
//int main()
//{
//  printf("%.2f, ", sqr(10.0));
//  printf("%.2f\n", sqr(10.0-5.0));
//}
// int main(){
// //    char str[10];
// //    int i;
// //    char* p;
// //    p = str;
// //    cout << "Please input: " << endl;
// //    scanf("%9s %9d", str, &i);
// //    printf("%s", str);
// //
//     int* ip;
//     *ip=10;
//     printf("%d\n", ip);
    
    
//     #define sqr(x) (x * x)
//     #define PI 3.1415
//     #define MAX 256
    
//     printf("%.2f, ", sqr(10.0));
//     printf("%.2f\n", sqr(10.0-5.0));
    
    
//     int upperbound = MAX - 1; int two = 2;
//     printf("The value of pi is: %f\n", PI); printf("Upperbound is: %d\n", upperbound); printf("The square of 2 is: %f\n", sqr(2.0));
//     // Some erroneous ways of using the ‘sqr’ macro (for example, // squaring a character produces a result!)
//     printf("Square of 3? %d\n", sqr(++two));
//     printf("Square of character a is :%d\n", sqr('a'));
    


    

//     return 0;
// }

union Name
{
  char firstName[10];
  char lastName[10];
};

int main()
{
  union Name name;
  strcpy(name.firstName, "Dennis");
  strcpy(name.lastName, "Ritchie");
  printf("%ld", sizeof(name));

  int (*arr2)[5];
}