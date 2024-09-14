#include <iostream>
using namespace std;

class Rectangle
{
public:
    int length;
    int breadth;
    void initialize(int l, int b)
    {
        length = l;
        breadth = b;
    }
    int area()
    {
        return length * breadth;
    }

    int peri()
    {
        return 2 * (length + breadth);
    }
};
int main()
{
    Rectangle r;
    int length, breadth;
    cout << "Enter length and breadth ";
    cin >> length;
    cin >> breadth;
    r.initialize(length, breadth);
    int a = r.area();
    int p = r.peri();

    cout << "area: " << a << endl;
    cout << "perimeter: " << p << endl;
}