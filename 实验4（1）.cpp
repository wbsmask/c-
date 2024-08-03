#include <iostream>
using namespace std;

class stu 
{
public:
	stu();
	void get();
	void show() const;
private:
	string name;
	int age;
};

stu::stu()
{
	name = "woshuai";
	age = 19;
}

void stu::get()
{
	cin >> name;
	cin >> age;
}

void stu::show() const
{
	cout << name << endl;
	cout << age << endl;
}

int main()
{
	stu const a;
	stu b;
	a.show();
	b.get();
	b.show();
	return 0;
}


