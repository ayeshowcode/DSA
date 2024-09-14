#include<iostream>
using namespace std;
struct Rectangle
{
    int length;
    int breadth;
};
void initialize(struct Rectangle *r, int a, int b)
{
    r->length=a;
    r->breadth=b;
}
int area(struct Rectangle r)
{
    return r.length*r.breadth;
}
void changelength(struct Rectangle *r, int c)
{
    r->length=c;
}
int main()
{
    struct Rectangle r;
    initialize(&r, 10,20);
    cout <<area(r) << endl;
    changelength(&r, 50);
}