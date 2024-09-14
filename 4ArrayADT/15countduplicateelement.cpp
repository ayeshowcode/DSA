#include<iostream>
using namespace std;
void findDuplicateFromUnsortedArray(int *arr,int size)
{
    for(int i =0; i< size-1; i++)
    {
        int count = 1;
           for(int j=i+1; j< size; j++)
           {
            if(arr[i]==arr[j])
            {
                count++;
                arr[j]=-1;
            }
           }
           if(count>1)cout << arr[i] << "appears" << count << "times" << endl;
    }
}
int main()
{
    int arr[]={8,3,6,4,6,5,6,8,2,7};
    findDuplicateFromUnsortedArray(arr, 10);
}