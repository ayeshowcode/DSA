#include <iostream>
using namespace std;
void selectionsort(int arr[], int i, int j, int max)
{
    if (i == 0)
        return;
    if (i > j)
    {
        if (arr[j] > arr[max])
            selectionsort(arr, i, j + 1, j);
        else
            selectionsort(arr, i, j + 1, max);
    }
    else
    {
        int temp = arr[i-1];
        arr[i - 1] = arr[max];
        arr[max] = temp;
        selectionsort(arr, i - 1, 0, 0);
    }
}
int main()
{
    int arr[] = {1,3,2,5,6};
    selectionsort(arr, 5, 0, 0);
    for(int i=0; i < 5; i++)
    {
        cout << arr[i] << "";
    }
}