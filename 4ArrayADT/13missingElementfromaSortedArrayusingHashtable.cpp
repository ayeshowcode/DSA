#include<iostream>
using namespace std;
void printElements(int *arr, int size, int low, int high)
{
    
    int hash[12]={0};
    for(int i=0; i<size; i++)
    {
         hash[arr[i]]++;
    }

    for(int i = low; i<=high; i++)
    {
        if(hash[i]==0)
        cout << i<< " ";
    }
}
int main()
{
    int arr[12]={3,7,4,9,12,6,1,11,2,10};
    printElements(arr, 6, 1, 12);
}