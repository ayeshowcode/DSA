// assumption: considered the position/index as: if the index/position value is 3 it means the value will be inserted after 3 nodes

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // Constructor to initialize a node
    Node() : data(0), prev(nullptr), next(nullptr) {}
    Node(int val)
    {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList
{
private:
    Node *head;

public:
    DoublyLinkedList(int A[], int n)
    {
        if (n <= 0)
            return; 

        Node *last;
        head = new Node(A[0]);
        last = head;

        for (int i = 1; i < n; i++)
        {
            Node *temp = new Node(A[i]);
            temp->prev = last;
            last->next = temp;
            last = temp;
        }

        // Making it circular
        last->next = head;
        head->prev = last;
    }

    // Display the list from the head to the end
    void display()
    {
        if (!head)
            return; 

        Node *p = head;
        do
        {
            cout << p->data << " ";
            p = p->next;
        } while (p != head);

        cout << endl;
    }
    int length()
    {
        if (!head)
            return 0; // No nodes

        Node *p = head;
        int len = 0;
        do
        {
            len++;
            p = p->next;
        } while (p != head);
        return len;
    }
 
};
int main()
{
    int A[] = {10, 20, 30, 40, 50};
    DoublyLinkedList dll(A, 5);
    cout << "original" << endl;
    dll.display();
    return 0;
}