#include <iostream>
using namespace std;

class Person
{
public:
	Person(string a):name(a){}
	~Person(){}
protected:
	string name;
};

class Student :virtual public Person
{
public:
	Student(string a,int b ,string c) :num(b) , major(c),Person(a){}
	void ShowInfo()
	{
		cout << "姓名:" << name << endl;
		cout << "学号:" << num << endl;
		cout << "专业:" << major << endl<<endl;
	
	}
	~Student(){}
protected:
	int num;
	string major;
};


class Teacher :virtual public Person
{
public:
	Teacher(string a,int b, string c, string d, int e) :t_num(b), title(c), coures(d), n_cou(e),Person(a){}
	void ShowInfo()
	{
		cout << "姓名:" <<Teacher:: name << endl;
		cout << "证件号:" << t_num << endl;
		cout << "职称:" << title << endl;
		cout << "课程:" << coures << endl;
		cout << "周课时数:" << n_cou << endl<<endl;
	}
	~Teacher(){}
protected:
	int t_num;
	string title;
	string coures;
	int n_cou;
};


class TA:public Teacher,public Student
{public:
   TA( string a,int b, string c,int f, string g, string d, int h) :Person(a),Student(a,b, c), Teacher(a,f,g,d,h){}
   void ShowInfo()
   {  
	   cout << "姓名:" << name << endl;
	   cout << "学号:" << num << endl;
	   cout << "专业:" << major << endl;
	   cout << "课程:" << coures << endl;
	   cout << "周课时数:" << n_cou << endl<< endl;
   }
   ~TA() {}
};

int main()
{
	Student a("wushuai", 11, "电子");
	Teacher b("mshan", 1999, "c++", "设计", 1);
	TA c("wushai", 11, "电子", 1999, "c++", "c++设计", 1);
	a.ShowInfo();
	b.ShowInfo();
	c.ShowInfo();
	return 0;
}
