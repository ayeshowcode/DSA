#include <iostream>
#include <vector>
using namespace std;
int binarySearch(vector<int> nums, int target)
{
    int ans = -1;
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (target < nums[mid])
        {
            high = mid - 1;
        }
        else if (target > nums[mid])
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
    }

    return ans; // Target not found
}
// recursively
int RBinarySearch(int *A, int low, int high, int key, int size)
{
    int mid;

    if (low <= high)
    {
        mid = (low + high) / 2;
        if (key == A[mid])
            return mid;
        else if (key < A[mid])
            return (A, low, mid - 1, key, size);
        else if (key > A[mid])
            return (A, mid + 1, high, key, size);
    }
    return -1;
}
int main()
{
    vector<int> A = {1, 2, 3, 4, 5, 6};
    int key = 2;
    int size = 6;

    int res = binarySearch(A, key);
    if (res != -1)
        cout << "found at index: " << res;
    else
        cout << "not found";

    cout << endl;
    // int res2 = RBinarySearch(A, 0, size - 1, key, size);
    // if (res2 != -1)
    //     cout << "found at index: " << res;
    // else
    //     cout << "not found";
}

/*
low = 0
high = 5
mid = 0+5/2=2
6>3 low = mid -- low = 3

mid = 2+5/2 = 3
6>4=low = 3

mid = 3+5/2=4
6>5 low = 4

mid = 4+5/2=4
6>5 low =

*/