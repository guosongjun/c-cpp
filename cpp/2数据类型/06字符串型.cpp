#include<iostream>
#include <string>//��c++�ָ��ַ���ʱ��,Ҫ�������ͷ�ļ�
using namespace std;

int main6()
{
	//1.C�ָ��ַ���
	//ע������  char   �ַ�����  []
	//ע������2  ���ź��� Ҫ��˫���� ���������ַ���
	char str[] = "hello world";
	cout << str << endl;

	cout << "hello world" << endl;

	//2.C++�ָ��ַ���
	//����һ��ͷ�ļ�  #include <string>
	string  str2 = "hello world";
	cout << str2 << endl;

	system("pause");
	return  0;
}
