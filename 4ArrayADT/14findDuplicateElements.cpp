#include<iostream>
using namespace std;
void printDuplicateElement(int *arr, int size)
{
    int lastduplicate=0;
    for(int i = 0; i< size-1; i++)
    {
        if(arr[i]==arr[i+1]&&arr[i]!=lastduplicate)
        {
            cout << arr[i] << " " ;
            lastduplicate=arr[i];
        }
    }
}
void countDuplicateElements(int *arr, int size)
{
    int j = 0;
    for(int i = 0; i< size-1; i++)
    {
        if(arr[i]==arr[i+1])
        {
            j=i+1;
            while(arr[j]==arr[i])j++;
            cout << arr[i] << " appears " << j-i << " times"<< endl;
            i=j-1;
        }
    }
}
int main()
{
  int arr[8]={1,2,2,3,4,5,5,6};
  printDuplicateElement(arr, 8);
  cout << endl;
  countDuplicateElements(arr, 8);
}