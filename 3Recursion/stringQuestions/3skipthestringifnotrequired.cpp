// only skip the app when it is not equal to apple

#include <iostream>
using namespace std;

string skipAppnotApple(string up)
{
    // Base case: if the input string is empty, return an empty string
    if (up.empty())
    {
        return "";
    }

    // Check if the current string starts with "apple"
    if (up.rfind("app", 0) == 0 && up.rfind("apple", 0) != 0)
    { // rfind with 0 checks if "apple" is at the start
        // Skip the length of "apple" and call skipApple recursively
        return skipAppnotApple(up.substr(3));
    }
    else
    {
        // Take the first character and recursively call skipApple on the rest
        return up[0] + skipAppnotApple(up.substr(1));
    }
}
int main()
{
    string a = "xxappleyyapplezz";
    cout << skipAppnotApple(a) << endl; // this will not skip because it has apple in it
    string b = "xxappyyappzz";
    cout << skipAppnotApple(b) << endl; // this will skip because it has not apple in it
    return 0;
}