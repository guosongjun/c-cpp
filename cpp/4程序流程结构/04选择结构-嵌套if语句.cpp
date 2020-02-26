#include<iostream>
using namespace std;

int main4()
{
	/*
	* 提示用户输入一个高考考试分数,根据分数做如下判断
* 分数如果大于600 视为考上一本,大于500视为考上二本,大于400考上三本 ,其余视为未考上本科;
* 在一本中 如果大于700分 考入北大, 大于650分  考入清华  大于600考入人大
	*/
	//1 提示输入高考分数
	int score = 0;
	cout << "请输入分数" << endl;
	cin >> score;

	//2.显示高考分数
	cout << "你输入的分数为:" << score << endl;

	//判断
	//如果大于600 一本;
		//	如果大于700 考入北大
		//	如果大于650 考入清华
		//	其余    600 人大
	//如果大于500 二本
	//如果大于400 三本
	//其余情况 未考上本科
	if (score > 600)
	{
		cout << "恭喜你考入一本大学" << endl;
		if(score>700)
		{
			cout << "你能考入北大" << endl;	
		}
		else if(score>650)	
		{
			cout << "你能考入清华" << endl;
		}
		else
		{
			cout << "你能考入人大" << endl;
		}
	}
	else if (score > 500)
	{
		cout << "恭喜考入二本" << endl;
	}
	else if (score>400)
	{
		cout << "恭喜你考入三本" << endl;
	}
	else
	{
		cout << "你没考上本科" << endl;
	}


	system("pause");
	return  0;
}
