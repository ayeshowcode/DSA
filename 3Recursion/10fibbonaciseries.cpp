#include <iostream>
using namespace std;

int fib(int n) // iterative
{
    int t0 = 0, t1 = 1, s = 0, i;
    if (n <= 1)
        return n;

    for (i = 2; i <= n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}

int erfib(int n) // excessive recursion
{
    if (n <= 1)
    {
        return n;
    }
    return fib(n - 2) + fib(n - 1);
}
int f[10];
int mrfib(int n) // momization
{
    if (n <= 1)
    {
        f[n] = n;
        return n;
    }
    else
    {
        if (f[n - 2] == -1)
        {
            f[n - 2] = mrfib(n - 2);
        }
        if (f[n - 1] == -1)
        {
            f[n - 1] = mrfib(n - 1);
        }
        return f[n - 2] + f[n - 1];
    }
}
int main()
{
     for (int i = 0; i < 10; i++)
    {
        f[i] = -1;
    }
    cout << fib(10) << endl;
    cout << erfib(10) << endl;
    cout << mrfib(10) << endl;
}