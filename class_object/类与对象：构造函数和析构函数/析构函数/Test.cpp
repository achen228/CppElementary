//析构函数是特殊的成员函数。对象在销毁时会自动调用析构函数，完成类的一些资源清理工作。
//1. 析构函数名是在类名前加上字符 ~
//2. 无参数无返回值（析构函数不可以重载）
//3. 一个类有且只有一个析构函数。若未显式定义，系统会自动生成默认的析构函数 
//4. 对象生命周期结束时，C++编译系统系统自动调用析构函数
//5. 编译器生成的默认析构函数，对会自定类型成员调用它的析构函数

//编译器对基本类型不做处理，但对自定义类型->初始化==调用它的析构函数

// 析构函数
#include <iostream>
#include <assert.h>
using namespace std;

typedef int DataType;
class SeqList
{
public:
	// 构造函数
	SeqList(int capacity = 10)
	{
		_p = (DataType*)malloc(capacity * sizeof(DataType));
		assert(_p);
		_size = 0;
		_capacity = capacity;
	}

	// 析构函数
	~SeqList()
	{
		if (_p)
		{
			free(_p);   // 释放堆上的空间            
			_p = NULL;   // 将指针置为空            
			_capacity = 0;
			_size = 0;
		}
	}

private:
	int* _p;
	int _size;
	int _capacity;
};

int main()
{

	system("pause");
	return 0;
}
