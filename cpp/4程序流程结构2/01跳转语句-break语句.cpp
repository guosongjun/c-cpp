#include<iostream>
using namespace std;

int main()
{
	//break��ʹ��ʱ��
	//1.������switch�����
	cout << "��ѡ�񸱱��Ѷ�" << endl;
	cout << "1.��ͨ" << endl;
	cout << "2.�е�" << endl;
	cout << "3.����" << endl;

	int select = 0;
	cin >> select;
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
	while (10)
	{
		cout << "    ѭ��" << endl;
	}
	//3.������Ƕ��ѭ�������

	system("pause");
	return  0;
}
