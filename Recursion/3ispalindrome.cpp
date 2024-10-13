#include <iostream>
using namespace std;
int rev(int n, int mul)
{
    if (n == 0)
        return 0;
    return ((n % 10) * mul) + rev(n / 10, mul / 10);
}
bool ispalindrome(int n, int mul)
{
    return (n == rev(n, mul));
}
int main()
{
    cout << rev(1234, 1000) << endl;
    if (ispalindrome(1221, 1000))
        cout << "yes it is a palindrome number" << endl;
    else
        cout << "not  palindrome number";
}