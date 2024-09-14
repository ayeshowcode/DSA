#include<iostream>
using namespace std;
struct Rectangle
{
    int length;
    int breadth;
};

void fun(struct Rectangle r)
{
    r.length=20; // will not change in the main functionca
    cout << r.length << " " << r.breadth << endl;
}
int main()
{
    struct Rectangle r={10,5};
    fun(r);
    cout << r.length << " " << r.breadth;
    return 0;
    
}