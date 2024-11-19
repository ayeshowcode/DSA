#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

class Heap
{
    int *arr;     // Pointer to the heap array
    int maxSize;  // Maximum size of the heap
    int heapSize; // Current number of elements in the heap

public:
    // Constructor
    Heap(int totSize)
    {
        heapSize = 0;
        maxSize = totSize;
        arr = new int[totSize];
    }

    // Helper functions
    int parent(int i)
    {
        return (i - 1) / 2;
    }
    int lchild(int i)
    {
        return (2 * i + 1);
    }
    int rchild(int i)
    {
        return (2 * i + 2);
    }

    // Core heap operations
    void insertKey(int x)
    {
        if (heapSize == maxSize)
        {
            cout << "Overflow: Could not insertKey" << endl;
            return;
        }
        heapSize++;
        int i = heapSize - 1;
        arr[i] = x;

        // Fix the max heap property if it is violated
        while (i != 0 && arr[parent(i)] < arr[i])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void increaseKey(int i, int newVal)
    {
        arr[i] = newVal;

        // Fix the max heap property
        while (i != 0 && arr[parent(i)] < arr[i])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    int removeMax()
    {
        if (heapSize <= 0)
            return INT_MIN;

        if (heapSize == 1)
        {
            heapSize--;
            return arr[0];
        }

        int root = arr[0];
        arr[0] = arr[heapSize - 1];
        heapSize--;

        maxHeapify(0);

        return root;
    }

    int removeMin()
    {
        if (heapSize <= 0)
            return INT_MAX; // No elements in the heap

        if (heapSize == 1)
        {
            heapSize--;
            return arr[0]; // Return the only element
        }

        // Extract the root (minimum element)
        int root = arr[0];
        arr[0] = arr[heapSize - 1]; // Replace root with the last element
        heapSize--;

        minHeapify(0); // Restore min heap property

        return root;
    }

    void deleteKey(int i)
    {
        increaseKey(i, INT_MAX); // Increase the key to the maximum value
        removeMax();             // Remove the maximum element
    }

    void maxHeapify(int i)
    {
        int l = lchild(i);
        int r = rchild(i);
        int largest = i;

        if (l < heapSize && arr[l] > arr[i])
            largest = l;
        if (r < heapSize && arr[r] > arr[largest])
            largest = r;

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            maxHeapify(largest);
        }
    }

    void minHeapify(int i)
    {
        int l = lchild(i);
        int r = rchild(i);
        int smallest = i;

        if (l < heapSize && arr[l] < arr[i])
            smallest = l;
        if (r < heapSize && arr[r] < arr[smallest])
            smallest = r;

        if (smallest != i)
        {
            swap(arr[i], arr[smallest]);
            minHeapify(smallest);
        }
    }

    void buildMaxHeap(int *inputArr, int size)
    {
        heapSize = size;
        for (int i = 0; i < size; i++)
        {
            arr[i] = inputArr[i];
        }

        for (int i = parent(size - 1); i >= 0; i--)
        {
            maxHeapify(i);
        }
    }

    void buildMinHeap(int *inputArr, int size)
    {
        heapSize = size;
        for (int i = 0; i < size; i++)
        {
            arr[i] = inputArr[i];
        }

        for (int i = parent(size - 1); i >= 0; i--)
        {
            minHeapify(i);
        }
    }

    // Utility functions
    int getMax()
    {
        return arr[0];
    }

    int curSize()
    {
        return heapSize;
    }

    void printHeap()
    {
        if (heapSize == 0)
        {
            cout << "Heap is empty." << endl;
            return;
        }

        cout << "Heap elements: ";
        for (int i = 0; i < heapSize; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Main function
int main()
{
    Heap h(15);

    cout << "Building max heap from array {7,1,6,2,5,9,10,2}..." << endl;
    int inputArr[] = {7, 1, 6, 2, 5, 9, 10, 2};
    h.buildMaxHeap(inputArr, 8);
    h.printHeap();

    cout << "Building min heap from array {7,1,6,2,5,9,10,2}..." << endl;
    h.buildMinHeap(inputArr, 8);
    h.printHeap();

    cout << endl
         << "Inserting 15 into the max heap..." << endl;
    h.insertKey(15);
    h.printHeap();

    cout << "The current max element is: " << h.getMax() << endl;

    return 0;
}