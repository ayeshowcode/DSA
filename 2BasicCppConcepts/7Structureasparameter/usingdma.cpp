#include<iostream>
using namespace std; 
struct Rectangle 
{
    int length;
    int breadth;
};

struct Rectangle *fun()
{
    struct Rectangle *r;
    r= new Rectangle;
    r->length=12;
    r->breadth=10;
    return r;
}
int main()
{
    struct Rectangle *ptr=fun();
    cout << ptr->length << " " << ptr->breadth;
}