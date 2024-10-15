#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node() : data(0), prev(nullptr), next(nullptr){}
};
class DoublyLinkedList
{
private:
    Node *head;

public:
    DoublyLinkedList() : head(NULL) {}
    DoublyLinkedList(int A[], int n)
    {
        if (n <= 0)
            return;
        Node *last;
        head = new Node;
        head->data = A[0];
        last = head;

        for (int i = 1; i < n; i++)
        {
            Node *t = new Node;
            t->data = A[i];
            t->prev = last;
            last->next = t;
            last = t;
        }
    }
    void display()
    {
        Node *p = head;
        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    int length()
    {
        Node *p = head;
        int len = 0;
        while (p)
        {
            len++;
            p = p->next;
        }
        return len;
    }

    void insert(int index, int value)
    {
        // Check if the index is valid
        if (index < 0 || index > length())
            return;

        Node *t = new Node; // Create a new node
        t->data = value;

        if (index == 0) // Insert at the head
        {
            t->next = head;
            if (head) // If list is not empty, set prev of head
                head->prev = t;
            head = t; // Update head to new node
        }
        else // Insert at any other position
        {
            Node *p = head;
            for (int i = 0; i < index - 1; i++) // Move to (index-1)-th node
                p = p->next;

            t->next = p->next; // Set new node’s next to p’s next
            t->prev = p;       // Set new node’s prev to p

            if (p->next) // If not inserting at the end
                p->next->prev = t;

            p->next = t; // Link p to the new node
        }
    }
    int deleteNode(int index)
    {
        // Check if the index is valid
        if (index < 0 || index >= length() || head == NULL)
            return -1;

        Node *p = head;
        int x;

        if (index == 0) // Deleting the head node
        {
            head = head->next; // Move head to the next node
            if (head)          // If head is not NULL, update its prev to NULL
                head->prev = NULL;
            x = p->data;
            delete p; // Delete the old head node
        }
        else // Deleting any other node
        {
            for (int i = 0; i < index; i++) // Move to the desired node
                p = p->next;

            p->prev->next = p->next; // Update the previous node’s next

            if (p->next) // If not deleting the last node, update the next node’s prev
                p->next->prev = p->prev;

            x = p->data;
            delete p; // Delete the node
        }
        return x; // Return the data of the deleted node
    }
};

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node() : data(0), prev(nullptr), next(nullptr) {}
};

class DoublyCircularLinkedList
{
private:
    Node *head;

public:
    DoublyCircularLinkedList() : head(nullptr) {}

    // Constructor to create a list from an array
    DoublyCircularLinkedList(int A[], int n)
    {
        if (n <= 0)
            return;

        Node *last;
        head = new Node;
        head->data = A[0];
        head->next = head;  // Circular link to itself
        head->prev = head;  // Circular link to itself
        last = head;

        for (int i = 1; i < n; i++)
        {
            Node *t = new Node;
            t->data = A[i];

            // Inserting new node between last and head
            t->prev = last;
            t->next = head;
            last->next = t;
            head->prev = t;

            last = t;  // Move last to the new node
        }
    }

    // Display the list
    void display()
    {
        if (!head)
            return;

        Node *p = head;
        do
        {
            cout << p->data << " ";
            p = p->next;
        } while (p != head);  // Stop when we come back to head
        cout << endl;
    }

    // Find the length of the list
    int length()
    {
        if (!head)
            return 0;

        int len = 0;
        Node *p = head;
        do
        {
            len++;
            p = p->next;
        } while (p != head);  // Stop when we come back to head

        return len;
    }

    // Insert a node at a given index
    void insert(int index, int value)
    {
        if (index < 0 || index > length())
            return;

        Node *t = new Node;
        t->data = value;

        if (index == 0)  // Inserting at the head
        {
            if (!head)  // If the list is empty
            {
                head = t;
                head->next = head;
                head->prev = head;
            }
            else  // If list is not empty
            {
                Node *last = head->prev;

                // Insert between last and head
                t->next = head;
                t->prev = last;
                last->next = t;
                head->prev = t;

                head = t;  // Update head to new node
            }
        }
        else  // Inserting at any other position
        {
            Node *p = head;
            for (int i = 0; i < index - 1; i++)
                p = p->next;

            t->next = p->next;
            t->prev = p;
            p->next->prev = t;
            p->next = t;
        }
    }

    // Delete a node at a given index
    int deleteNode(int index)
    {
        if (index < 0 || index >= length() || !head)
            return -1;

        int x;
        if (index == 0)  // Deleting the head node
        {
            Node *p = head;
            x = p->data;

            if (head->next == head)  // If only one node is present
            {
                delete head;
                head = nullptr;
            }
            else  // If more than one node
            {
                Node *last = head->prev;
                head = head->next;

                last->next = head;
                head->prev = last;

                delete p;
            }
        }
        else  // Deleting any other node
        {
            Node *p = head;
            for (int i = 0; i < index; i++)
                p = p->next;

            p->prev->next = p->next;
            p->next->prev = p->prev;
            x = p->data;

            delete p;
        }
        return x;
    }
};
int main()
{
}