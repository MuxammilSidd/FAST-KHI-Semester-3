//23K2001 - Muzammil
#include <iostream>
using namespace std;

class Stack
{
    int *arr;
    int size;
    int top;

public:
    Stack(int s)
    {
        size = s;
        arr = new int[size];
        top = -1;
    }

    void push(int val)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = val;
        }
        else
        {
            cout << "Stack is FULL " << endl;
        }
    }
    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stak undeflow" << endl;
        }
    }

    int peek()
    {
        if (top >= 0 && top < size)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack empty" << endl;
            return -1;
        }
    }

    bool empty()
    {
        return top < 0;
    }
};

class Queue
{
    int *qarr;
    int size;
    int rear;
    int front;

public:
    Queue(int s)
    {
        size = s;
        qarr = new int[size];
        rear = 0;
        front = 0;
    }

    void enqueue(int val)
    {
        if (rear == size)
        {
            cout << "Queue FULL " << endl;
        }
        else
        {
            qarr[rear] = val;
            rear++;
        }
    }

    void dequeue()
    {
        if (rear == front)
        {
            cout << " Queuue Empty " << endl;
        }
        else
        {
            front++;
            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
        }
    }

    int top()
    {
        return qarr[front];
    }

    bool empty()
    {
        return front == rear;
    }
};

int main()
{
    Stack s1(4);
    s1.push(40);
    s1.push(30);
    s1.push(20);
    s1.push(10);
    
    Queue q1(4);

    while (!s1.empty())
    {
        q1.enqueue(s1.peek());
        s1.pop();
    }

    while (!q1.empty())
    {
        s1.push(q1.top());
        q1.dequeue();
    }

    while (!s1.empty())
    {
        cout << s1.peek() << " ";
        s1.pop();
    }
}