#include <iostream>
#include <string> // Include string header for string type
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
    int precedence(char x);
    int isOperand(char x);
    string infixToPostfix(string infix);
    int evaluatePostfix(string postfix);
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

int Stack ::precedence(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}

int Stack::isOperand(char x)
{
    return !(x == '+' || x == '-' || x == '*' || x == '/');
}

string Stack::infixToPostfix(string infix)
{
    string postfix;
    for (int i = 0; i < infix.length(); i++)
    {
        if (isOperand(infix[i]))
        {
            postfix += infix[i]; // Add operand directly to postfix
        }
        else
        {
            while (!isEmpty() && precedence(infix[i]) <= precedence(top->data))
                postfix += pop(); // Pop higher/equal precedence operators
            push(infix[i]);
        }
    }
    while (!isEmpty())
    {
        postfix += pop(); // Add remaining operators in the stack
    }
    return postfix;
}
int Stack::evaluatePostfix(string postfix)
{
    for (int i = 0; i < postfix.size(); i++)
    {
        if (isOperand(postfix[i]))
            push(postfix[i] - '0');
        else
        {
            int val1 = top->data;
            pop();
            int val2 = top->data;
            pop();
            switch (postfix[i])
            {
            case '+':
                push(val2 + val1);
                break;
            case '-':
                push(val2 - val1);
            case '*':
                push(val2 * val1);
            case '/':
                push(val2 / val1);
                break;
            }
        }
    }
    return top->data;
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

    string infix = " x=12+13-5(0.5+0.5) +1";
    string postfix = stk.infixToPostfix(infix);
    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << postfix << endl;

    cout << stk.evaluatePostfix(postfix) << endl;

        return 0;
}
