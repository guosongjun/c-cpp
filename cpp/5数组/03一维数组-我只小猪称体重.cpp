#include<iostream>
using namespace std;

int main3()
{
	//五只小猪称体重
	//创建5只小猪体重数组
	int arr[5] = { 0 };
	int max = 0;//用来保存最大值
	//输入五只小猪的体重
	cout << "请输入五只小猪的体重" << endl;
	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
	}
	for (int j = 0; j < 5; j++)
	{
		cout << "你输入的五只小猪体重分别是" << arr[j] << endl;

	}
	//比较五只小猪的体重那只小猪的体重最重
	for (int i = 0; i < 5; i++)
	{
		if (arr[i] > max)//访问数组中的元素比我认定的最大值还大,就更新最大值
		{
			max = arr[i];

		}

	}
	cout << max << endl;

	system("pause");
	return  0;
}
