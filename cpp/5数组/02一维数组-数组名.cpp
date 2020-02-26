#include<iostream>
using namespace std;

int main2()
{
	//数组名用途
	//1.可以通过数组名统计整个数组所占用内存大小
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << "整个数组占用内存为:  " << sizeof(arr) << endl;
	cout << "每个元素占用内存空间为 " << sizeof(arr[0]) << endl;
	cout << "数组中元素的个数为" << sizeof(arr) / sizeof(arr[0]) << endl;

	//可以通过数组名查看数组的首地址
	cout << "数组的首地址为" << arr << endl;
	cout << "第一个元素的地址" << arr[0] << endl;
	cout << "第二个元素的地址" << arr[1] << endl;

	//数组名是常量不可以进行赋值操作
	//arr=100;

	system("pause");
	return  0;
}
