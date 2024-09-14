#include <iostream>
#include<algorithm>
using namespace std;
void negonleftside(int *arr, int size)
{
    int i = 0;
    int j = size - 1;

    while (i < j)
    {
        while (arr[i] < 0)
            i++;
        while (arr[j] >= 0)
            j--;

        if (i < j)
            swap(arr[i], arr[j]);
    }
}
int main()
{
    int arr[5] = {1, -2, 3, 4, -5};
    negonleftside(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
}