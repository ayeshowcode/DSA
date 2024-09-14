// 2^5=2*2*2*2*2=32
// pow(m,n)=m*m*m*m*m*.... for n times
// pow(m,n)=m*m*m*m*m....for (n-1) times * m
// pow(m,n)=pow(m, n-1) * m

// n=0 --> 1
// n>0 --> pow(m, n-1) * m

#include <iostream>
using namespace std;

int pow(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return pow(m, n - 1) * m;
    }
}
int main()
{
    cout << pow(2, 10);
}

// faster way (less no of multiplications)

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
        return m * fpow(m * m, n / 2);
}
int main()
{
    cout << fpow(2, 10);
}