#include<iostream>
using namespace std;
//�����Ķ��巽ʽ
//1. #define	�곣��
//2. const���εı���

//1. #define	�곣��
#define day 7
int main4()
{
	//day = 14;//����, day�ǳ���,һ���޸ľͻᱨ��
	cout << "һ�ܹ���:" << day << "��" << endl;

	//2. const���εı���
	const int month = 12;
	//month = 24; //����, const���εı���Ҳ��֮Ϊ����
	cout << "һ���ܹ���:" << month << "���·�" << endl;

	system("pause");
	return 0;
}