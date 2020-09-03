//my_strcpy   10分
#include<assert.h>
char* my_strcpy(char* dest, const char* src)//在次优化后    src不可以改变 10分
{
	char* ret=dest;
	assert(dest != NULL);//断言
	assert(src != NULL);//断言  将问题抛出来
	//把src 指向的字符串拷贝到dest指向的空间  ,包含 '\0'字符
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}