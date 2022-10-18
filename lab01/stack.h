#include <cstdio>
using namespace std;

#define SIZE 5
class stack
{
    int arr[SIZE];
    int top;

    public:
    stack()
    {
        top = -1;
    }

    bool isFull()
    {
        if (top == SIZE-1)
            return true;
        else
            return false;
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }

    void push(int num)
    {
        if (isFull())
        {
            printf("Stack is full\n");
        }
        else
        {
            top++;
            arr[top] = num;
        }
    }

    int pop()
    {
        if (isEmpty())
        {
            printf("Stack is empty\n");
            return -1;
        }
        else
        {
            int num = arr[top];
            top--;
            return num;
        }
    }

    int peek()
    {
        if (isEmpty())
        {
            printf("Stack is empty\n");
            return -1;
        }
        else
        {
            return arr[top];
        }
    }

    void display()
    {
        for (int i = top; i > -1; i--)
        {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
};
