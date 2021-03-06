//运算符重载是具有特殊函数名的函数，也具有其返回值类型，函数名字以及参数列表，其返回值类型与参数列表与普通的函数类似
//作为类成员的重载函数时，其形参看起来比操作数数目少1，成员函数的操作符有一个默认的形参此，限定为第一个形参
//。*，::，sizeof，？：,. 注意以上5个运算符不能重载。这个经常在笔试选择题中出现。    

//运算符重载一般写在类里面，写在类外面将会暴露成员变量

//赋值运算符重载：
//1.有返回值，支持连续赋值
//2.自己给自己赋值的判断检查
//3.传参和传返回值用引用
//4.一个类如果没有显式定义赋值运算符重载，编译器也会生成一个，完成对象按字节序的值拷贝

//运算符重载和赋值运算符重载
#include <iostream>
using namespace std;

class Date
{	
public:
	//bool operator == (Date *this, const Date& d);
	bool operator == (const Date& d)
	{
		return this->_year == d._year
			&& _month == d._month
			&& _day == d._day;
	}

	bool operator < (const Date& d)
	{
		if (_year < d._year)
		{
			return true;
		}
		else if (_year == d._year)
		{
			if (_month < d._month)
			{
				return true;
			}
			else if (_month == d._month)
			{
				if (_day < d._day)
				{
					return true;
				}
			}
		}
		return false;
	}

	//赋值运算符重载
	// d2 = d1;
	void operator = (const Date& d)
	{
		if (this != &d)//防止自己给自己赋值
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
	}

	// d3 = d2 = d1;
	//Date& operator = (const Date& d) //用了两个引用（出了作用域还在），减少两次拷贝构造
	//{
	//	_year = d._year;
	//	_month = d._month;
	//	_day = d._day;
	//	return *this;
	//}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1;
	Date d2;

	d1 == d2;
	//d1.operator == (d2);
	//d1.operator == (&d1, d2);

	d1 < d2;

	d2 = d1; //赋值运算符重载
	Date d3（d1）; //拷贝构造
	Date d4 = d1; //拷贝构造

	system("pause");
	return 0;
}
