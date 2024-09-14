#include<iostream>
using namespace std;
int main()
{
    int a=10;
    int *p;
    p=&a;

    cout << "deferencing: " << *p << endl;
    cout << "directly printning the address: " << &a << endl;
    cout << "p is pointing to the address of a: " << p << endl;
    // both will have same address
}