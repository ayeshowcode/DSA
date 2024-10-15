#include <iostream>
#include <string>
using namespace std;
void dice(string p, int target)
{
    if (target == 0)
    {
        cout << p << ", ";
        return;
    }
    for (int i = 1; i <= 6 && i <= target; i++)
    {
        dice(p + to_string(i), target - i);
    }
}
int main()
{
    dice("", 4);
}