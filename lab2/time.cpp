#include <iostream>
using namespace std;

class Clock
{
    int hour;
    int minute;
    int second;

public:
    Clock()
    {
        hour = 0;
        minute = 0;
        second = 0;
    }

    void set_time(int h, int m, int s)
    {
        if (h < 24 && m < 60 && s < 60 && h >= 0 && m >= 0 && s >= 0)
        {
            hour = h;
            minute = m;
            second = s;
        }
        else
        {
            cout << "invalid time" << endl;
        }
    }

    int get_hour()
    {
        return hour;
    }

    int get_minute()
    {
        return minute;
    }

    int get_second()
    {
        return second;
    }

    ~Clock() {}
};

void print_st(Clock time);
void print_ut(Clock time);
void print_ist(Clock time);
void print_pst(Clock time);
string time_str(int t);

int main()
{
    Clock time;
    int choice = 0;

    cout << "1. Set Time (UTC)" << endl;
    cout << "2. Print 12-hr format (AM or PM)" << endl;
    cout << "3. Print 24-hr format" << endl;
    cout << "4. Print Indian Standard Time" << endl;
    cout << "5. Print Pacific Standard Time" << endl;
    cout << "6. Exit" << endl;

    while (choice != 6)
    {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int hr, min, sec;
            cout << "Enter Time in 24hr-format (hr min sec): ";
            cin >> hr >> min >> sec;
            time.set_time(hr, min, sec);
            break;

        case 2:
            print_st(time);
            break;

        case 3:
            print_ut(time);
            break;

        case 4:
            print_ist(time);
            break;

        case 5:
            print_pst(time);
            break;

        case 6:
            break;

        default:
            cout << "Invalid Option" << endl;
            break;
        }
    }

    return 0;
}

string time_str(int t)
{
    if (t < 10)
        return "0" + to_string(t);
    else
        return to_string(t);
}

void print_st(Clock time)
{
    int hr = time.get_hour();
    string am_pm;
    if (hr < 12)
        am_pm = "AM";
    else if (hr > 12)
    {
        am_pm = "PM";
        hr -= 12;
    }
    else
        am_pm = "PM";

    cout << "Standard Time (12-hr): ";
    cout << time_str(hr) << ":";
    cout << time_str(time.get_minute()) << ":";
    cout << time_str(time.get_second()) << " ";
    cout << am_pm << endl;
}

void print_ut(Clock time)
{
    cout << "Universal Time (24-hr): ";
    cout << time_str(time.get_hour()) << ":";
    cout << time_str(time.get_minute()) << ":";
    cout << time_str(time.get_second()) << endl;
}

void print_ist(Clock time)
{
    int hr = time.get_hour();
    int min = time.get_minute();

    min += 30;
    if (min >= 60)
    {
        min -= 60;
        hr = (hr + 1) % 24;
    }
    hr = (hr + 5) % 24;

    cout << "Indian Standard Time (24-hr): ";
    cout << time_str(hr) << ":";
    cout << time_str(min) << ":";
    cout << time_str(time.get_second()) << endl;
}

void print_pst(Clock time)
{
    int hr = time.get_hour();
    hr -= 8;
    if (hr < 0)
        hr += 24;

    string am_pm;
    if (hr < 12)
        am_pm = "AM";
    else if (hr > 12)
    {
        am_pm = "PM";
        hr -= 12;
    }
    else
        am_pm = "PM";

    cout << "Pacific Standard Time (12-hr): ";
    cout << time_str(hr) << ":";
    cout << time_str(time.get_minute()) << ":";
    cout << time_str(time.get_second()) << " ";
    cout << am_pm << endl;
}