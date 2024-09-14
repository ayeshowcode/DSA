#include<iostream>
using namespace std;
int main()
{
    int a = 10;
    // int &r; this is not allowed we cannot just declare it we have to initialize it 
    int &r=a; // r is the name of the other variable 
    cout << a << endl;
    cout << r << endl;
    r++;
    cout << a << endl;
    cout << r << endl;

    a=123;
    cout << a << endl;
    cout << r << endl;

    int b=30;
    r=b;
    cout << a << endl;
    cout << r << endl;
    

}