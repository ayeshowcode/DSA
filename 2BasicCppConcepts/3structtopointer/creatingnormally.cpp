#include<iostream>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};
int main()
{
    struct Rectangle r={10,15};
    struct Rectangle *p=&r;
    cout << p->length << endl;
    cout << p->breadth << endl;

}