#include <iostream>
using namespace std;

class student
{public:
	student(int a, string y, int z);
	void ChangeScore(int c);
	static void GetAverage();
private:
	int id;
	string name;
	int score;
	static float total;
	static int count;
};

float student::total = 0;
int   student::count = 3;

student::student(int x, string y, int z)
{
	id = x;
	name = y;
	score = z;
	total += score;
}

void student::ChangeScore(int c)
{
	total = total - score + c;
	score = c;
}

void student::GetAverage()
{
	float ave;
	ave = total / count;
	cout << "平均值为:"<< ave << endl;
}

int main()
{   
	student a1(1,"wodefa",80 );
	student a2(2,"sss",80 );
	student a3(3,"dw",80 );
	a2.ChangeScore(90);
	a3.ChangeScore(100);
	a3.GetAverage();
	return 0;
}
/*
	   a1.total = 0; 在代码中，a1.total = 0; 这行代码无法访问 total 是因为 total 是静态数据成员，
       它属于类，而不是属于对象。
	   静态数据成员在类的所有对象之间共享，并且只能通过类名来访问。
	   要修改静态数据成员的值，应该使用类名来进行操作，而不是通过对象名。
	   在你的代码中，可以通过 student::total = 0; 来对 total 进行赋值。
	   这样修改后的代码可以正确地访问和修改静态数据成员 total。
*/
