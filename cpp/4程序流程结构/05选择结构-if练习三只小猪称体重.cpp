#include<iostream>
using namespace std;

int main5()
{
	//��ֻС������� ���ж��Ǹ�����

	//1������ֻС������ر���
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;

	//���û�������ֻС�������
	cout << "������С��A������" << endl;
	cin >> num1 ;
	
	cout << "������С��B������" << endl;
	cin >> num2;
	
	cout << "������С��C������" << endl;
	cin >> num3;

	cout << "�������С��A=" << num1 << endl;
	cout << "�������С��B=" << num2 << endl;
	cout << "�������С��C=" << num3 << endl;

	//�ж���ֻ����
	//���ж�A��B����
	if (num1 > num2)//A��B��
	{
		if(num1>num3)//A��C��
		{
			cout << "С��A����" << endl;
		}
		else//C��A��
		{
			cout << "С��C����" << endl;
		}
	}
	else//B��A��
	{
		if (num2 > num3)//B��C��
		{
			cout << "С��B����" << endl;
		}
		else //C��B��
		{
			cout << "С��C����" <<endl;

		}
	}


	system("pause");
	return  0;
}
