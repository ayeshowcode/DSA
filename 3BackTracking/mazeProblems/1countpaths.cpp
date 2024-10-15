#include<iostream>
using namespace std;
int count (int r, int c)
{
    if(r==1 || c==1)return 1;
    int left = count(r-1, c);
    int right = count(r, c-1);
    return left + right;
}
int main()
{
    cout << count(3,3) << endl;
} 