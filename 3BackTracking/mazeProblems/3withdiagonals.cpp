#include <iostream>
using namespace std;
void path(string p, int r, int c)
{
    if (r == 1 && c == 1)
    {
        cout << p << " ";
        return;
    }
    if (r > 1)
        path(p + 'V', r - 1, c);
    if (c > 1)
        path(p + 'H', r, c - 1);
    if(r>1 && c>1)
        path(p+'D', r-1, c-1);
}
int main()
{
    path("" , 3,3);
}