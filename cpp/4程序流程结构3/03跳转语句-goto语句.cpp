#include<iostream>
using namespace std;

int main()
{
	//goto 语句
	cout << "1.xxxxx" << endl;

	cout << "2.xxxxx" << endl;

	goto FLAG;//构建 标记   程序员到这寻找标记 接下来直接跳转到标记出

	cout << "3.xxxxx" << endl;

	cout << "4.xxxxx" << endl;
	
	FLAG://标记   直接跳转的这
	cout << "5 .xxxxx" << endl;


	system("pause");
	return  0;
}
