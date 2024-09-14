#include <iostream>
using namespace std;
void TOH(int n, int A, int B, int C)
{
    if (n > 0)
    {
        TOH(n - 1, A, C, B);
        cout << "moving from " << A << " to " << C << " using " << B << endl;
        TOH(n - 1, B, A, C);
    }
}
int main()
{
    cout << "FOR 1 DISK: " << endl;
    TOH(1,1,2,3);


    cout << endl << endl;

    cout << "FOR 2 DISK: " << endl;
    TOH(2, 1, 2, 3);

    cout << endl << endl;


    cout << "FOR 3 DISK: " << endl;
    TOH(3,1,2,3);
}