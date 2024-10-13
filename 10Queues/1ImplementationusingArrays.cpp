#include<iostream>
using namespace std;

class Queue
{
private:
    int size;
    int front;
    int rear;
    int *Q;

public:
    Queue(int size)
    {
        this->size = size;
        front = rear = -1;
        Q = new int[size];
    }

    ~Queue()
    {
        delete[] Q;
    }

    void enqueue(int x)
    {
        if (rear == size - 1)
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            rear++;
            Q[rear] = x;
        }
    }
    int dequeue()
    {
        int x = -1;
        if (front == rear)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            front++;
            x = Q[front];
        }
        return x;
    }

    void display()
    {
        for (int i = front + 1; i <= rear; i++)
        {
            cout << Q[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    cout << q.dequeue() << endl;
    q.display();

    return 0;
}