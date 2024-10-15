#include <iostream>
using namespace std;

string skipApple(string up)
{
    // Base case: if the input string is empty, return an empty string
    if (up.empty())
    {
        return "";
    }

    // Check if the current string starts with "apple"
    if (up.rfind("apple", 0) == 0)
    { // rfind with 0 checks if "apple" is at the start
        // Skip the length of "apple" and call skipApple recursively
        return skipApple(up.substr(5));
    }
    else
    {
        // Take the first character and recursively call skipApple on the rest
        return up[0] + skipApple(up.substr(1));
    }
}
int main()
{
    string a = "xxappleyyapplezz";
    cout << skipApple(a) << endl; // Output: xxyyzz
    return 0;
}