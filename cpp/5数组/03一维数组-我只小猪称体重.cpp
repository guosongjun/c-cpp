#include<iostream>
using namespace std;

int main3()
{
	//��ֻС�������
	//����5ֻС����������
	int arr[5] = { 0 };
	int max = 0;//�����������ֵ
	//������ֻС�������
	cout << "��������ֻС�������" << endl;
	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
	}
	for (int j = 0; j < 5; j++)
	{
		cout << "���������ֻС�����طֱ���" << arr[j] << endl;

	}
	//�Ƚ���ֻС���������ֻС�����������
	for (int i = 0; i < 5; i++)
	{
		if (arr[i] > max)//���������е�Ԫ�ر����϶������ֵ����,�͸������ֵ
		{
			max = arr[i];

		}

	}
	cout << max << endl;

	system("pause");
	return  0;
}
