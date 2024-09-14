#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // int maxProduct(vector<int> &nums)
    // {
    //     int n = nums.size();
    //     if (n == 0)
    //         return 0;

    //     int maxProd = nums[0];
    //     int minProd = nums[0];
    //     int result = nums[0];

    //     for (int i = 1; i < n; i++)
    //     {
    //         if (nums[i] < 0)
    //             swap(maxProd, minProd);

    //         maxProd = max(nums[i], maxProd * nums[i]);
    //         minProd = min(nums[i], minProd * nums[i]);

    //         result = max(result, maxProd);
    //     }
    //     return result;
    // }
    int maxProduct(vector<int> &nums)
    {
        int prefix=1, suffix=1;
        int maxi=INT_MIN;
        for (int i = 0; i< nums.size(); i++)
        {
            if(prefix==0)prefix=1;
            if(suffix==0)suffix=1;

            prefix*=nums[i];
            suffix*=nums[nums.size()-i-1];
            maxi= max(maxi, max(prefix,suffix));
        }
        return maxi;
    }
};

int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(-3);
    arr.push_back(3);

    Solution s;
    cout << s.maxProduct(arr);
}

/*
[2,3,-2,4]
maxprod=2
minprod=2
result=2

3<0 NO swap
maxprod = max(2,2*3) = 6
minprod= min(2, 2*3) = 2
result=(2,6)=6



-2<0 YES SWAP:
minprod=2
maxprod=6

maxprod(-2, 6*-2)= -2
minprod(-2, 2*-2)= -2



*/