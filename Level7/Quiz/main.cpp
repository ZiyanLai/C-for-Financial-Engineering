/*
 * fileName:          main.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-06
 * @lastModifiedDate: 2020-06-06
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

#include <iostream>
#include <vector>
using namespace std;
// Predicate determining if the value satisfies a criteria.
struct Predicate
{
	bool operator()(int v)
	{
		return (v%2)>0;
	}
};

int main()
{
	vector<int> v(5);
	v[0]=10; v[1]=14; v[2]=9; v[3]=15; v[4]=8;

	// Find the first number satisfying the given criteria.
	vector<int>::iterator result=find_if(v.begin(), v.end(), Predicate());
	cout<<"First number found: "<<*result<<endl;
}
