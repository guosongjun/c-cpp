#include<iostream>
using namespace std;

int main1()
{
	//ѡ��ṹ    ���� if ���
	//�û��������,�������600,��Ϊ����һ����ѧ, ����Ļ�����

	//1.�û�����ķ���
	int score = 0;
	cout << "������һ������:" << endl;
	cin >> score;

	//2.��ӡ�û�����ķ���
	cout << "������ķ���Ϊ:" << score << endl;

	//3.�жϷ����Ƿ����600 ,�������,��ô���
	//ע������,if�������治Ҫ�ӷֺ�
	if (score > 600)
	{
		cout << "��ϲ�㿼��һ��" << endl;
	}
	system("pause");
	return  0;
}
