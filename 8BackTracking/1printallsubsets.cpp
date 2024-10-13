#include <iostream>
using namespace std;

void permute(string &a, int l, int r)
{
    if (l == r)
    {
        cout << a << endl;  // Base case: a valid permutation is generated
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            // Swap a[l] with a[i] 
            swap(a[l], a[i]);

            // Recursively call permute with the next index
            permute(a, l + 1, r);

            // Backtrack: undo the swap
            // swap(a[l], a[i]);
        }
    }
}
int main()
{
    string a;
    cout << "Enter the string: ";
    cin >> a;

    // Call permute with correct string length (a.size() - 1)
    permute(a, 0, a.size() - 1);
}
