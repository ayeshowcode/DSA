#include<iostream>
using namespace std;
int countzeros(int n, int x)
{
    if(n==0) return x;
    if(n%10==0) 
    return countzeros(n/10, x+1);
    else return countzeros(n/10, x);
}
int main()
{
    cout << countzeros(101010000, 0);
}