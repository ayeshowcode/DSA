#include <iostream>
using namespace std;
void pad(string p, string up)
{
    if (up.empty())
    {
        cout << p << endl;
        return;
    }
    int digit = up[0] - '0';
    for (int i = (digit - 1) * 3; i < digit * 3; i++)
    {
        char ch = (char)('a' + i);
        pad(p + ch, up.substr(1));
    }
}
int padCount(string p, string up)
{
    if (up.empty())
    {
        return 1;
    }
    int count = 0;
    int digit = up[0] - '0';

    for (int i = (digit - 1) * 3; i < digit * 3; i++)
    {
        char ch = (char)('a' + i);
        count = count + padCount(p + ch, up.substr(1));
    }
    return count;
}
int main()
{
    pad("", "12");
    cout << endl;
    cout << padCount("", "12");
}