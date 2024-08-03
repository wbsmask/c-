#include <iostream>
using namespace std;
class Date;       //对Date类的提前引用声明

class Time
{
public:
    void display(Date &b);
    Time(int a, int b, int c) :year(a), month(b), day(c) {};
private:
    int year;
    int month;
    int day;
};
                   
class Date
{
public:
    friend void Time::display(Date &);                                                 //声明为了友元函数
    friend Time;                                                                       //声明为了友元类  Time能调用Date的成员
    Date(int a, int b, int c) :hour(a), min(b), s(c){}
private:
    int hour;
    int min;
    int s;
};

void Time::display(Date &b)               //这一步需要参数
{
    cout << year << ":" << month << ":" << day<<endl;
    cout << b.hour << ":" << b.min << ":" << b.s;         //便于现在调用私有数据
}
int main()
{
    Time a1(2024,5,6);
    Date b2(16,40,5);
    a1.display(b2);
    return 0;
}
