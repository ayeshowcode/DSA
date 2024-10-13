#include <iostream>
using namespace std;
int rev(int n, int mul)
{
    if (n == 0)
        return 0;
    return ((n % 10) * mul) + rev(n / 10, mul / 10);
}
int main()
{
    cout << rev(1234, 1000);
}