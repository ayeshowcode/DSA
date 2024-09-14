#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> nums3(m+n);
        int i = 0, j = 0, k = 0;
        while(i< m && j< n)
        {
           if(nums1[i]<nums2[j]) nums3[k++]=nums1[i++];
           else nums3[k++]=nums2[j++];
        }
        //atleast one (may be more) element from either the nums1 or nums2 is/are remaining
        while(i< m)
        {
            nums3[k++]=nums1[i++];
        }
        while(j< n)
        {
            nums3[k++]=nums2[j++];
        }
        return nums3;
    }
};
int main()
{
    vector<int> num1;
    num1.push_back(3);
    num1.push_back(4);
    num1.push_back(5);
    num1.push_back(6);
    num1.push_back(10);

    vector<int> num2;
    num2.push_back(2);
    num2.push_back(4);
    num2.push_back(5);
    num2.push_back(7);
    num2.push_back(12);
    
    Solution s;
    vector<int> num3= s.merge(num1, 5, num2, 5);
    for(int i = 0; i<10; i++)
    cout << num3[i] << " ";
}