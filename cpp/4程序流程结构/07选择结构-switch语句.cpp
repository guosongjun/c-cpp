#include<iostream>
using namespace std;

int main()
{
	//switch 语句
	//给电影打分
	//10~9	经典
	//8~7	非常好
	//6~5	一般
	//5以下	烂片

	//1 提示用户给电影评分
	cout << "请给电影评分" << endl;

	//2 用户进行打分
	int score = 0;
	cin >> score;
	cout << "你输入的分数为 " << score << endl;

	//根据用户输入的分数来提示用户最后结果
	switch (score)
	{
	case 10:
		cout << "是一部经典电影" << endl;
		break;
	case 9:
		cout << "是一部经典电影" << endl;
		break;
	case 8:
		cout << "是一部非常好的电影" << endl;
		break;
	case 7:
		cout << "是一部非常好的电影" << endl;
		break;
	case 6:
		cout << "是一部一般的电影" << endl;
		break;
	case 5:
		cout << "是一部一般的电影" << endl;
		break;
	default:
		cout << "是一部烂片" << endl;
		break;
	}
	//if 和 switch 区别
	//switch 缺点  判断时候只能是整型或者字符型,不可以是一个区间
	//switch 有点  结构清晰,执行效率高

	system("pause");
	return  0;
}
