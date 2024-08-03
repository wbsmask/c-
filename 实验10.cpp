#include <iostream>
using namespace std;

class Cshape                                            //抽象类 
{
public:
	virtual void DispAttr() {}                          //图形信息     虚函数 
	virtual float Sarea() const = 0;         			//计算表面积   纯虚函数 
	virtual float Volume() const = 0;       			//体积         纯虚函数 
};

class circle :public Cshape
{
public:
	circle() :r(0) {}
	circle(int a) :r(a) {}

	virtual float Sarea() const {                              //球面积计算 
		return (float)4 * 3.14 * r * r;
	}
	virtual float Volume() const {
		return (float)3.14 * r * r * r * 3.0 / 4;              //球体积计算 
	}
	virtual void DispAttr() {
		cout << "球半径：" << r << endl;
		cout << "球面积为:   " << Sarea() << endl;
		cout << "球体积为:   " << Volume() << endl << endl;
	}
private:
	int r;
};

class cube :public Cshape
{
public:
	cube() :x(0) {}
	cube(int a) :x(a) {}

	virtual float Sarea() const {                     //正方体面积计算 
		return (float)6 * x * x;
	}
	virtual float Volume() const {					  //正方体体积计算
		return (float)x * x * x;
	}
	virtual void DispAttr() {
		cout << "边长：" << x << endl;
		cout << "正方体面积为:" << Sarea() << endl;
		cout << "正方体体积为:" << Volume() << endl << endl;
	}
private:
	int x;
};

class cuboid :public Cshape
{
public:
	cuboid() :x(0), y(0), z(0) {}
	cuboid(int a, int b, int c) :x(a), y(b), z(c) {}
	virtual float Sarea() const {                     //长方体面积计算 
		return (float)x * y * 2 + x * z * 2 + y * z * 2;
	}
	virtual float Volume() const {					  //长方体体积计算
		return (float)x * y * z;
	}
	virtual void DispAttr() {
		cout << "长：" << x << "  " << "宽：" << y << "  " << "高：" << z << endl;
		cout << "长方体面积为:" << Sarea() << endl;
		cout << "长方体体积为:" << Volume() << endl << endl;
	}
private:
	int x;
	int y;
	int z;
};

class cylinder :public Cshape
{
public:
	cylinder() :R(0), h(0) {}
	cylinder(int a, int b) :R(a), h(b) {}
	virtual float Sarea() const {                     //圆柱体面积计算 
		return (float)2 * 3.14 * R * R + 2 * 3.14 * R * h;
	}
	virtual float Volume() const {					  //圆柱体体积计算
		return (float)3.14 * R * R * h;
	}
	virtual void DispAttr() {
		cout << "半径：" << R << "  " << "高：" << h << endl;
		cout << "圆柱体面积为:" << Sarea() << endl;
		cout << "圆柱体体积为:" << Volume();
	}
private:
	int R;
	int h;
};

int main()
{
	//球 
	Cshape* p;
	circle cir(2);
	p = &cir;


	p->DispAttr();
	//正方体
	cube cub(2);
	p = &cub;


	p->DispAttr();
	//长方体
	cuboid cubo(2, 2, 2);
	p = &cubo;


	p->DispAttr();
	//圆柱体
	cylinder cyl(2, 2);
	p = &cyl;
	p->Sarea();
	p->Volume();
	p->DispAttr();
	return 0;
}