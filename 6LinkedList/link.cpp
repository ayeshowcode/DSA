#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *head = NULL, *first = NULL, *second = NULL, *third = NULL;

void create(int A[], int n)
{
    struct Node *temp, *newnode;
    head = new struct Node;
    head->data = A[0];
    head->next = NULL;
    newnode = head;

    for (int i = 1; i < n; i++)
    {
        temp = new struct Node;
        temp->data = A[i];
        temp->next = NULL;
        newnode->next = temp;
        newnode = temp;
    }
}

// the belo 2 functions are for the 2 new linked list creation for merging (first and second)
void create2(int A[], int n)
{
    struct Node *temp, *newnode;
    first = new struct Node;
    first->data = A[0];
    first->next = NULL;
    newnode = first;

    for (int i = 1; i < n; i++)
    {
        temp = new struct Node;
        temp->data = A[i];
        temp->next = NULL;
        newnode->next = temp;
        newnode = temp;
    }
}
void create3(int A[], int n)
{
    struct Node *temp, *newnode;
    second = new struct Node;
    second->data = A[0];
    second->next = NULL;
    newnode = second;

    for (int i = 1; i < n; i++)
    {
        temp = new struct Node;
        temp->data = A[i];
        temp->next = NULL;
        newnode->next = temp;
        newnode = temp;
    }
}

