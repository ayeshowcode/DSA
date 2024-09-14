#include<iostream>
using namespace std;
int LinearSearch(int *A, int key, int size)
{
    for (int i = 0; i< size; i++)
    {
        if (A[i]==key)
        return i;
    }
        return -1;
}
int main()
{
    int A[5]={1,2,3,4,5};
    int size = 5;
    int key=2;
    
    int res=LinearSearch(A, key, size);
    if(res!=-1) cout << "found at index: " << res;
    else cout << "not found";
}