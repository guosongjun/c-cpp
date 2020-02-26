#include <iostream>
#include "mystring.h"
/*
类就是私有的结构体  结构体是公有的类
成员函数  this 指针访问当前对象的成员
piblic 公有  private 私有  protected 受保护

字符串类    一串字符   用\0作为结尾 一般是字符数组存放/堆内存
//string类


*/

using namespace std;
int main()
{//
	mystring a;//直接定义对象  调用的无参构造
	a.copy("hello world!");
	a.show();//打印函数
	a.dele();//释放内存

	mystring b("hello");//定义对象的时候  可以在后面加上(参数)  指定调用哪个构造函数
	//mystring c(1, 2);

	cout << "你好" << endl;
	return 0;
}