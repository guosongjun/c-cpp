#include<iostream>
using namespace std;

int main3()
{
	//1.前置递增
	int a = 10;
	++a;//让变量+1  等价于 a=a+1;
	cout << "a=" << a << endl;

	//2.后置递增
	int b = 10;
	b++;
	cout << "b=" << b << endl;

	//3.前置和后置的区别
	//前置递增 先让变量++ 然后进行表达式的运算
	int a2 = 10;
	int b2 = ++a2 * 10;
	cout << "a2=" <<a2<< endl;
	cout << "b2=" <<b2<< endl;

	//后置递增 先进行表达式运算,后让变量++
	int a3 = 10;
	int b3 = a3++ * 10;
	cout << "a3=" << a3 << endl;
	cout << "b3=" << b3 << endl;


	//前置递减
	int a4 = 10;
	int b4 = --a4 * 10;
	cout << "a4=" << a4 << endl;
	cout << "b4=" << b4 << endl;
	
	//后置递减
	int a5 = 10;
	int b5 = a5-- * 10;
	cout << "a5=" << a5 << endl;
	cout << "b5=" << b5 << endl;
	//前置和后置递减的区别
	//前置递减 先让变量-- 在做表达式的运算
	int a6 = 10;
	int b6 = --a6 * 10;
	cout << "a6=" << a6 << endl;
	cout << "b6=" << b6 << endl;

	//后置递减 先做表达式的运算 在让变量--
	int a7 = 10;
	int b7 = a7-- * 10;
	cout << "a7=" << a7 << endl;
	cout << "b7=" << b7 << endl;

	system("pause");
	return  0;
}
