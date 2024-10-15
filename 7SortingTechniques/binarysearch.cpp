#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) 
{
    int low = 0;
    int high = n - 1;

    while (low <= high) 
    {
        // Calculate the middle index
        int mid = low + (high - low) / 2;

        // Check if the target is at mid
        if (arr[mid] == target) 
        {
            return mid;
        }
        // If the target is greater, ignore the left half
        else if (arr[mid] < target) 
        {
            low = mid + 1;
        }
        // If the target is smaller, ignore the right half
        else 
        {
            high = mid - 1;
        }
    }

    return -1; // Target not found
}

int main()
{
    
}