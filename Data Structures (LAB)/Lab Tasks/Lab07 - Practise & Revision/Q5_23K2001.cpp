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

    void deleteMiddle(int count, int size)
    {
        if (count == (size) / 2)
        {
            pop();
            return;
        }

        int val = peek();
        pop();

        deleteMiddle(count + 1, size);
        push(val);
    }
};

int main()
{
    Stack s1(5);
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);

    s1.deleteMiddle(0, 5);
    while (!s1.empty())
    {
        cout << s1.peek() << " ";
        s1.pop();
    }

    return 0;
}
