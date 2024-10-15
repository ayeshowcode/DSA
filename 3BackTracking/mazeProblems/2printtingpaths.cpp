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
        path(p + 'D', r - 1, c);
    if (c > 1)
        path(p + 'R', r, c - 1);
}
int countpaths(string p, int r, int c)
{
    if (r == 1 && c == 1)
    {
        // cout << p << " ";
        return 1;
    }
    int count = 0;
    if (r > 1)
        count+=countpaths(p + 'D', r - 1, c);
    if (c > 1)
        count+=countpaths(p + 'R', r, c - 1);
    return count;
}
int main()
{
    path("", 3,3);
    cout << countpaths("", 3, 3);
}