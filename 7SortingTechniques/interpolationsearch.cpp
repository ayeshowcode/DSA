#include<iostream>
using namespace std;

int interpolationSearch(int arr[], int n, int target) 
{
    int low = 0;
    int high = n - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) 
    {
        // Prevent division by zero if all elements in range are the same
        if (arr[low] == arr[high]) {
            if (arr[low] == target) return low;
            else break;
        }

        // Estimate the position of the target
        int pos = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        // If the target is found at the estimated position
        if (arr[pos] == target) 
        {
            return pos;
        }
        // If the target is greater, search the right side
        else if (arr[pos] < target) 
        {
            low = pos + 1;
        }
        // If the target is smaller, search the left side
        else 
        {
            high = pos - 1;
        }
    }

    return -1; // Target not found
}
int main()
{
    
}