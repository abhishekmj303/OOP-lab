#include <iostream>
#include <vector>
using namespace std;

class Student
{
protected:
    int roll;
    string name;

public:
    Student()
    {
        roll = -1;
        name = "";
    }

    Student(int roll, string name)
    {
        this->roll = roll;
        this->name = name;
    }

    void virtual display() = 0;
};

class PGStudent : virtual public Student
{
protected:
    string courses[3];

public:
    PGStudent() : Student()
    {
        for (int i = 0; i < 3; i++)
            courses[i] = "";
    }

    PGStudent(int roll, string name, string courses[3]) : Student(roll, name)
    {
        for (int i = 0; i < 3; i++)
            this->courses[i] = courses[i];
    }

    void display()
    {
        for (int i = 0; i < 3; i++)
            cout << "    Course" << i+1 << ": " << courses[i] << endl;
    }
};

class ResearchStudent : virtual public Student
{
protected:
    string course;
    string research_area;

public:
    ResearchStudent()
    {
        course = "";
        research_area = "";
    }

    ResearchStudent(int roll, string name, string course, string research_area) : Student(roll, name)
    {
        this->course = course;
        this->research_area = research_area;
    }

    void display()
    {
        cout << "    Course: " << course << endl;
        cout << "    Research Area: " << research_area << endl;
    }
};

class TA : public PGStudent, public ResearchStudent
{
    string course_assigned;
    string role;

public:
    TA() : PGStudent(), ResearchStudent()
    {
        course_assigned = "";
        role = "";
    }

    TA(int roll, string name, string courses[3], string course_assigned, string role) : Student(roll, name), PGStudent(roll, name, courses)
    {
        this->course_assigned = course_assigned;
        this->role = role;
    }

    TA(int roll, string name, string course, string research_area, string course_assigned, string role) : Student(roll, name), ResearchStudent(roll, name, course, research_area)
    {
        this->course_assigned = course_assigned;
        this->role = role;
    }

    void display()
    {
        cout << endl;
        cout << "Details: " << endl;
        cout << "    Name: " << name << endl;
        cout << "    Roll Number: " << roll << endl;
        cout << "    Course Assigned: " << course_assigned << endl;
        cout << "    Role: " << role << endl;
        if (role == "PG")
        {
            PGStudent::display();
        }
        else if (role == "Research")
        {
            ResearchStudent::display();
        }
    }

    friend int search(vector<TA> &ta, int roll);
};

int search(vector<TA> &ta, int roll)
{
    for (int i = 0; i < ta.size(); i++)
    {
        if (ta[i].roll == roll)
            return i;
    }
    return -1;
}

int main()
{
    int choice;
    cout << "1. Set Details" << endl;
    cout << "2. Display" << endl;
    cout << "3. Exit" << endl;

    vector<TA> ta_array;

    while (choice != 3)
    {
        cout << "\nEnter choice: ";
        cin >> choice;
        
        if (choice == 1)
        {
            int roll, role;
            string name, course_assigned;
            cout << "Set Details:" << endl;
            cout << "    Roll number: ";
            cin >> roll;
            if (search(ta_array, roll) != -1)
            {
                cout << "    Roll number already exists !!" << endl;
                continue;
            }
            cout << "    Name: ";
            cin >> name;
            cout << "    Course assigned: ";
            cin >> course_assigned;
            cout << "    Role: 1. PG  2. Research >> ";
            cin >> role;

            if (role == 1)
            {
                string courses[3];
                for (int i = 0; i < 3; i++)
                {
                    cout << "    Course" << i + 1 << ": ";
                    cin >> courses[i];
                }
                TA temp(roll, name, courses, course_assigned, "PG");
                ta_array.push_back(temp);
            }
            else if (role == 2)
            {
                string course, research_area;
                cout << "    Course: ";
                cin >> course;
                cout << "    Research area: ";
                cin >> research_area;
                TA temp(roll, name, course, research_area, course_assigned, "Research");
                ta_array.push_back(temp);
            }

        }
        else if (choice == 2)
        {
            int roll;
            cout << "Enter Roll number: ";
            cin >> roll;
            int index = search(ta_array, roll);
            if (index == -1)
            {
                cout << "Not found" << endl;
            }
            else
            {
                ta_array[index].display();
            }
        }
        else if (choice == 3)
        {
            cout << "Exiting..." << endl;
        }
        else
        {
            cout << "Invalid choice" << endl;
        }
    }
}