#include<iostream>
#include <string>//用c++分格字符串时候,要包含这个头文件
using namespace std;

int main6()
{
	//1.C分格字符串
	//注意事项  char   字符串名  []
	//注意事项2  括号后面 要用双引号 包含起来字符串
	char str[] = "hello world";
	cout << str << endl;

	cout << "hello world" << endl;

	//2.C++分格字符串
	//包含一个头文件  #include <string>
	string  str2 = "hello world";
	cout << str2 << endl;

	system("pause");
	return  0;
}
