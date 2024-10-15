#include <iostream>
using namespace std;

void bubbleSort(int arr[], int i, int j)
{
    if (i == 0) // Base case: when no more passes are needed
        return;

    if (i > j + 1) // Inner loop: compare and swap adjacent elements
    {
        if (arr[j] > arr[j + 1])
        {
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
        bubbleSort(arr, i, j + 1); // Move to the next pair
    }
    else // Outer loop: after completing a pass, reduce the problem size
    {
        bubbleSort(arr, i - 1, 0); // Restart from the beginning with a smaller array
    }
}

int main()
{
    int arr[] = {1, 4, 3, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n, 0);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
