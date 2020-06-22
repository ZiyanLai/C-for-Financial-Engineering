#include <stdio.h>
#include <iostream>
using namespace std;

void DoSomething()
{
    int a;
    int b[3] = {4,2,1};
    double c = .78;
    int *d = &a;

    a = ++*b * 5 % 3;
    *(b+1) = c;
    *d = (*b)++ % 2 + *(b+1);
    //cout << *d << endl;  
    printf("%d", *d);   
}


int main(){
    DoSomething();
    return 0;

}
