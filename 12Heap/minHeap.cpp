#include <iostream>
#include <limits.h>
using namespace std;

class MinHeap
{
    int *arr;     // Pointer to the heap array
    int maxSize;  // Maximum size of the heap
    int heapSize; // Current number of elements in the heap

public:
    // Constructor
    MinHeap(int totSize)
    {
        heapSize = 0;
        maxSize = totSize;
        arr = new int[totSize];
    }

    // Helper functions
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return (2 * i + 1); }
    int rightChild(int i) { return (2 * i + 2); }

    // Insert a new key
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

        // Fix the min-heap property
        while (i != 0 && arr[parent(i)] > arr[i])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    // Remove and return the minimum element (root)
    int extractMin()
    {
        if (heapSize <= 0)
            return INT_MAX;

        if (heapSize == 1)
        {
            heapSize--;
            return arr[0];
        }

        int root = arr[0];
        arr[0] = arr[heapSize - 1];
        heapSize--;

        minHeapify(0);

        return root;
    }

    // Fix the min-heap property
    void minHeapify(int i)
    {
        int l = leftChild(i);
        int r = rightChild(i);
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

    // Utility functions
    int getMin() { return heapSize > 0 ? arr[0] : INT_MAX; }

    void printHeap()
    {
        if (heapSize == 0)
        {
            cout << "Heap is empty." << endl;
            return;
        }

        cout << "Min-Heap elements: ";
        for (int i = 0; i < heapSize; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Main function for min-heap
int main()
{
    MinHeap minHeap(10);

    minHeap.insertKey(3);
    minHeap.insertKey(2);
    minHeap.insertKey(15);
    minHeap.insertKey(5);
    minHeap.insertKey(4);
    minHeap.insertKey(45);

    minHeap.printHeap();

    cout << "Min element extracted: " << minHeap.extractMin() << endl;
    minHeap.printHeap();

    cout << "Min element: " << minHeap.getMin() << endl;

    return 0;
}