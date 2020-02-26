#include<iostream>
using namespace std;

int main1()
{
	//选择结构    单行 if 语句
	//用户输入分数,如果大于600,视为考入一本大学, 在屏幕上输出

	//1.用户输入的分数
	int score = 0;
	cout << "请输入一个分数:" << endl;
	cin >> score;

	//2.打印用户输入的分数
	cout << "您输入的分数为:" << score << endl;

	//3.判断分数是否大于600 ,如果大于,呢么输出
	//注意事项,if条件后面不要加分号
	if (score > 600)
	{
		cout << "恭喜你考上一本" << endl;
	}
	system("pause");
	return  0;
}
