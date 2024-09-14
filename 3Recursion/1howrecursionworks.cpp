#include<iostream>
using namespace std;

void func1(int x)
{
    if(x>0)
    {
        cout << x << " ";
        func1(x-1);
    }
}

void func2(int x)
{
    if(x>0)
    {
        func2(x-1);
        cout << x << " ";
    }
}
int main()
{
    func1(3);
    cout << endl;
    func2(3);
}