#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class SinglyLL
{
private:
    Node *first;

public:
    SinglyLL() { first = NULL; }
    SinglyLL(int A[], int n)
    {
        Node *last, *t;
        int i = 0;

        first = new Node;
        first->data = A[0];
        first->next = NULL;
        last = first;

        for (int i = 1; i < n; i++)
        {
            t = new Node;
            t->data = A[i];
            t->next = NULL;
            last->next = t;
            last = t;
        }
    }
    ~SinglyLL()
    {
        Node *p = first;
        while (first)
        {
            first = first->next;
            delete p;
            p = first;
        }
    }
    void display(Node *p)
    {
        Node *p = first;
        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }
    int len()
    {
        Node *p = first;
        int length = 0;
        while (p)
        {
            length++;
            p = p->next;
        }
        return length;
    }
    void displayrec(Node *p)
    {
        if (!p)
            return;
        cout << p->data;
        display(p->next);
    }
    void insert(int val, int index)
    {

        if (index < 0 || index > len())
            return;
        Node *p = first;
        Node *t = new Node;
        t->data=val;
        t->next = NULL;

        if (index == 0)
        {
            t->next = first;
            first = t;
        }
        else
        {
            
            for (int i = 0; i < index - 1; i++)
            {
                p = p->next;
            }
            t->next = p->next;
            p->next = t;
        }
    }
    int dlt(int index)
    {
        Node *p, *q = NULL;
        int x = -1;
        if (index < 1 || index > len())
        {
            return -1;
        }
        if (index == 1)
        {
            p = first;
            p = p->next;
            x = p->data;
            delete p;
        }
        else
        {
            p = first;
            for (int i = 0; i < index - 1; i++)
            {
                q = p;
                p = p->next;
            }
            q->next = p->next;
            x = p->data;
            delete p;
        }
        return x;
    }
};
class CircularSinglyLL
{
private:
    Node *first;

public:
    CircularSinglyLL() { first = NULL; }
    CircularSinglyLL(int A[], int n)
    {
        Node *last, *t;

        first = new Node;
        first->data = A[0];
        first->next = first;
        last = first;

        for (int i = 1; i < n; i++)
        {
            t = new Node;
            t->data = A[i];
            t->next = last->next;
            last->next = t;
            last = t;
        }
    }
    ~CircularSinglyLL()
    {
        Node *p = first;
        if (first != NULL)
        {
            do
            {
                Node *temp = p;
                p = p->next;
                delete temp;
            } while (p != first);
        }
    }
    void display(Node *p)
    {
        if(first==NULL) return;
        Node *p = first;
        do 
        {
            cout << p->data << " ";
            p=p->next;
        }while(p!=first);
        cout << endl;
    }
    int len()
    {
        if(first==NULL) return 0;
        Node *p=first;
        int length = 0;
        do
        {
            length++;
            p=p->next;
        }while(p!=first);
        return length;
    }
    
    void insert(int val, int index)
    {

        if (index < 0 || index > len())
            return;
        Node *p = first;
        Node *t = new Node;
        t->next = NULL;

        if (index == 0)
        {
            t->data=val;
            if(first==NULL)
            {
                first=t;
                first->next=first;
            }
            else
            {
                while(p->next!=first)
                    p=p->next;
                p->next=t;
                t->next=first;
                first=t;
            }
        }
        else
        {
            for (int i = 0; i < index - 1; i++)
            {
                p = p->next;
            }
            t->data=val;
            t->next = p->next;
            p->next = t;
        }
    }
    int dlt(int index)
    {
        Node *p=first, *q = NULL;
        int x = -1;
        if (index < 1 || index > len())
        {
            return -1;
        }
        if (index == 1)
        {
           while(p->next!=first)
           p=p->next;
           x=first->data;
           if(first==p) // only one node
           {
            delete first;
            first = NULL;
           }
           else
           {
            p->next=first->next;
            Node *temp = first;
            first = first->next;
            delete temp;
           }
        }
        else
        {
            p = first;
            Node *q=NULL;
            for (int i = 0; i < index - 2; i++)
            {
                q = p;
                p = p->next;
            }
            q->next = p->next;
            x = p->data;
            delete p;
        }
        return x;
    }
};

int main()
{
}