#include<iostream>
using namespace std;

int main6()
{
	//�����Ӱ���
	//�����1~100����
	for (int i = 0; i <= 100; i++)
	{
		if(i%10==7||i%7==0||i/10==7)//�жϳ���Щ����������
		{
			cout << "������" << endl;//���������־ʹ�ӡ������
		}
		else//�����������־���������
		{
			cout << i << endl;
		}

	}

	system("pause");
	return  0;
}
