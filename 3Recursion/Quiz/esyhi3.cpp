#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;
class Solution
{
public:
    // int maxSubArray(vector<int> &nums)
    // {
    //     int sum;
    //     int max = INT_MIN;
    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         sum = 0;
    //         for (int j = i; j < nums.size(); j++)
    //         {
    //             sum += nums[j];
    //             if (sum > max)
    //                 max = sum;
    //         }
    //     }
    //     return max;
    // }
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0, maxi = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            sum += nums[i];
            maxi = max(maxi, sum);
            if (sum < 0)
                sum = 0;
        }
        return maxi;
    }
};

int main()
{
    vector<int> nums;
    // nums.push_back(-2);
    nums.push_back(1);
    // nums.push_back(-3);
    // nums.push_back(4);
    // nums.push_back(-1);
    // nums.push_back(2);
    // nums.push_back(1);
    // nums.push_back(-5);
    // nums.push_back(4);

    Solution s;
    cout << s.maxSubArray(nums);
}