#include <iostream>
#include <cmath>
using namespace std;

class Coordinate
{
    double xnum, ynum;

public:
    Coordinate(double xnum = 0.0, double ynum = 0.0)
    {
        this->xnum = xnum;
        this->ynum = ynum;
    }

    double length(Coordinate pnt)
    {
        Coordinate temp;
        temp = (*this - pnt) ^ 2;
        return sqrt(temp.xnum + temp.ynum);
    }

    bool isRight(Coordinate pnt1, Coordinate pnt2)
    {
        double l1, l2, l3;
        l1 = pow(this->length(pnt1), 2);
        l2 = pow(pnt1.length(pnt2), 2);
        l3 = pow(pnt2.length(*this), 2);
        if (l1 == l2 + l3 || l2 == l3 + l1 || l3 == l1 + l2)
            return true;
        else
            return false;
    }

    void operator~()
    {
        if (this->xnum < 0.0)
            this->xnum = -this->xnum;
        if (this->ynum < 0.0)
            this->ynum = -this->ynum;
    }

    Coordinate operator-(Coordinate pnt)
    {
        Coordinate result;
        result.xnum = this->xnum - pnt.xnum;
        result.ynum = this->ynum - pnt.ynum;
        return result;
    }

    Coordinate operator^(double exp)
    {
        Coordinate result;
        result.xnum = pow(this->xnum, exp);
        result.ynum = pow(this->ynum, exp);
        return result;
    }

    friend ostream &operator<<(ostream &out, Coordinate pnt);
    friend istream &operator>>(istream &in, Coordinate &pnt);
};

istream &operator>>(istream &in, Coordinate &pnt)
{
    in >> pnt.xnum >> pnt.ynum;
    ~pnt;
    return in;
}

ostream &operator<<(ostream &out, Coordinate pnt)
{
    out << "(" << pnt.xnum << "," << pnt.ynum << ")";
    return out;
}

int main()
{
    int choice = 0;
    cout << "1. Set Point" << endl;
    cout << "2. Display Point" << endl;
    cout << "3. Display Length" << endl;
    cout << "4. Check Right Triangle" << endl;
    cout << "5. Exit" << endl;

    Coordinate pnt1, pnt2, pnt3;

    while (choice != 5)
    {
        cout << "\nChoice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Set (x y):" << endl;
            cout << "\tPoint 1: ";
            cin >> pnt1;
            cout << "\tPoint 2: ";
            cin >> pnt2;
            cout << "\tPoint 3: ";
            cin >> pnt3;
        }
        else if (choice == 2)
        {
            cout << "Point 1: " << pnt1 << endl;
            cout << "Point 2: " << pnt2 << endl;
            cout << "Point 3: " << pnt3 << endl;
        }
        else if (choice == 3)
        {
            cout << "Distances between: " << endl;
            cout << "\tPoint 1 and Point 2: " << pnt1.length(pnt2) << endl;
            cout << "\tPoint 2 and Point 3: " << pnt2.length(pnt3) << endl;
            cout << "\tPoint 3 and Point 1: " << pnt3.length(pnt1) << endl;
        }
        else if (choice == 4)
        {
            if (pnt1.isRight(pnt2, pnt3))
            {
                cout << "The Points form a Right Triangle" << endl;
            }
            else
            {
                cout << "The Points does not form a Right Triangle" << endl;
            }
        }
        else if (choice == 5)
        {
            cout << "Exiting..." << endl;
        }
        else
        {
            cout << "Invalid Choice" << endl;
        }
    }
}