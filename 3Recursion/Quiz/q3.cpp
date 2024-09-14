#include <iostream>
using namespace std;
int f(int &x, int c)
{
    c--;
    if (c == 0)
        return 1;
    x++;
    return f(x, c) * x;
}
int main()
{
    int a = 5;
    cout << f(a, a);
}

// c    4 3 2 1 0 return 1
// a/x  6 7 8 9

// if c==0 return 1
// return 1*9
// return 9*9
// return 81*9
// return 729*9 --> 6561
//return 