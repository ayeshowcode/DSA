#include<iostream>
using namespace std;
class Queue
{
    int front;
    int rear;
    int *arr;
    int size;
    public:
    Queue()
    {
      size=5;
      arr=new int[size];
      front = 0;
      rear = 0;
    }
    bool isEmpty()
    {
        if(front==-1 && rear == -1) return true;
        else return false;
    }
    bool isFull()
    {
        if(rear==4)
        return true;
        else return false;
    }
    void enqueue(int val)
    {
        if(rear==size)
        cout << "Queue is full" << endl;
        else 
        {
            arr[rear]=val;
            rear++;
        }
    }
    int dequeue()
    {
        if(front==rear)
        return -1;
        else 
        {
            arr[front] = -1;
            front++;
            if(front==rear)
            {
                front = 0;
                rear = 0;
            }
        }
    }
    int front()
    {
        if(front == rear)
        return true;
        else return false;
    }
};
int main()
{
    Queue q;
    q.enqueue(5);
    q.enqueue(7);
    q.enqueue(9);



}