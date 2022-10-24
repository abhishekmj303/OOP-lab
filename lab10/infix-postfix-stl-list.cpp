#include <iostream>
#include <list>
using namespace std;

template <typename T>
class Queue
{
    list<T> q;

public:
    Queue() {}

    void enqueue(T data)
    {
        q.push_back(data);
    }

    T dequeue()
    {
        T data;
        try
        {
            if (q.empty())
            {
                throw 0;
            }
        }
        catch (int ex)
        {
            cout << "Queue is Empty !!" << endl;
            return data;
        }
        
        data = q.front();
        q.pop_front();
        return data;
    }

    bool isEmpty()
    {
        return q.empty();
    }

    int size()
    {
        return q.size();
    }
};

void stackPush(Queue<char> &q, char data)
{
    q.enqueue(data);
}

char stackPop(Queue<char> &q)
{
    Queue<char> next_q;
    while (q.size() != 1)
    {
        next_q.enqueue(q.dequeue());
    }

    char data = q.dequeue();
    q =  next_q;
    return data;
}

string charType(char ch)
{
    if (ch == '+' || ch == '-' || ch == '^' || ch == '*' || ch == '/')
        return "sym";
    else if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        return "alpha";
    else
        return "none";
}

void checkExp(string exp_str)
{
    string prev = "";
    for (int i = 0; i < exp_str.size(); i++)
    {
        string c_type = charType(exp_str[i]);
        if (c_type == "alpha")
        {
            if (prev == "alpha")
                throw i;
            prev = "alpha";
        }
        else if (c_type == "sym")
        {
            if (prev != "alpha")
                throw i;
            prev = "sym";
        }
        else
            throw i;
    }
    if (prev == "sym")
        throw (int)exp_str.size();
}

int precedence(char sym)
{
    if (sym == '+' || sym == '-')
        return 0;
    else if (sym == '*' || sym == '/')
        return 1;
    else
        return -1;
}

string in2post(string infix)
{
    Queue<char> sym_stack;
    string postfix = "";
    for (int i = 0; i < infix.size(); i++)
    {
        string c_type = charType(infix[i]);
        if (c_type == "alpha")
        {
            postfix += infix[i];
        }
        else if (c_type == "sym")
        {
            char stack_top;
            while (!sym_stack.isEmpty())
            {
                stack_top = stackPop(sym_stack);
                if (precedence(stack_top) >= precedence(infix[i]))
                {
                    postfix += stack_top;
                }
                else
                {
                    stackPush(sym_stack, stack_top);
                    break;
                }
            }
            stackPush(sym_stack, infix[i]);
        }
    }

    while (!sym_stack.isEmpty())
    {
        postfix += stackPop(sym_stack);
    }

    return postfix;
}

int main()
{
    string infix = "", postfix;
    int choice = 0;
    cout << "1. Get Infix Expression" << endl;
    cout << "2. Print Infix Expression" << endl;
    cout << "3. Print Postfix Expression" << endl;
    cout << "4. Exit" << endl;

    while (choice != 4)
    {
        cout << "\nEnter Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter Infix Expression: ";
            cin >> infix;

            try
            {
                checkExp(infix);
            }
            catch (int index)
            {
                cout << "Invalid Expression: " << infix << endl;
                cout << "                    ";
                for (int i = 0; i < index; i++)
                    cout << " ";
                cout << "^" << endl;
                infix = "";
            }
        }
        else if (choice == 2 || choice == 3)
        {
            try
            {
                if (infix == "")
                    throw 0;
            }
            catch (int ex)
            {
                cout << "Infix Expression not found !!" << endl;
                continue;
            }

            if (choice == 2)
                cout << "Infix Expression: " << infix << endl;
            else
            {
                postfix = in2post(infix);
                cout << "Postfix Expression: " << postfix << endl;
            }
        }
        else if (choice == 4)
        {
            cout << "Exiting ..." << endl;
            return 0;
        }
        else
        {
            cout << "Invalid Choice: '" << choice << "'\n";
        }
    }
    

    return 0;
}