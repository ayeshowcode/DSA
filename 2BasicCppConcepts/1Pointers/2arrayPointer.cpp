#include<iostream>
using namespace std;
int main()
{
    int A[5]={2,4,6,8,10}; //created inside the stack frame
    int *p=A; // no need of &A because 'A' is pointing to the address of the first index though we can 
    // int *p=&A[0]; this is valid
    for(int i=0; i<5;i++)
    {
        cout << p[i] << " " ;
    }

}