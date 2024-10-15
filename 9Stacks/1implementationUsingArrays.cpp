#include <iostream>
using namespace std;

class Stack
{
private:
    int size;
    int top;
    int *s; // Pointer to hold the stack array

public:
    // Constructor to initialize the stack
    Stack(int stackSize)
    {
        size = stackSize;
        top = -1;
        s = new int[size]; // Dynamically allocate memory for the stack
    }

    // Destructor to release the allocated memory
    ~Stack()
    {
        delete[] s;
    }

    // Method to display the elements of the stack
    void display()
    {
        for (int i = top; i >= 0; i--)
            cout << s[i] << " ";
        cout << endl;
    }

    // Method to push an element onto the stack
    void push(int x)
    {
        if (isFull())
        {
            cout << "Stack overflow" << endl;
        }
        else
        {
            s[++top] = x; // Increment top and add element
        }
    }

    // Method to pop an element from the stack
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        else
        {
            return s[top--]; // Return element and decrement top
        }
    }

    // Method to peek at an element at a specific index from the top
    int peek(int index)
    {
        if (top - index + 1 < 0)
        {
            cout << "Invalid index" << endl;
            return -1;
        }
        else
        {
            return s[top - index + 1];
        }
    }

    // Method to check if the stack is empty
    bool isEmpty()
    {
        return top == -1;
    }

    // Method to check if the stack is full
    bool isFull()
    {
        return top == size - 1;
    }

    // Method to get the element at the top of the stack
    int stackTop()
    {
        if (!isEmpty())
            return s[top];
        return -1;
    }
};

int main()
{
    int stackSize;
    cout << "Enter the size of the stack: ";
    cin >> stackSize;

    // Create a stack object
    Stack st(stackSize);

    // Push elements onto the stack
    st.push(8);
    st.push(10);
    st.push(12);
    st.push(14);

    // Display the stack
    cout << "Stack elements: ";
    st.display();

    // Pop an element and display the stack again
    cout << "Popped element: " << st.pop() << endl;
    cout << "Stack after popping: ";
    st.display();

    return 0;
}
