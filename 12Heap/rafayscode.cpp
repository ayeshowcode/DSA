#include <iostream>
#include <iomanip>
using namespace std;

class Heap
{
public:
    int *arr;
    int size;
    int capacity;

    Heap(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;
        this->arr = new int[capacity];
    }
    void insert(int data)
    {
        if (size == capacity)
        {
            cout << "Heap is full\n";
            return;
        }
        arr[size] = data;
        int index = size++;

        while (index >= 0 && arr[index] > arr[(index - 1) / 2])
        {
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }
    void heapify(int i)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && arr[left] > arr[largest])
        {
            largest = left;
        }
        if (right < size && arr[right] > arr[largest])
        {
            largest = right;
        }
        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }
    int getMax()
    {
        if (size == 0)
        {
            cout << "Heap is empty\n";
            return -1;
        }
        int data = arr[0];
        swap(arr[0], arr[size - 1]);
        size--;
        heapify(0);
        return data;
    }

    void buildHeap()
    {
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(i);
        }
    }

    void heapSort()
    {
        buildHeap();
        int SIZE = size;
        for (int i = size - 1; i > 0; i--)
        {
            swap(arr[0], arr[i]);
            size--;
            heapify(0);
        }
        size = SIZE;
    }

    ~Heap()
    {
        delete[] arr;
    }
};