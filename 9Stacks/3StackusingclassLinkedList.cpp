#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor to initialize a node
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class Stack
{
private:
    Node *top; // Pointer to the top of the stack

public:
    // Constructor to initialize an empty stack
    Stack()
    {
        top = nullptr;
    }

    // Destructor to delete all nodes and avoid memory leaks
    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    // Method to push an element onto the stack
    void push(int value)
    {
        Node *newNode = new Node(value); // Create a new node
        newNode->next = top;             // Link new node with the current top
        top = newNode;                   // Update the top to the new node
    }

    // Method to pop an element from the stack
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        Node *temp = top;            // Temporary pointer to the top node
        int poppedValue = top->data; // Store the value to return
        top = top->next;             // Move top to the next node
        delete temp;                 // Delete the old top node
        return poppedValue;
    }

    // Method to peek at the top element of the stack
    int stackTop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }

    // Method to check if the stack is empty
    bool isEmpty()
    {
        return top == nullptr;
    }

    // Method to display all elements in the stack
    void display()
    {
        Node *current = top;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack st;

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

    // Peek at the top element
    cout << "Top element: " << st.stackTop() << endl;

    return 0;
}
