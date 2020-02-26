#pragma once
#include <string.h>
#include<iostream>
class mystring
{
	char *str;//指针 用于申请内存   存放字符串
	int size;//用来管理内存的大小
public:
	mystring();//构造函数    函数名和类名相同  没有返回值类型  可以有参数      有参数就可以重载
	mystring(char* str);//可以重载
	/*
	构造器(构造函数)  给对象的成员初始化  构造函数  定义变量的时候就会自动调用
	每个对象出生的时候就会自动调用构造函数   每个对象会调用一次构造

	如果写了类  但是没有写构造   自动生成一个没有参数也不做任何事情的构造函数
	没有参数的构造函数 -->默认构造  定义对象不传参数  就调用默认构造函数


	*/

	~mystring();//析构函数

	void copy(char* arr);//字符串拷贝函数
	void show();//打印函数
	void dele();//释放内存函数
};

