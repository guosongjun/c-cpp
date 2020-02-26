#include<iostream>
using namespace std;

int main()
{
	//break的使用时机
	//1.出现在switch语句中
	cout << "请选择副本难度" << endl;
	cout << "1.普通" << endl;
	cout << "2.中等" << endl;
	cout << "3.困难" << endl;

	int select = 0;
	cin >> select;
	switch (select)
	{
	case 1:
		cout << "普通难度" << endl;
		break;
	case 2:
		cout << "中等难度" << endl;
		break;
	case 3:
		cout << "困难难度" << endl;
		break;
	default:
		break;
	}

	//2.出现在循环语句中
	while (10)
	{
		cout << "    循环" << endl;
	}
	//3.出现在嵌套循环语句中

	system("pause");
	return  0;
}
