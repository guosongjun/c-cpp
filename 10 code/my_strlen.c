//my_strlen   10分
#include<stdio.h>
#include<assert.h> //断言用的头文件
int my_strlen(const char* str)//保证  str 不被修改      10分的代码
{
	int count = 0;
	assert(str != NULL);//断言  保证指针的有效性
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}