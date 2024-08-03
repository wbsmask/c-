#include <iostream>
#include <string>
using namespace std;

class student
{
public:
	student() :num(0), name(""), score(0) {}
	student(int a, string b, int c) :num(a), name(b), score(c) {}
	int getnum() { return num; }
	string getname() { return name; }
	int  getscore() { return score; }
	~student() {}
private:
	int num;
	string name;
	int score;
};

class Lesson
{
public:
	Lesson(int id, string name, string teacher) :id(id), name(name), teacher(teacher), count(0) {}
	//增加选课学生信息
	void  AddStudent(int num, string name, int score)
	{
		if (count > 50)
		{
			cout << "选课人数已满" << endl;
		}
		else
			stu[count++] = student(num, name, score);               //count此处的用法**********
	}

	//算课程的及格率
	float  GetPassRate()
	{
		int n = 0;
		for (int i = 0; i < count; i++)
		{
			if (stu[i].getscore() >= 60)
			{
				n++;
			}
		}
		return (float)n / count * 100;
	}

	//显示课程信息
	void  ShowInfo()
	{
		cout << "课程名：" << name << endl << "课号:" << id << endl << "任课老师:" << teacher << endl;
		cout << "选课学生:" << endl;

		for (int i = 0; i < count; i++) {
			cout << "学号：" << stu[i].getnum() << ":" << "姓名：" << stu[i].getname() << ":" << "成绩：" << stu[i].getscore() << endl;
		}
		cout << "及格率：" << GetPassRate() << "%" << endl;
	}

protected:
	int id;
	string name;
	string teacher;
	student stu[50];
	int count;

};


int main()
{   //课程类
	Lesson a(2, "c++", "Mrhan");

	//增加选课学生信息
	a.AddStudent(1, "张", 50);
	a.AddStudent(2, "三", 60);
	a.AddStudent(3, "李", 60);
	a.AddStudent(4, "四", 60);

	//课程信息
	a.ShowInfo();
	return 0;
}

/*默认构造函数是一个不带参数的构造函数。它的作用是初始化类对象的成员变量。
当一个类没有显式定义任何构造函数时，编译器会自动生成一个默认构造函数。
如果类中定义了其他构造函数（带参数的构造函数），但没有定义默认构造函数，那么编译器就不会再自动生成默认构造函数。

默认构造函数的作用
初始化对象成员变量：
默认构造函数通常用于初始化对象的成员变量，
确保它们有合理的初始值。比如在学生类 Student 中，默认构造函数将学号 id 初始化为 0，姓名 name 初始化为空字符串，成绩 grade 初始化为 0.0。
创建数组对象：
默认构造函数在创建对象数组时非常有用。创建对象数组时，每个元素都会使用默认构造函数进行初始化。

关于默认构造函数比较重要的一个知识点就是：当一个类没有显式定义任何构造函数时，编译器会自动生成一个默认构造函数。
如果类中定义了其他构造函数（带参数的构造函数），但没有定义默认构造函数，那么编译器就不会再自动生成默认构造函数。

简单的说就是，只要你在类中自定义了一个构造函数，那么你一般就应该显示的定义一个默认构造函数。
*/

/*为什么必须要student();

在您的代码中，student 类被用作 Lesson 类内部的一个数组类型 student stu[50];。当您定义这个数组时，
C++ 需要知道如何为数组中的每个元素（即每个 student 对象）创建默认的构造函数调用，
因为您可能会在定义数组时或在其他地方（如 AddStudent 函数中）不带任何参数地创建 student 对象。

这就是为什么您必须在 student 类中定义 student();（默认构造函数）的原因。
如果没有默认构造函数，C++ 编译器在尝试创建 student 数组或默认初始化 student 对象时会报错，因为它不知道如何初始化这些对象。*/
