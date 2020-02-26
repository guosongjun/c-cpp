#include<iostream>
using namespace std;
int main7()
{
	//1.创建 bool 数据类型
	bool flag = true; //true代表真   1
	cout << flag << endl;//1

	flag = false;	//false代表假	 0
	cout << flag << endl;

	//2.查看bool类型所占内存空间
	cout << "bool类型所占的内存空间 " << sizeof(bool) << endl;


	system("pause");
	return  0;
}
