#include<iostream>
using namespace std;

int main6()
{
	//��Ŀ�����
	
	//������������ a b c
	//��a��b�Ƚ�  ���������ֵ��ֵ������c
	int a = 10;
	int b = 20;
	int c = 0;

	c = (a > b ? a : b); 
	cout << "c=" << c << endl;

	//c++����Ŀ��������ص��Ǳ��������Լ�����ֵ

	(a > b ? a:b) = 100;

	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;

	system("pause");
	return  0;
}
