#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class LinkedList
{
private:
    Node *first;

public:
    LinkedList() { first = NULL; }
    LinkedList(int A[], int n)
    {
        Node *last, *t;
        int i = 0;

        first = new Node;
        first->data = A[0];
        first->next = NULL;
        last = first;

        for (i = 1; i < n; i++)
        {
            t = new Node;
            t->data = A[i];
            t->next = NULL;
            last->next = t;
            last = t;
        }
    }
    ~LinkedList()
    {
        Node *p = first;
        while (first)
        {
            first = first->next;
            delete p;
            p = first;
        }
    }
    void display()
    {
        Node *p;
        p = first;
        while (p != NULL)
        {
            cout << p->data << " ";

            p = p->next;
        }
    }
};
int main()
{
    int A[] = {17, 15, 8, 12, 10, 5, 4, 1, 7, 6};

    LinkedList ll1(A, 10);
    cout << "ORIGINAL" << endl;
    ll1.display();

}