#include <iostream>
#include "mystring.h"
/*
�����˽�еĽṹ��  �ṹ���ǹ��е���
��Ա����  this ָ����ʵ�ǰ����ĳ�Ա
piblic ����  private ˽��  protected �ܱ���

�ַ�����    һ���ַ�   ��\0��Ϊ��β һ�����ַ�������/���ڴ�
//string��


*/

using namespace std;
int main()
{//
	mystring a;//ֱ�Ӷ������  ���õ��޲ι���
	a.copy("hello world!");
	a.show();//��ӡ����
	a.dele();//�ͷ��ڴ�

	mystring b("hello");//��������ʱ��  �����ں������(����)  ָ�������ĸ����캯��
	//mystring c(1, 2);

	cout << "���" << endl;
	return 0;
}