#include<iostream>
using namespace std;
int main2()
{
	//整型: short(2) int(4) long(4)  long long (8)
	//可以利用 sizeof 关键字可以统计数据类型所占内存大小

	//语法: 	sizeof(数据类型 / 变量)
	short num1 = 10;
	cout << "short 类型所占的内存空间: " << sizeof(short) << endl;
	cout << "short 类型所占的内存空间: " << sizeof(num1) << endl;
	
	int num2 = 10;
	cout << "int 类型所占的内存空间: " << sizeof(int) << endl;
	cout << "int 类型所占的内存空间: " << sizeof(num2) << endl;
	
	long num3 = 10;
	cout << "long 类型所占的内存空间: " << sizeof(long) << endl;
	cout << "long 类型所占的内存空间: " << sizeof(num3) << endl;
	
	long long num4 = 10;
	cout << "long long 类型所占的内存空间: " << sizeof(long long) << endl;
	cout << "long long 类型所占的内存空间: " << sizeof(num4) << endl;

	//整型大小比较
	//short < int <= long <= long long
	system("pause");
	return  0;
}
