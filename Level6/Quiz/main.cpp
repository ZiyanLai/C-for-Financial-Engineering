/*
 * fileName:          main.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-04
 * @lastModifiedDate: 2020-06-04
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

#include <iostream>

class EA {};
class EB: public EA {};

void F()
{
  throw EB();
}

int main()
{
  try
  {
    F();
  }
  catch(EA&)
  {
    std::cout<<"EA Exception"<<std::endl;
  }
  catch(EB&)
  {
    std::cout<<"EB Exception"<<std::endl;
  }

  std::cout<<"Finished"<<std::endl;

  return 0;
}