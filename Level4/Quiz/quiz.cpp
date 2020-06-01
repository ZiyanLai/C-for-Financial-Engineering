/*
 * fileName:          quiz.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-05-31
 * @lastModifiedDate: 2020-05-31
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/
#include <iostream>
using namespace std;
int x=10;

namespace
{
  int x=20;
}

int main(int x, char* y[])
{
  {
    int x=30;
    std::cout<<::x<<std::endl;
  }
  return 0;
}