void display(struct Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
void displayrec(struct Node *p)
{
    if (p != NULL)
    {
        displayrec(p->next); // reverse if before the print statement
        cout << p->data << " ";
    }
}
int countNodes(struct Node *p)
{
    int length = 0;
    while (p)
    {
        length++;
        p = p->next;
    }
    return length;
}
int countNodesRec(struct Node *p)
{
    if (p)
    {
        return countNodes(p->next) + 1;
    }
    else
        return 0;
}
int sum(struct Node *p)
{
    int sum = 0;
    while (p)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}
int sumRec(struct Node *p)
{
    if (p)
    {
        return sumRec(p->next) + p->data;
    }
    else
        return 0;
}
int max(struct Node *p)
{
    int max = INT_MIN;
    while (p)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}
int maxRec(struct Node *p)
{
    int x = 0;
    if (p == 0)
        return INT_MIN;
    x = maxRec(p->next);
    if (x > p->data)
        return x;
    else
        return p->data;
}

Node *Linearsearch(struct Node *p, int key)
{
    while (p != NULL)
    {
        if (key == p->data)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}
Node *recursiveLinearSearch(struct Node *p, int key)
{
    if (p == NULL)
        return NULL;
    if (key == p->data)
        return p;

    return recursiveLinearSearch(p->next, key);
}
Node *ImprovingLinearsearch(struct Node *p, int key)
{
    struct Node *q;
    while (p != NULL)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = head;
            head = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}
void insert(struct Node *p, int index, int x)
{
    struct Node *t;
    if (index < 0 || index > countNodes(p))
        return;
    t = new struct Node;
    t->data = x;

    if (index == 0)
    {
        t->next = head;
        head = t;
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
void SortedInsert(struct Node *p, int x)
{
    struct Node *t, *q = NULL;
    t = new Node;
    t->data = x;
    t->next = NULL;
    if (head == NULL)
    {
        head = t;
    }
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == head) // insert before the head... suppose the list is 10, 20, 30 and we want to insert '5' so it should be insert at starting position...
        {
            t->next = head;
            head = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}
int Delete(struct Node *p, int index)
{
    struct Node *q = NULL;
    int x = -1;
    if (index < 1 || index > countNodes(p))
    {
        return -1;
    }
    if (index == 1)
    {
        q = head;
        x = head->data;
        head = head->next;
        delete q;
        return x;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
        return x;
    }
}
bool isSorted(struct Node *p)
{
    int x = INT_MIN;
    while (p != NULL)
    {
        if (p->data < x)
            return false;
        x = p->data;
        p = p->next;
    }
    return true;
}
void removingDuplicatesfromSortedList(struct Node *p)
{
    struct Node *q = p->next;
    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}
void reverse1(struct Node *p)
{
    int *A;
    struct Node *q = p;
    A = new int[countNodes(p)];
    int i = 0;
    while (q != NULL)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    while (q != NULL)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
}
// using sliding pointers
void reverse2(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
}
// recursive
void reverse3(struct Node *q, struct Node *p)
{
    if (p)
    {
        reverse3(p, p->next);
        p->next = q;
    }
    else
        head = q;
}
void Concat(struct Node *p, struct Node *q)
{
    third = p;
    while (p->next != NULL)
        p = p->next;

    p->next = q;
}
void merge(struct Node *p, struct Node *q)
{
    struct Node *last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }
    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
        if (p)
            last->next = p;
        else if (q)
            last->next = q;
    }
}
int isLoop(struct Node *f)
{
    struct Node *p, *q;
    p=q=f;

    do
    {
        p=p->next;
        q=q->next;
        q=q?q->next:q;
    }while(p&&q && p!=q);
    if(p==q)
    return 1;
    return 0;
}
int main()
{
    int A[] = {1, 2, 3, 4, 5};
    create(A, 5);
    display(head);
    displayrec(head);
    cout << endl;
    cout << "length of the list is: " << countNodes(head) << endl;
    cout << "length of the list is: " << countNodesRec(head) << endl;
    cout << "sum of the elements is: " << sum(head) << endl;
    cout << "sum of the elements is: " << sumRec(head) << endl;
    cout << "max element in the list is: " << max(head) << endl;
    cout << "max element in the list is: " << maxRec(head) << endl;
    struct Node *temp;
    struct Node *temprec;
    temp = Linearsearch(head, 3);
    if (temp != NULL)
        cout << "key is found: " << temp->data << endl;
    else
        cout << "key is not found" << endl;

    temprec = recursiveLinearSearch(head, 3);
    if (temprec != NULL)
        cout << "key is found: " << temprec->data << endl;
    else
        cout << "key is not found" << endl;

    struct Node *tempimproved;
    tempimproved = ImprovingLinearsearch(head, 3);
    if (tempimproved != NULL)
        cout << "key is found: " << tempimproved->data << endl;
    else
        cout << "key is not found" << endl;

    // to check the list is modified lets call the display function
    display(head);
    insert(head, 4, 99); // insert 99 at index 4
    cout << "inserting 99 at index 4" << endl;
    display(head);

    int B[] = {1, 2, 3, 4, 5};
    cout << "creating new array:" << endl;
    create(B, 5);
    display(head);
    SortedInsert(head, 1010);
    display(head);

    cout << "deleting 3 from array" << endl;
    Delete(head, 3);
    display(head);

    cout << isSorted(head) << endl;
    display(head);
    insert(head, 5, 1010); // inserting to use "removeduplicates" function
    cout << "list with dupliacates" << endl;
    display(head);
    removingDuplicatesfromSortedList(head);
    cout << "list without duplicates" << endl;
    display(head);
    reverse1(head);
    display(head);
    reverse2(head);
    display(head);
    reverse3(NULL, head);
    display(head);
    cout << endl
         << endl;
    cout << "creating 2 new linked lists for merging" << endl;
    int firstarr[] = {5, 10, 20, 30, 40};
    int secondarr[] = {50, 152, 252, 352, 500};
    create2(firstarr, 5);
    create3(secondarr, 5);
    display(first);
    display(second);
    // Concat(first, second);
    // cout << "concatinated" << endl;
    // display(third);
    cout << "merge" << endl;
    merge(first, second);
    display(third);

    cout << endl;
    struct Node *t1, *t2;
    reverse1(head);
    Delete(head, 5);
    display(head);
    insert(head, 2,3);
    display(head);
    // now array is 1,2,3,4,5
    t1 = head->next->next; // 3
    t2=head->next->next->next->next; // 5
    t2->next=t1;

    cout << isLoop(head);
    
    return 0;
}