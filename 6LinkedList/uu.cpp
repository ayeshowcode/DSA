#include <iostream>
using namespace std;

int main()
{
    struct node
    {
        int data;
        struct node *next;
    };
    struct node *head;
    struct node *newnode;
    struct node *temp;
    head = NULL;
    int choice = 1, count = 0;
    while (choice)
    {
        newnode = new struct node;
        cout << "Enter Data:\n";
        cin >> newnode->data;
        newnode->next = 0;
        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        cout << "Do you want to continue (0,1)?\n";
        cin >> choice;
    }
    printf("--------------------------------\n");
    temp = head;
    while (temp != 0)
    {
        printf("\n%d\n", temp->data);
        temp = temp->next;
        count++;
    }
    {
        cout << "\nCount: " << count << endl;
    }
}