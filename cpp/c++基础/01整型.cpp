


#include<iostream>
using namespace std;

int main()
{
	//整型
	//1.短整形(-32768~32767)
	short num1 = 10;
	short num = 32768;//输出成负数了
	//2.整型
	int num2 = 10;
	//3.长整型
	long num3 = 10;
	//4.长长整型
	long long num4 = 10;
	cout << "num=" << num << endl;
	cout << "num1=" << num1 << endl;
	cout << "num2=" << num2 << endl;
	cout << "num3=" << num3 << endl;
	cout << "num4=" << num4 << endl;

	system("pause");
	return 0;
}
