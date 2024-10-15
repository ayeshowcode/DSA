#include <iostream>
#include <cstdlib> // For rand() function
#include <ctime>   // For seeding random numbers
using namespace std;

// Partition function with the ability to select different pivot strategies
int partition(int A[], int l, int h, const string &pivotType)
{
    int pivotIndex;

    // Select the pivot based on the specified strategy
    if (pivotType == "first")
    {
        pivotIndex = l; // First element as pivot
    }
    else if (pivotType == "last")
    {
        pivotIndex = h; // Last element as pivot
    }
    else if (pivotType == "middle")
    {
        pivotIndex = l + (h - l) / 2; // Middle element as pivot
    }
    else if (pivotType == "random")
    {
        pivotIndex = l + rand() % (h - l + 1); // Random element as pivot
    }
    else
    {
        cout << "Invalid pivot type!" << endl;
        exit(1); // Exit if the pivot type is incorrect
    }

    // Swap the chosen pivot with the first element
    swap(A[l], A[pivotIndex]);
    int pivot = A[l];

    int i = l + 1, j = h;

    while (true)
    {
        while (i <= h && A[i] <= pivot)
            i++; // Move i right
        while (j >= l && A[j] > pivot)
            j--; // Move j left

        if (i >= j)
            break;        // If i and j cross, exit the loop
        swap(A[i], A[j]); // Swap A[i] and A[j]
    }

    swap(A[l], A[j]); // Place pivot in its correct position
    return j;         // Return the partition index
}

// QuickSort function with pivot type as parameter
void quickSort(int A[], int l, int h, const string &pivotType)
{
    if (l < h)
    {
        int j = partition(A, l, h, pivotType); // Partition the array
        quickSort(A, l, j - 1, pivotType);     // Sort left partition
        quickSort(A, j + 1, h, pivotType);     // Sort right partition
    }
}

int main()
{
    srand(time(0)); // Seed random number generator

    int size = 8;
    int *A = new int[size]{1, 9, 2, 4, 3, 5, 6, 8};

    // Change the pivot type here: "first", "last", "middle", "random"
    quickSort(A, 0, size - 1, "random");

    // Print the sorted array
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    delete[] A; // Free allocated memory
    return 0;
}
