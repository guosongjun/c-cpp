/*



运算符 
	1.什么是运算符 运算符的作用
		基本的运算所用的符号  比如 +  两个数字相加运算
		对数据进行基本的运算


	2.注意事项

		运算符符号  + - * / %
				17%3
			
		运算符含义\
		优先级  1+2*3
			计算的顺序 (15层 记不下来)  不认识的运算符 -->记得查表
			(1+2)*3要么加()
	
	3.运算符计算规则
		3.1 算数运算符
			+ - * / %
			除法  1.0 /2 ---->0.5
				整数相除  的到的结果是整数  3/4 (不会四舎五入)

		printf 中 %f 和%lf 效果一样的

				% 求余(取模)	求余数(只能是两个整数才可以求余)

				3%4   3   (可以理解位  3个苹果分给4个小朋友   不够分 余3个苹果)


			双目  3+4 两个数据相加
			从左往右  1+2+3+4*5



		3.2 关系运算符  和逻辑运算符
		 > < >= <= == !=  比较两个数据的大小  的到比较结果
		 比较左右两端的数据  3<4 成立就是真(1) 不成立 假(0)
		 非0为真

		 == 比较两端的数据是否相等(一个=是赋值运算符  不要弄错了)


		分支语句  用做条件 循环条件
		三目运算符  用做条件


		3<10<5   1<5
		3<x<5 

		逻辑运算符  作用链接关系运算符的

		x必须是比3大  并且比15小
		
		逻辑或  || 表示左右两个条件成立一个还行  两个都不为真  结果就是假
			10<9||3>2    有真则真
			(截断)只要是左边的条件为真   右边不需要判断条件

		逻辑与 && 左右两端 有一个条件成立  结果位就为假
			10<9&&3>2
			 
			
			

		逻辑非

	
	
	
	
	
	
*/



#include<stdio.h>
int main()
{
	



	gitchar();
	return 0;

}
