#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, int m, vector<int> &nums2, int n, int &length)
    {
        vector<int> nums3(m+n);
        int i = 0, j = 0, k = 0;
        while(i< m && j< n)
        {
           if(nums1[i]<nums2[j]) i++;
           else if (nums1[i] > nums2[j])j++;
           else 
        {
            nums3[k++]=nums1[i++];
            j++;
        }
        }
        //atleast one (may be more) element from either the nums1 or nums2 is/are remaining
       
        length=k;
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
    int length;
    Solution s;
    vector<int> num3= s.intersection(num1, 5, num2, 5, length);
    for(int i = 0; i<length; i++)
    cout << num3[i] << " ";
}