#include<iostream>
using namespace std;

int main8()
{
	//案例九九乘法表
	for (int i = 1; i <= 9; i++)//行
	{cout << endl;
		for (int j = 1; j <= i	; ++j)//列
		{
			cout << j << "*" << i << "=" << j * i<<" ";

			
		}
		cout << endl;

	}

	system("pause");
	return  0;
}
