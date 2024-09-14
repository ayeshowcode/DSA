#include<iostream>
using namespace std;
void insert(int *Arr, int length, int elem)
{
    int index=length-1;
    while(Arr[index]>elem)
    {
        Arr[index+1]=Arr[index];
        index--;
    }
    Arr[index+1]=elem;
    length++;
}
int main()
{
    int Arr[7]={1,2,3,4,5};
    insert(Arr, 5, 2);
    for(int i = 0; i< 7; i++)
    {
        cout << Arr[i] << " ";
    }
}