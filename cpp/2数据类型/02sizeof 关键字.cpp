#include<iostream>
using namespace std;
int main2()
{
	//����: short(2) int(4) long(4)  long long (8)
	//�������� sizeof �ؼ��ֿ���ͳ������������ռ�ڴ��С

	//�﷨: 	sizeof(�������� / ����)
	short num1 = 10;
	cout << "short ������ռ���ڴ�ռ�: " << sizeof(short) << endl;
	cout << "short ������ռ���ڴ�ռ�: " << sizeof(num1) << endl;
	
	int num2 = 10;
	cout << "int ������ռ���ڴ�ռ�: " << sizeof(int) << endl;
	cout << "int ������ռ���ڴ�ռ�: " << sizeof(num2) << endl;
	
	long num3 = 10;
	cout << "long ������ռ���ڴ�ռ�: " << sizeof(long) << endl;
	cout << "long ������ռ���ڴ�ռ�: " << sizeof(num3) << endl;
	
	long long num4 = 10;
	cout << "long long ������ռ���ڴ�ռ�: " << sizeof(long long) << endl;
	cout << "long long ������ռ���ڴ�ռ�: " << sizeof(num4) << endl;

	//���ʹ�С�Ƚ�
	//short < int <= long <= long long
	system("pause");
	return  0;
}
