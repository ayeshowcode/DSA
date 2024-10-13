#include <iostream>
using namespace std;

struct Stack
{
    int size;
    int top;
    int *s; // Pointer to hold the stack array
};

void create(struct Stack *st)
{
    cout << "Enter the size: ";
    cin >> st->size;
    st->top = -1; // Initialize top to -1, indicating an empty stack

    // Allocate memory for the stack array
    st->s = new int[st->size]; // Allocating an array of size `st->size`
}
void display(struct Stack *st)
{
    for (int i = st->top; i >= 0; i--)
    {
        cout << st->s[i] << " ";
    }
    cout << endl;
}
void push(struct Stack *st, int x)
{
    if (st->top == st->size == -1)
        cout << "stack overflow" << endl;
    else
        st->top++;
    st->s[st->top] = x;
}
int pop(struct Stack *st)
{
    int x;
    if (st->top == -1)
        cout << "stack underflow" << endl;
    else
        x = st->s[st->top--];
    return x;
}
int peek(struct Stack *st, int index)
{
    int x = -1;
    if (st->top - index + 1 < 0)
        cout << "invalid index" << endl;
    x = st->s[st->top - index + 1];
    return x;
}
int isEmpty(struct Stack *st)
{
    if (st->top == -1)
        return 1;
    return 0;
}
int isFull(struct Stack *st)
{
    return st->top == st->size - 1;
}
int stackTop(struct Stack *st)
{
    if (!isEmpty(st))
        return st->s[st->top];
    return -1;
}
int main()
{
    Stack st;
    create(&st); // Create the stack
    push(&st, 8);
    push(&st, 10);
    push(&st, 12);
    push(&st, 14); // this will be the first one to be displayed!!!

    display(&st); // display the stack
    cout << pop(&st) << endl;
    display(&st);
    // You can now use the stack (push, pop, etc.)

    // Cleanup: Don't forget to deallocate the memory when done
    delete[] st.s;

    return 0;
}
