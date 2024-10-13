#include <iostream>
using namespace std;

class Node
{
public:
    char data;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:
    Stack() { top = NULL; }

    void push(char x);
    char pop();
    char last();
    void display();
    int isEmpty();
    int isBalanced(char *exp);
    int isBalanced2(char *exp);
};

void Stack::push(char x)
{
    Node *t = new Node;
    if (t == NULL)
        cout << "stack is full" << endl;
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

char Stack::pop()
{
    char x = '\0';
    if (top == NULL)
        cout << "stack is empty" << endl;
    else
    {
        x = top->data;
        Node *t = top;
        top = top->next;
        delete t;
    }
    return x;
}

char Stack::last()
{
    char x = '\0';
    if (top == NULL)
        cout << "stack is empty" << endl;
    else
    {
        x = top->data;
    }
    return x;
}

void Stack::display()
{
    Node *p = top;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int Stack::isEmpty()
{
    return top == NULL;
}
int Stack::isBalanced(char *exp)
{
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
            push(exp[i]);
        else if (exp[i] == ')')
        {
            if (isEmpty())
                return 0;
            pop();
        }
    }
    return isEmpty();
}

int Stack::isBalanced2(char *exp)
{
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
            push(exp[i]);
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (isEmpty())
                return 0;

            char x = pop();
            if ((x == '(' && exp[i] != ')') || (x == '[' && exp[i] != ']') || (x == '{' && exp[i] != '}'))
                return 0;
        }
    }
    return isEmpty();
}

int main()
{
    char exp[] = "((a+b)*(c-d))";
    char exp2[] = "{([a+b]*[c-d])/e}";
    Stack stk;

    if (stk.isBalanced(exp))
        cout << "The expression is balanced." << endl;
    else
        cout << "The expression is not balanced." << endl;

    if (stk.isBalanced2(exp2))
        cout << "The expression 2 is balanced." << endl;
    else
        cout << "The expression 2 is not balanced." << endl;
    return 0;
}
