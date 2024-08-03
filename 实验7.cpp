#include <iostream>
using namespace std;

class Undergraduate
{
public:
	Undergraduate(int a,string nam, string wor) { num = a; name = nam; work = wor; }
	void ShowInfo()
	{
		cout << "num:" << num << endl;
		cout << "name:" << name << endl;
		cout << "work:" << work << endl;
	}
protected:
	int num;
	string name;
	string work;
};

class Graduate: public Undergraduate
{
public:
	Graduate(int a, string num, string wor, string tea, int nam):
		Undergraduate(a,num,wor) {teacher = tea; pip_num = nam; }
	void ShowInfo()
	{
		cout << "num:" << num << endl;
		cout << "name:" << name << endl;
		cout << "work:" << work << endl;
		cout << "teacher:" << teacher << endl;
		cout << "pip_num:" << pip_num << endl;
	}
private:
	string teacher;
	int pip_num;
};
int main()
{
	Graduate stu(06,"wbsmusk", "electroic","MsHan" , 5);
	stu.ShowInfo();
	return 0;
}

