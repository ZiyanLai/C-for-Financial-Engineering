/*
 * fileName:          main.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-02
 * @lastModifiedDate: 2020-06-02
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

#include <iostream>
using namespace std;
class A{
private:
  int m_da;

public:
  A(int da): m_da(da) {}
  int GetA() { return m_da; }
  A& operator = (const A& source) { m_da=source.m_da; return *this; }
};
	
class B: public A
{
private:
  int m_db;

public:
  B(int da, int db): A(da), m_db(db) {}
  int GetB() { return m_db; }
  B& operator = (const B& source) { m_db=source.m_db; return *this; }
};

int main()
{
  B b1(10, 20); B b2(30, 40);
  b1=b2;
  std::cout<<b1.GetA()<<", "<<b1.GetB()<<std::endl;
  return 0;
}
