#include "mystring.h"


mystring::mystring()
{
	std::cout << "调研构造函数1" <<std:: endl;
	str = nullptr;//c++里面  基本上用 nullptr
	size = 0;
}
mystring::mystring(char* str)
{
	std::cout << "调研构造函数2" << std::endl;
	size = strlen(str) + 1;//求长度
	this->str = new char[size];
	strcpy(this->str, str);
}

mystring::~mystring()
{
}
void mystring::copy(char* arr)//成员函数类外实现  需要在前面加上类名
{
	size = strlen(arr) + 1;//求长度    +1  是因为\0结束  要占一个位置
	str = new char[size];//申请内存
	strcpy(str, arr);//拷贝赋值
}

void mystring::dele()
{
	delete[]str;
}
void mystring::show()//打印函数
{
	std::cout << str << std::endl;
}
