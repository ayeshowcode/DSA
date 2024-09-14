#include<iostream>
using namespace std;

void func(int *a, int n) // pointer to an array
{
    cout << sizeof(a)/sizeof(int) << endl; //     8/4=2   (because pointer always takes 8 bytes)
    //   for(int x:a)
    // cout << x << " ";  this is wrong we cannot use for each loop for pointers

    a[0]=20; // in main function it will also change
    for(int i=0; i<n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

}
int main()
{
    int a[]={1,3,4,5,6};
    int n=5;
    cout << sizeof(a)/sizeof(int) << endl; // 20/4
    func(a,n); //call by address (arrays are alwayas passed by address)
    for(int x:a)
    cout << x << " ";
    return 0;
}