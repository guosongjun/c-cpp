#include "mystring.h"


mystring::mystring()
{
	std::cout << "���й��캯��1" <<std:: endl;
	str = nullptr;//c++����  �������� nullptr
	size = 0;
}
mystring::mystring(char* str)
{
	std::cout << "���й��캯��2" << std::endl;
	size = strlen(str) + 1;//�󳤶�
	this->str = new char[size];
	strcpy(this->str, str);
}

mystring::~mystring()
{
}
void mystring::copy(char* arr)//��Ա��������ʵ��  ��Ҫ��ǰ���������
{
	size = strlen(arr) + 1;//�󳤶�    +1  ����Ϊ\0����  Ҫռһ��λ��
	str = new char[size];//�����ڴ�
	strcpy(str, arr);//������ֵ
}

void mystring::dele()
{
	delete[]str;
}
void mystring::show()//��ӡ����
{
	std::cout << str << std::endl;
}
