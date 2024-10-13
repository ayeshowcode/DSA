#include <iostream>
using namespace std;

int partition(int A[], int l, int h) {
    int pivot = A[l];  // Use the first element as the pivot
    int i = l + 1;     // Start i from the element next to pivot
    int j = h;         // Start j from the last element

    while (true) {
        // Move i to the right until you find an element greater than pivot
        while (i <= h && A[i] <= pivot) {
            i++;
        }
        // Move j to the left until you find an element smaller than or equal to pivot
        while (j >= l && A[j] > pivot) {
            j--;
        }
        // If i and j cross, break the loop
        if (i >= j) {
            break;
        }
        // Swap A[i] and A[j]
        swap(A[i], A[j]);
    }
    // Swap pivot element with A[j] (final position of the pivot)
    swap(A[l], A[j]);
    return j;  // Return the partition index
}

void quickSort(int A[], int l, int h) {
    if (l < h) {
        int j = partition(A, l, h);  // Partition the array
        quickSort(A, l, j - 1);      // Sort left partition
        quickSort(A, j + 1, h);      // Sort right partition
    }
}

int main() {
    int size = 8;
    int* A = new int[size]{1, 9, 2, 4, 3, 5, 6, 8};

    quickSort(A, 0, size - 1);  // Use size - 1 for correct range

    // Print the sorted array
    for (int i = 0; i < size; i++) {
        cout << A[i] << " ";
    }

    delete[] A;  // Free allocated memory
    return 0;
}
