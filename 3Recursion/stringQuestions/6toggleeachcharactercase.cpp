#include <iostream>
#include <cctype>  // For isalpha, islower, toupper, tolower
using namespace std;

void togglePermute(string &a, int l) {
    if (l == a.size()) {  
        cout << a << endl;  // Base case: a valid permutation is generated
        return;
    }

    // Explore the original character without change
    togglePermute(a, l + 1);

    if (isalpha(a[l])) {  // Toggle only if it's an alphabet
        // Toggle the case of the current character
        a[l] = islower(a[l]) ? toupper(a[l]) : tolower(a[l]);

        // Explore with the toggled character
        togglePermute(a, l + 1);

        // Backtrack: Restore the original character
        a[l] = islower(a[l]) ? toupper(a[l]) : tolower(a[l]);
    }
}

int main() {
    string a;
    cout << "Enter the string: ";
    cin >> a;

    cout << "Toggle Case Permutations:\n";
    togglePermute(a, 0);  // Start with the first character
    return 0;
}
