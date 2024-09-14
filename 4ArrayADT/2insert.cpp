#include<iostream>
using namespace std;
struct Array 
{
    int A[10];
    int size;
    int length;
};
void display(struct Array arr)
{
    for(int i = 0; i< arr.length; i++)
    cout << arr.A[i] << " ";
}
void insert(struct Array *arr,int index, int x)
{
    if(index>=0 && index<=arr->length)
    {
        for(int i=arr->length; i>index;i--)
        {
             arr->A[i]=arr->A[i-1];
        }
        arr->A[index]=x;
        arr->length++;
    }
}
int main()
{
    struct Array arr={{1,2,3,4,5},10,5};
    insert(&arr, 1,10);
    display(arr);
}