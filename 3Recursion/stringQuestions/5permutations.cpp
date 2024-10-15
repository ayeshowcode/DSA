#include <iostream>
using namespace std;
void permutations(string p, string up)
{
    if (up.empty())
    {
        cout << p << ", ";
        return;
    }
    char ch=up[0];
    for(int i = 0; i<= p.length(); i++)
    {
        string f=p.substr(0, i);
        string s=p.substr(i);
        permutations(f+ch+s, up.substr(1));
    }
}
void permutationsWithCaseToggle(string p, string up) {
    if (up.empty()) {
        cout << p << ", ";  // Base case: Print the generated permutation
        return;
    }

    // Take the first character from `up`
    char ch = up[0];

    // Generate two branches: one with the character as is, one with toggled case
    // Option 1: Keep the character as is
    for (int i = 0; i <= p.length(); i++) {
        string f = p.substr(0, i);  // Part before the current index
        string s = p.substr(i);     // Part after the current index
        permutationsWithCaseToggle(f + ch + s, up.substr(1));
    }

    // Option 2: Toggle the case if the character is alphabetic
    if (isalpha(ch)) {
        // Toggle the case: uppercase to lowercase or vice versa
        ch = islower(ch) ? toupper(ch) : tolower(ch);

        // Insert the toggled case character in all positions
        for (int i = 0; i <= p.length(); i++) {
            string f = p.substr(0, i);  // Part before the current index
            string s = p.substr(i);     // Part after the current index
            permutationsWithCaseToggle(f + ch + s, up.substr(1));
        }
    }
}
int main()
{
    permutations("", "abc");
    cout << endl;
    permutationsWithCaseToggle("", "ab");
}