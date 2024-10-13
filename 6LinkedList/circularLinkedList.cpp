#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
} *head;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    head = new Node;
    head->data = A[0];
    head->next = head; // just one node
    last = head;
    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}
void display(struct Node *h)
{
    do
    {
        cout << h->data << " ";
        h = h->next;
    } while (h != head);
    cout << endl;
}
int length(struct Node *p)
{
    int len = 0;
    do
    {
        len++;
        p = p->next;
    } while (p != head);
    return len;
}
void insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    if (index < 0 || index > length(p))
        return;
    if (index == 0)
    {
        t = new Node;
        t->data = x;
        if (head == NULL)
        {
            head = t;
            head->next = head;
        }
        else
        {
            while (p->next != head)
                p = p->next;
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t = new Node;
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}
int Delete(struct Node *p, int index)
{
    struct Node *q;
    int i, x;
    if (index < 0 || index > length(p))
        return -1;
    if (index == 1)
    {
        while (p->next != head)
            p = p->next;
        x = head->data;
        if (head == p)
        {
            delete p;
            p = NULL;
        }
        else
        {
            p->next = head->next;
            delete p;
            head = p->next;
        }
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        x = q->data;
        delete q;
    }
    return x;
}
int main()
{
    int A[] = {1, 2, 3, 4, 5};
    create(A, 5);
    display(head);
    insert(head, 5, 5);
    display(head);
    Delete(head, 1);
    display(head);
}