#include<iostream>
using namespace std;

int main1()
{
	//break��ʹ��ʱ��
	//1.������switch�����
	cout << "��ѡ�񸱱��Ѷ�" << endl;
	cout << "1.��ͨ" << endl;
	cout << "2.�е�" << endl;
	cout << "3.����" << endl;

	int select = 0;//����ѡ�����ı���
	cin >> select;//�ȴ��û�����
	switch (select) 
	{
	case 1:
		cout << "��ͨ�Ѷ�" << endl;
		break;
	case 2:
		cout << "�е��Ѷ�" << endl;
		break;
	case 3:
		cout << "�����Ѷ�" << endl;
		break;
	default:
		break;
	}

	//2.������ѭ�������
	for	(int i = 0; i < 10; i++)
	{
		if (i == 5)
		{
			break;
		}
		cout << i << endl;
	}
	//3.������Ƕ��ѭ�������
	for (int i = 0; i < 10; i++)
	{

		
		for (int j = 0; j < 10; j++)
		{
			if (j == 5)
			{
				break;
			}
			cout << "* " ;
			break;
		}
		cout << endl;

	}
	system("pause");
	return  0;
}
