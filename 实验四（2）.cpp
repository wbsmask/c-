#include <iostream>
using namespace std;

class Time
{
public:
    Time();
    void get();
    void show() const;
private:
    int years;
    int months;
    int days;
};

Time::Time() 
{
    years = 2024;
    months = 4;
    days = 22;
}

void Time::get()
{
    cin >> years;
    cin >> months;
    cin >> days;
}

void Time::show() const
{
    cout << years << ":" << months << ":" << days << endl;
}

int main()
{
    Time a;
    Time b;
    const Time* p;
    Time* const q=&a;
    p = &a;
    p = &b;
    (*p).show();
    (*q).get();
    (*q).show();
    return 0;
}
