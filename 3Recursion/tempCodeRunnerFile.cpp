
// 2^8=(2^2)^4
// 2^9=2*(2^2)4
#include <iostream>
using namespace std;
int fpow(int m, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return fpow(m * m, n / 2);
    else
        return m * fpow(m * m, (n) / 2);
}
int main()
{
    cout << fpow(2, 10);
}