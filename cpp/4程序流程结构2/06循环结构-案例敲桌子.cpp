#include<iostream>
using namespace std;

int main6()
{
	//敲桌子案例
	//先输出1~100数字
	for (int i = 0; i <= 100; i++)
	{
		if(i%10==7||i%7==0||i/10==7)//判断出那些是特殊数字
		{
			cout << "敲桌子" << endl;//是特殊数字就打印敲桌子
		}
		else//不是特殊数字就输出这个数
		{
			cout << i << endl;
		}

	}

	system("pause");
	return  0;
}
