#include<iostream>
using namespace std;

int main2()
{
	//��������;
	//1.����ͨ��������ͳ������������ռ���ڴ��С
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << "��������ռ���ڴ�Ϊ:  " << sizeof(arr) << endl;
	cout << "ÿ��Ԫ��ռ���ڴ�ռ�Ϊ " << sizeof(arr[0]) << endl;
	cout << "������Ԫ�صĸ���Ϊ" << sizeof(arr) / sizeof(arr[0]) << endl;

	//����ͨ���������鿴������׵�ַ
	cout << "������׵�ַΪ" << arr << endl;
	cout << "��һ��Ԫ�صĵ�ַ" << arr[0] << endl;
	cout << "�ڶ���Ԫ�صĵ�ַ" << arr[1] << endl;

	//�������ǳ��������Խ��и�ֵ����
	//arr=100;

	system("pause");
	return  0;
}
