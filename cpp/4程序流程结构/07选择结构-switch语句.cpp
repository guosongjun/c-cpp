#include<iostream>
using namespace std;

int main()
{
	//switch ���
	//����Ӱ���
	//10~9	����
	//8~7	�ǳ���
	//6~5	һ��
	//5����	��Ƭ

	//1 ��ʾ�û�����Ӱ����
	cout << "�����Ӱ����" << endl;

	//2 �û����д��
	int score = 0;
	cin >> score;
	cout << "������ķ���Ϊ " << score << endl;

	//�����û�����ķ�������ʾ�û������
	switch (score)
	{
	case 10:
		cout << "��һ�������Ӱ" << endl;
		break;
	case 9:
		cout << "��һ�������Ӱ" << endl;
		break;
	case 8:
		cout << "��һ���ǳ��õĵ�Ӱ" << endl;
		break;
	case 7:
		cout << "��һ���ǳ��õĵ�Ӱ" << endl;
		break;
	case 6:
		cout << "��һ��һ��ĵ�Ӱ" << endl;
		break;
	case 5:
		cout << "��һ��һ��ĵ�Ӱ" << endl;
		break;
	default:
		cout << "��һ����Ƭ" << endl;
		break;
	}
	//if �� switch ����
	//switch ȱ��  �ж�ʱ��ֻ�������ͻ����ַ���,��������һ������
	//switch �е�  �ṹ����,ִ��Ч�ʸ�

	system("pause");
	return  0;
}
