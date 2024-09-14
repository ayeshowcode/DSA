//breaking the program into funcitons is called modular function
#include<iostream>
using namespace std;
int area(int length, int breadth)
{
    return length*breadth;
}
int perimeter(int length, int breadth)
{
    return 2*(length+breadth);
}
int main()
{
    cout<< area(20,10)<<endl;
    cout<< perimeter(20,10);

}