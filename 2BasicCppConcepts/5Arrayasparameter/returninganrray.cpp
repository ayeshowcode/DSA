#include<iostream>
using namespace std;
int *fun(int size)
{
    int *p;
    p=new int[size];
    for(int i = 0; i<size; i++)
    {
        p[i]=i+1;
    }
    return p;

}
int main()
{
    int *p;
    p=fun(5);
    for(int i =0; i<5; i++)
    {
        cout << p[i] << " ";
    }
    return 0;
}