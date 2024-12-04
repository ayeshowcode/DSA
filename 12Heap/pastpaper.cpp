#include <iostream>
#include <cmath>
using namespace std;

// Class to represent a Drone with its coordinates and distance from origin.
class Drone
{
public:
    int x;
    int y;
    float distance;

    Drone()
    {
        this->x = 0;
        this->y = 0;
        this->distance = 0;
    }

    Drone(int x, int y)
    {
        this->x = x;
        this->y = y;
        this->distance = sqrt(x * x + y * y);
    }
};

// Heap class to represent a Max Heap.
class Heap
{
public:
    Drone *arr; // Array to store the heap.
    int size;   // Current size of the heap.

    Heap()
    {
        size = 0;             // Initialize heap size to 0.
        arr = new Drone[100]; // Allocate memory for the heap (max size 100).
    }

    // Function to print distances of all drones in the heap.
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Distances: " << arr[i].distance << endl;
        }
        cout << endl;
    }

    // Function to insert a new drone into the heap.
    void insert(Drone data)
    {
        arr[size] = data;
        size++;
        // Heapify up from the inserted position to maintain heap property.
        heapify_up(arr, size, size - 1);
    }

    // Function to delete the root (maximum element) from the heap.
    Drone Delete()
    {
        if (size == 0)
        {
            cout << "Heap is empty. Cannot delete!" << endl;
            return Drone(); // Return a default drone if heap is empty.
        }

        // Replace root with the last element and reduce heap size.
        Drone removed = arr[0];         // Store the root (max element).
        arr[0] = arr[size - 1];         // Replace root with the last element.
        size--;                         // Reduce the size of the heap.
        heapify_max_heap(arr, size, 0); // Heapify down from the root.

        return removed; // Return the removed drone.
    }

    // Function to heapify up from a given index (used for insertion).
    void heapify_up(Drone arr[], int n, int index)
    {
        while (index > 0)
        {
            int parent_idx = (index - 1) / 2; // Parent index for 0-based indexing.
            if (arr[parent_idx].distance < arr[index].distance)
            { // For max heap.
                swap(arr[parent_idx], arr[index]);
                index = parent_idx;
            }
            else
            {
                break;
            }
        }
    }

    // Function to heapify down from a given index (used for deletion).
    void heapify_max_heap(Drone arr[], int n, int index)
    {
        int largest = index;
        int left = 2 * index + 1;  // Left child for 0-based indexing.
        int right = 2 * index + 2; // Right child for 0-based indexing.

        if (left < n && arr[left].distance > arr[largest].distance)
        { // Check left child.
            largest = left;
        }
        if (right < n && arr[right].distance > arr[largest].distance)
        { // Check right child.
            largest = right;
        }

        if (largest != index)
        { // If the largest is not the root.
            swap(arr[index], arr[largest]);
            heapify_max_heap(arr, n, largest); // Recursively heapify the affected subtree.
        }
    }

    // Function to find the k largest drones and print them.
    void find_k_largest(int k)
    {
        if (k > size)
        {
            cout << "Error: k is larger than the number of elements in the heap!" << endl;
            return;
        }

        // Temporary array to store the k largest drones.
        Drone largestDrones[k];

        // Extract the k largest elements from the heap.
        for (int i = 0; i < k; i++)
        {
            largestDrones[i] = Delete();
        }

        // Print the k largest drones.
        for (int i = 0; i < k; i++)
        {
            cout << "Drone " << i + 1 << " : " << largestDrones[i].x << " " << largestDrones[i].y << endl;
        }

        // Reinsert the extracted elements back into the heap.
        for (int i = 0; i < k; i++)
        {
            insert(largestDrones[i]);
        }
    }
};

int main()
{
    // Create a heap.
    Heap h;

    // Insert drones into the heap.
    h.insert(Drone(1, 3));
    h.insert(Drone(2, -2));
    h.insert(Drone(5, 8));
    h.insert(Drone(0, 1));
    h.insert(Drone(7, 6));

    // Find and print the 2 largest drones.
    h.find_k_largest(2);

    return 0;
}