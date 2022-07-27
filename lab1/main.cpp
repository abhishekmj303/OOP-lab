#include <iostream>
#include "stack.h"
using namespace std;

void push_num(stack &stk, int num);
void dig2txt(stack stk);
bool palindrome(stack stk);
void reverse(stack stk);

int main()
{
    int choice = 0, num;
    stack stk;
    
    cout << " 1. Get Number\n 2. Digit in Text\n 3. Reverse\n 4. Palindrome Check\n 5. Exit\n";
    while (choice != 5)
    {
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter the number (max 5 digits): ";
                cin >> num;
                push_num(stk, num);
                break;
            case 2:
                dig2txt(stk);
                break;
            case 3:
                reverse(stk);
                break;
            case 4:
                bool isPalin = palindrome(stk);
                if (isPalin)
                    cout << "The number is a palindrome" << endl;
                else
                    cout << "The number is not a palindrome" << endl;
        }
        cout << endl;
    }

    return 0;
}

void push_num(stack &stk, int num)
{
    while (num != 0)
    {
        stk.push(num % 10);
        num /= 10;
    }
}

void dig2txt(stack stk)
{
    cout << "Digit in Text: ";
    while (!stk.isEmpty())
    {
        switch (stk.pop())
        {
            case -1:
                return;
            case 0:
                cout << "Zero";
                break;
            case 1:
                cout << "One";
                break;
            case 2:
                cout << "Two";
                break;
            case 3:
                cout << "Three";
                break;
            case 4:
                cout << "Four";
                break;
            case 5:
                cout << "Five";
                break;
            case 6:
                cout << "Six";
                break;
            case 7:
                cout << "Seven";
                break;
            case 8:
                cout << "Eight";
                break;
            case 9:
                cout << "Nine";
                break;
        }
        cout << " ";
    }
    cout << endl;
}

void reverse(stack stk)
{
    stack temp;
    while (!stk.isEmpty())
    {
        temp.push(stk.pop());
    }
    cout << "Reversed number: ";
    while (!temp.isEmpty())
    {
        cout << temp.pop();
    }
    cout << endl;
}

bool palindrome(stack stk)
{
    stack temp1 = stk, temp2;
    int size = 0;
    while (!stk.isEmpty())
    {
        temp2.push(stk.pop());
        size++;
    }

    for (int i = 0; i < size/2; i++)
    {
        if (temp1.pop() != temp2.pop())
            return false;
    }
    return true;
}