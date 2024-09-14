#include <iostream>

struct Rectangle {
    int length;
    int breadth;
};

int main() {
    // Dynamically allocate memory for a single Rectangle
    Rectangle* p = new Rectangle;

    // Access and set the properties of the rectangle
    p->length = 41;
    p->breadth = 21;

    // Print the properties to verify
    std::cout << "Length: " << p->length << ", Breadth: " << p->breadth << std::endl;

    // Deallocate the memory
    delete p;

    return 0;
}
