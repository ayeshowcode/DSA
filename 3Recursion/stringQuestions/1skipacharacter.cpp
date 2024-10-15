#include <iostream>
using namespace std;
string skip(string up) // processed and unprocessed
{
    if (up.empty())
    {
        return "";
    }
    char ch = up[0];

    if (ch == 'a')
        return skip(up.substr(1));
    else
        return ch + skip(up.substr(1)); 
}
int main() 
{
    string a = "aabbccadd";
    cout << skip(a);
}