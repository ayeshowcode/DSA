///everything written in main fucntion is called monotholic program

#include<iostream>
using namespace std;
int main()
{
    int length=0, breadth=0;
    cout << "Enter the length and breadth";
    cin >> length;
    cin >>breadth;

    int area=length=breadth;
    int peri=2*(length+breadth);
    cout << "Area: " << area << endl;
    cout << "perimeter: " <<peri << endl;
    return 0;
}