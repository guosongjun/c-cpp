#include<iostream>
using namespace std;
//timeϵͳʱ��ͷ�ļ�����
#include<ctime>

int main2()
{
	//������������  ���� ���õ�ǰϵͳʱ�����������,��ֹÿ���������һ��
	srand((unsigned int)time(NULL));

	//1 ϵͳ���������
	int num = rand() % 100 + 1;	// rand()%100+1  s���� 0+1 ~ 99+1 �����
	//cout << num << endl;


	//2 ��ҽ��в²�
	int val = 0;//�������´������
	cout << "��������µ���" << endl;

	
	while (1) 
	{
		cin >> val;
		//3�ж���ҵĲ²�
		
		//�´� ��ʾ�µĽ�� ������߹�С ���·��ص�2��
		if (val > num)
		{
			cout << "�²����" << endl;
		}
		else if (val < num)
		{
			cout << "�²��С" << endl;
		}
		else
		{
			cout << "�¶���" << endl;
			//�¶�  �˳���Ϸ
			break;// break �������øĹؼ������˳���ǰѭ��
		}
	}


	//�¶� �˳���Ϸ
	



	system("pause");
	return  0;
}
