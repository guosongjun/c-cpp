#include<iostream>
using namespace std;

int main3()
{
	//1.ǰ�õ���
	int a = 10;
	++a;//�ñ���+1  �ȼ��� a=a+1;
	cout << "a=" << a << endl;

	//2.���õ���
	int b = 10;
	b++;
	cout << "b=" << b << endl;

	//3.ǰ�úͺ��õ�����
	//ǰ�õ��� ���ñ���++ Ȼ����б��ʽ������
	int a2 = 10;
	int b2 = ++a2 * 10;
	cout << "a2=" <<a2<< endl;
	cout << "b2=" <<b2<< endl;

	//���õ��� �Ƚ��б��ʽ����,���ñ���++
	int a3 = 10;
	int b3 = a3++ * 10;
	cout << "a3=" << a3 << endl;
	cout << "b3=" << b3 << endl;


	//ǰ�õݼ�
	int a4 = 10;
	int b4 = --a4 * 10;
	cout << "a4=" << a4 << endl;
	cout << "b4=" << b4 << endl;
	
	//���õݼ�
	int a5 = 10;
	int b5 = a5-- * 10;
	cout << "a5=" << a5 << endl;
	cout << "b5=" << b5 << endl;
	//ǰ�úͺ��õݼ�������
	//ǰ�õݼ� ���ñ���-- �������ʽ������
	int a6 = 10;
	int b6 = --a6 * 10;
	cout << "a6=" << a6 << endl;
	cout << "b6=" << b6 << endl;

	//���õݼ� �������ʽ������ ���ñ���--
	int a7 = 10;
	int b7 = a7-- * 10;
	cout << "a7=" << a7 << endl;
	cout << "b7=" << b7 << endl;

	system("pause");
	return  0;
}
