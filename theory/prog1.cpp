#include <iostream>
using namespace std;

class B;

class A
{
    int a;

public:
    A(int num)
    {
        a = num;
    }

    friend int add_AB(A, B);
};

class B
{
    int b;

public:
    B(int num)
    {
        b = num;
    }

    friend int add_AB(A, B);
};

int add_AB(A numA, B numB)
{
    return numA.a + numB.b;
}

int main()
{
    A numA(1);
    B numB(20);

    cout << add_AB(numA, numB) << endl;
}