

#   c++基础入门

## 1 c++知识

### 1.2注示

>

	作用：在代码中加一些说明和解释，方便自己或者其他程序员阅读代码
	
	两中格式
		1.单行注释：  //描述信息
			通过放在一行代码的上方，或者一条语句的末尾，对改行代码的说明
		2.多行注释： /*描述信息*/
			通常放在一段代码的上方，对该代码的整体说明
		提示：编译器在编译时，会忽略注释的内容

















### 1.3变量

>1.3变量
>
>>作用:给一段指定的空间起名,方便操作这段内存

>>语法:数据类型  变量名=初始值;
>>
>>示例:

>>```c++
>>#include<iostream>
>>using namespace std;
>>
>>int main()
>>{
>>    //变量存在的意义:方便我们管理内存空间
>>    //变量的定义
>>    
>>    //语法:数据类型  变量名 = 初始值
>>    int a = 10;
>>    cout << "a=" << a << endl;
>>    
>>    system ("pause");
>>    return 0
>>}
>>```
>>
>>



























### 1.4常量

作用:用于记录程序中不可更改的数据

c++定义常量两种方式

1.#define宏常量: #define 常量名  常量数值

* 通常在文件上方定义,表示一个常量

2.const 修饰的变量  const 数据类型  常量名 = 常量值

* 通常在变量定义前加关键字 const ,修饰该变量为常量,不可修改

示例

```c++
#include <iostream>
using namespace std;
//1.宏常量
#define day 7
int main()
{
    cout<<"一周共有"<<day<<"天"<<endl;
    //day=8;//报错,宏常量不可以修改
    
    //2.const修饰的变量
    const int month=12;
    cout <<"一年总共有:"<<month<<"个月份"<<endl;
    //month=24;//报错, 常量是不可修改的
    system ("pause");
    return 0;
}
```















### 1.5关键字

作用:关键字是c++中预先保留的单词(标识符)

* **在定义变量或者常量时候,不要用关键字**

c++关键字入下:

| asm        | do           | if               | return      | typedef  |
| ---------- | ------------ | ---------------- | ----------- | -------- |
| auto       | doubke       | inline           | short       | typeid   |
| bool       | dynamic_cast | int              | signed      | typename |
| break      | else         | long             | sizeof      | union    |
| case       | enum         | mutable          | static      | unsigned |
| catch      | explicit     | namespace        | static_cast | using    |
| char       | export       | new              | struct      | virtual  |
| class      | extern       | operator         | switch      | void     |
| const      | false        | private          | template    | volatile |
| const_cast | float        | protected        | this        | wchar_t  |
| continue   | for          | public           | throw       | while    |
| default    | friend       | register         | true        |          |
| delete     | goto         | reinterpret_cast | try         |          |

提示:在给变量或者常量起名称时候,不要用c++的关键字,否则会产生歧义.













### 1.6标识符命名规则

1.6标识符命名规则

作用:c++规定给标识符 (变量  常量) 命名时,有一套自己的规则

* 标识符不能是关键字
* 标识符只能由字母 数字 下划线组成
* 第一个字符必须为字母或者下划线
* 标识符中字母区分大小写

建议:给标识符命名时,争取做到见名知意的效果, 方便自己和他人的阅读



























## 2 数据类型

c++规定在创建一个变量或者常量时,必须要指定出相应的数据类型,否则无法给变量分配内存

### 2.1 整形

作用:整形变量表示的是**整数类型**的数据

c++中能够表示整型的类型有以下几种方式,**区别在于所占内存空间不同**

| 数据类型           | 占用空间                                      | 取值范围       |
| ------------------ | --------------------------------------------- | -------------- |
| short(短整型)      | 2字节                                         | (-2^15~2^15-1) |
| int (整型)         | 4字节                                         | (2^31~2^31-1)  |
| long(长整型)       | Windows为4字节,Linux为4字节(32位),8字节(64位) | (-2^31~2^31-1) |
| longlong(长长整型) | 8字节                                         | (-2^63~2^63-1) |

```c++
#include<iostream>
using namespace std;
int main()
{
	//整型
	//1.短整形
	short num1 = 10;
	short num = 32768;//显示成-32768
	//2.整型
	int num2 = 10;

	//3.长整型
	long num3 = 10;

	//4.长长整型
	long long num4 = 10;
	cout << "num=  " << num << endl;
	cout << "num1= " << num1 << endl;
	cout << "num2= " << num2 << endl;
	cout << "num3= " << num3 << endl;
	cout << "num4= " << num4 << endl;
	system("pause");
	return  0;
}
```



















### **2.2 sizeof关键字**

作用:利用 sizeof 关键字可以统计数据类型所占内存大小

语法: 	sizeof (数据类型 / 变量)

示例:

```c++
int main()
{
    cout<<"short 类型所占的内存空间: "<<sizeof(short)<<endl;
    cout<<"int 类型所占的内存空间: "<<sizeof(int)<<endl;
    cout<<"long 类型所占的内存空间: "<<sizeof(long)<<endl;
    cout<<"long long 类型所占的内存空间: "<<sizeof(long long)<<endl;
    
    system("pause");
	return 0;
}
```

> 整型结论: short < int <= long <= long long



























### 2.3 实型 (浮点型)

> 作用:用于表示小数
>
> 浮点型变量分为两种:
>
> ​	1.单精度  float
>
> ​	2.双进度	double
>
> 两者的区别在于表示的有效数字范围不同
>
> | 数据类型 | 占用空间 | 有效数字范围    |
> | -------- | -------- | --------------- |
> | float    | 4字节    | 7位有效数字     |
> | double   | 8字节    | 15~16位有效数字 |
>
> 示例:
>
> ```c++
> int main()
> {
>     float f1=3.14f;
>     double d1=3.14;
>     cout<<f1<<endl;
>     cout<<d1<<endl;
> //统计 float 和 double 占用的内存空间
> 	cout << "float 占用的内存空间为: " << sizeof(float) << endl;//4字节
> 	cout << "double 所占的内存空间为: " << sizeof(double) << endl;//8字节
> 
> 	//科学计数法
> 	float f2 = 3e2; //3* 10^2
> 	cout << "f2= " << f2 << endl;
> 
> 	float f3 = 3e-2;//3*0.1^2	
> 	cout << "f3= " << f3 << endl;
>     system("pause");
>     return 0;
> }
> ```
>
> 

















### 2.4 字符型

> 作用:字符型变量用于显示单个字符
>
> 语法: char ch ='a';        关键字    变量名 =初始值;
>
> ​	注意1 :在显示字符型变量时,用单引号将字符括起来,不要用双引号
>
> ​	注意2 :单引号内只能有一个字符 , 不可以用字符串

* c和c++中字符型变量只占用1个字节.

* 字符型变量并不是把字符本身放到内存中存储,而是讲对应的 ASCII 编码放入到内存单元

  

  示例:

  ```c++
  int main()
  {
      char ch='1';
      cout<<ch<<endl;
      cout<<sizeof(char)<<endl;
      
      //ch="abcde";//错误, 不可以用双引号
      //ch='abcde';//错误,单引号内只能有一个字符 
      
      system("pause");
      return 0;
  }
  ```

   ![img](https://img2018.cnblogs.com/blog/787364/201912/787364-20191209152307156-1282162537.png)

  ASCII码大致由以下两部分组成:
  
  * ASCII 非打印控制字符:ASCII 表上的数字0~31分配给控制字符,用于控制像打印机等一些外围设备.
  * ASCII 打印字符: 数字32~126分配了能在键盘上找到的字符,当查看或打印文档时会出现.

[https://www.asciim.cn]: 















### 2.5 转义字符

> 作用:用于表示一些不能显示出来的ASCII字符
>
> 现阶段我们常用的转义字符有 :   \n  \\     \t
>
> | 转义字符 | 含义                                  | ASCII码值(十进制) |
> | -------- | ------------------------------------- | ----------------- |
> | \a       | 报警                                  | 007               |
> | \b       | 退格(BS),将当前位置移到前一列         | 008               |
> | \f       | 换页(FF),麻将当前位置移到下页开头     | 012               |
> | **\n**   | **换行(LF)将当前位置移到下一行开头**  | **010**           |
> | \r       | 回车(CR),将当前位置移到本行开头       | 013               |
> | **\t**   | **水平制表(HT)  (跳到下一个TAB位置)** | **009**           |
> | \v       | 垂直制表(VT)                          | 011               |
> | **\\**   | **代表一个反斜杠字符 " \ "**          | **092**           |
> | \'       | 代表一个单引号(撇号)字符              | 039               |
> | \"       | 代表一个双引号字符                    | 034               |
> | \?       | 代表一个问号                          | 063               |
> | \0       | 代表数字0                             | 000               |
> | \ddd     | 8进制转义字符. d范围0~7               | 3位8进制          |
> | \xhh     | 16进制转义字符,h范围 0~9, a~f, A~F    | 3位16进制         |
>
> 





















### 2.6 字符串型

> 作用:用于表示一串字符
>
> 两种风格
>
> > 1.**C风格字符串** :   char  变量名[ ] = "字符串值"
> >
> > 示例:
> >
> > ```c++
> > int main()
> > {
> >     char str1[] = "hello world";
> >     cout << str1 << endl;
> >     
> >     system("pause");
> >     return 0;
> > }
> > ```
> >
> > 注意:C风格的字符串要用双引号括起来
> >
> > 1.**C++风格字符串** :  string	变量名	=	"字符串值"
> >
> > 示例:
> >
> > ```c++
> > int main()
> > {
> > 	string  str2 = "hello world";
> > 	cout << str2 << endl;
> >     
> >     system ("pause");
> >     return 0;
> > }
> > ```
> >
> > 注意: C++分格字符串,需要加头文件 #include<string>

























### 2.7 布尔类型 bool

> 作用:布尔数据类型代表真或假的值
>
> bool 类型只有两个值:
>
> * true  ---真 (本质是1)

> * false ---假 (本质是0)
>
>   

> **bool类型占*1个字节*大小**
>
> 示例:
>
> ```c++
> int main()
> {
>     bool flag=true;
>     cout<<flag<<endl;//1
>     
>     flag=false;
>     cout<<flag<<endl;//0
>     
>     cout<<"sizeof of bool = "<<sizeof(bool)<<endl;//1
>     
>     system("pause");
>     return 0;
> }
> ```
>
> 





















### 2.8 数据的输入

> 作用: 用于从键盘获取数据
>
> 关键字 :  cin
>
> 语法:   cin >> 变量
>
> 示例:
>
> ```c++
> int main()
> {
>  //整型输入
>  int a=0;
>  cout<<"请输入整型变量: "<<endl;
>  cin>>a;
>  cout<<a<<endl;
>  
>  //浮点型输入
>  double d=0;
>  cout<<"请输入浮点型变量: "<<endl;
>  cin>>d;
>  cout<<d<<endl;
>  
>  //字符型输入
>  char ch=0;
>  cout<<"请输入字符型变量: " <<endl;
>  cin>>ch;
>  cout<<ch<<endl;
> 	
>  //布尔类型   非零及真
> 	bool flag = false;
> 	cout << "请给布尔类型 flag 赋值" << flag << endl;
> 	cin >> flag;
> 	cout << "布尔类型flag=" << flag << endl;
> 	
>  system("pause");
> 	return 0;
> }
> ```
>
> 

















## 3 运算符

### 3.1 算数运算符

> **作用**:用于处理四则运算
>
> 算数运算符包括以下符号:
>
> | 运算符 | 术语       | 示例       | 结果     |
> | ------ | ---------- | ---------- | -------- |
> | +      | 正号       | +3         | 3        |
> | -      | 负号       | -3         | -3       |
> | +      | 加         | 10+5       | 15       |
> | -      | 减         | 10-5       | 5        |
> | *      | 乘         | 10*5       | 50       |
> | /      | 除         | 10/5       | 2        |
> | %      | 取模(取余) | 10%3       | 1        |
> | ++     | 前置递增   | a=2;b=++a; | a=3;b=3; |
> | ++     | 后置递增   | a=2;b=a++; | a=3;b=2  |
> | --     | 前置递减   | a=2;b=--a; | a=1;b=1; |
> | --     | 后置递减   | a=2;b=a--; | a=1;b=2; |
>
> 示例:
>
> ```c++
> #include<iostream>
> using namespace std;
> int main()
> {
> 	//加减乘除
> 	int a1 = 10;
> 	int b1 = 3;
> 	cout << a1 + b1 << endl;
> 	cout << a1 - b1 << endl;
> 	cout << a1 * b1 << endl;
> 	cout << a1 / b1 << endl;//两个整数相除  结果依然是整数,将小数部分去除
> 
> 	int a2 = 10;
> 	int b2 = 20;
> 	cout << a2 / b2 << endl;
> 
> 	int a3 = 10;
> 	int b3 = 0;
> 	//cout<<a3/b3<<endl;//错误!两个数相除,除数是不可以为 0 的 
> 
> 	//两个小数可以相除
> 	double d1 = 0.5;
> 	double d2 = 0.25;
> 	cout << d1 / d2 << endl; //运算的结果也可以是小数
> 
> 	system("pause");
> 	return  0;
> }
> ```
>
> 示例2:
>
> ```c++
> #include<iostream>
> using namespace std;
> int main()
> {
> 	
> 	//取模运算本质 就是求余数
> 	int a1 = 10;
> 	int b1 = 3;
> 	cout << a1 % b1 << endl;
> 
> 	int a2 = 10;
> 	int b2 = 20;
> 	
> 	cout << a2 % b2 << endl;
> 
> 	int a3 = 10;
> 	int	b3 = 0;	
> 	//cout << a3 % b3 << endl;//错误  两个数相除 除数不可以为0,所以也不能取模运算 
> 
> 	//两个小数是不可以做取模运算的
> 	double d1 = 3.14;
> 	double d2 = 1.1;
> 	//
> 	cout << d1 % d2 << endl;//错误
> 
> 	system("pause");
> 	return  0;
> }
> ```
>
> 示例3:
>
> ```c++
> #include<iostream>
> using namespace std;
> 
> int main()
> {
> 	//1.前置递增
> 	int a = 10;
> 	++a;//让变量+1  等价于 a=a+1;
> 	cout << "a=" << a << endl;
> 
> 	//2.后置递增
> 	int b = 10;
> 	b++;
> 	cout << "b=" << b << endl;
> 
> 	//3.前置和后置的区别
> 	//前置递增 先让变量++ 然后进行表达式的运算
> 	int a2 = 10;
> 	int b2 = ++a2 * 10;
> 	cout << "a2=" <<a2<< endl;
> 	cout << "b2=" <<b2<< endl;
> 
> 	//后置递增 先进行表达式运算,后让变量++
> 	int a3 = 10;
> 	int b3 = a3++ * 10;
> 	cout << "a3=" << a3 << endl;
> 	cout << "b3=" << b3 << endl;
> 
> 
> 	//前置递减
> 	int a4 = 10;
> 	int b4 = --a4 * 10;
> 	cout << "a4=" << a4 << endl;
> 	cout << "b4=" << b4 << endl;
> 	
> 	//后置递减
> 	int a5 = 10;
> 	int b5 = a5-- * 10;
> 	cout << "a5=" << a5 << endl;
> 	cout << "b5=" << b5 << endl;
> 	
>     
>     //前置和后置递减的区别
> 	//前置递减 先让变量-- 在做表达式的运算
> 	int a6 = 10;
> 	int b6 = --a6 * 10;
> 	cout << "a6=" << a6 << endl;
> 	cout << "b6=" << b6 << endl;
> 
> 	//后置递减 先做表达式的运算 在让变量--
> 	int a7 = 10;
> 	int b7 = a7-- * 10;
> 	cout << "a7=" << a7 << endl;
> 	cout << "b7=" << b7 << endl;
> 
> 	system("pause");
> 	return  0;
> }
> ```
>
> 

 













### 3.2 赋值运算符

> **作用:** 用于将表达式的值赋给变量
>
> 赋值运算符包括以下几个负号:
>
> | 运算符 | 术语   | 示例      | 结果     |
> | ------ | ------ | --------- | -------- |
> | =      | 赋值   | a=2;b=3;  | a=2;b=3; |
> | +=     | 加等于 | a=0;a+=2  | a=2;     |
> | -=     | 减等于 | a=5;a-=3; | a=2;     |
> | *=     | 乘等于 | a=2;a*=2; | a=4;     |
> | /=     | 除等于 | a=4;a/=2; | a=2;     |
> | %=     | 模等于 | a=3;a%=2  | a=1;     |
>
> 示例:
>
> ```c++
> #include<iostream>
> using namespace std;
> 
> int main()
> {
> 	//赋值运算符
> 	//  =
> 	int a = 10;
> 	a = 100;
> 	cout << "a=" << a << endl;
> 
> 	// +=
> 	a = 10;
> 	a += 2;//a=a+2;
> 	cout << "a=" << a << endl;
> 
> 	// -=
> 	a = 10;
> 	a -= 2;//a=a-2;
> 	cout << "a=" << a << endl;
> 	// *=
> 	a = 10;
> 	a *= 2;//a=a*2;
> 	cout << "a=" << a << endl;
> 	// /=
> 	a = 10;
> 	a /= 2;//a=a/2;
> 	cout << "a=" << a << endl;
> 	// %=
> 	a = 10;
> 	a &= 2;//a=a%2;
> 	cout << "a=" << a << endl;
> 
> 	system("pause");
> 	return  0;
> }
> 
> ```
>
> 















### 3.3 比较运算符

> **作用:**用于表达式的比较,并返回一个真值或者假值
>
> 比较运算符有以下符号:
>
> | 运算符 | 术语     | 示例 | 结果 |
> | ------ | -------- | ---- | ---- |
> | ==     | 相等于   | 4==5 | 0    |
> | !=     | 不等于   | 4!=3 | 1    |
> | <      | 小于     | 4<3  | 0    |
> | >      | 大于     | 4>3  | 1    |
> | <=     | 小于等于 | 4<=3 | 0    |
> | >=     | 大于等于 | 4>=3 | 1    |
>
> 示例
>
> ```c++
> #include<iostream>
> using namespace std;
> 
> int main()
> {
> 	//比较运算符
> 	//	==
> 	int a = 3;
> 	int b = 4;
> 	cout << (a == b )<< endl;//0
> 	//	!=
> 	cout << (a != b) << endl;//1
> 	//	<
> 	cout << (a < b) << endl;//1
> 	//	>	
> 	cout << (a > b) << endl;//0
> 		
> 	//	<=
> 	cout << (a <= b) << endl;	//1
> 	//	>=
> 	cout << (a >= b) << endl;//0  
> 
> 	system("pause");
> 	return  0;
> }
> ```
>
> 









### 3.4 逻辑运算符

> **作用** 用于根据表达式的返回值真值或者假值
>
> 逻辑运算符有以下符号:
>
> | 运算符 | 术语 | 示例   | 结果                                                 |
> | ------ | ---- | ------ | ---------------------------------------------------- |
> | !      | 非   | !a     | 如果a为假,则!a为真;如果a为真.!a为假                  |
> | &&     | 与   | a&&b   | 如果a和b都为真,则结果为真,否则为假                   |
> | \|\|   | 或   | a\|\|b | 如果a和b有一个为真,则结果为真,二者都为假时,结果为假. |
>
> 示例1 :逻辑非    !
>
> ```c++
> #include<iostream>
> using namespace std;
> 
> int main()
> {
> 	//逻辑运算符
> 	//	!   逻辑运算符  非
> 
> 	int a = 10;
> 	//在C++中除了 0 都为真
> 	cout << !a << endl;//0
> 	cout << !!a << endl;
> 
>     system("pause");
> 	return  0;
> }
> ```
>
> 总结:逻辑非        真变假 ,	假变真
>
> 
>
> 
>
> 
>
> 
>
> 
>
> 示例2   逻辑与   &&
>
> ```c++
> #include<iostream>
> using namespace std;
> 
> int main()
> {
> 	//逻辑运算符
> 	//	&&	逻辑运算符  与
> 	int a = 10;
> 	int b = 10;
> 	cout << (a && b) << endl;
> 	 
> 	a = 0;
> 	b = 10;
> 	cout << (a && b) << endl;
> 
> 	a = 0;
> 	b = 0;
> 	cout << (a && b) << endl;
> 
> 	//同真为真   其余为假
> 
> 
> 
> 	system("pause");
> 	return  0;
> }
> 
> ```
>
> 总结:逻辑与    同真为真   其余为假
>
> 
>
> 
>
> 
>
> 
>
> 
>
> 
>
> 
>
> 示例3:	||	逻辑运算符  或
>
> ```c++
> #include<iostream>
> using namespace std;
> 
> int main()
> {
> 	//	||	逻辑运算符  或
> 	int a = 10;
> 	int b = 10;
> 	cout << (a || b) << endl;
> 
> 	a = 0;
> 	b = 10;
> 	cout << (a || b) << endl;
> 
> 	a = 0;
> 	b = 0;
> 	cout << (a || b) << endl;
> 
> 	//逻辑或:  同假为假,   其余为真
> 
> 	system("pause");
> 	return  0;
> }
> ```
>
> 总结:逻辑或:  同假为假,   其余为真

















## 4 程序流程结果

C/C++支持最基本的三种程序运行结果:  **顺序结构    选择结构   循环结构**

* 顺序结构:程序按顺序执行, 不发生跳转
* 选择结构: 依据条件是否满足,有选择的执行相应功能
* 循环结构 依据条件是否满足,循环多次执行某段代码



### **4.1选择结构**

#### **4.1.1  if 语句**

>作用: 执行满足条件的语句
>
>if 语句的三种形式
>
>* 单行格式 if 语句
>* 多行格式 if 语句
>* 多行条件的 if 语句



> 1.单行格式: if  (条件) {条件满足执行的语句 }

><img src="C:\Users\Administrator.PC-20200122YHZE\AppData\Roaming\Typora\typora-user-images\image-20200130170731808.png" alt="image-20200130170731808" style="zoom:80%;" />
>
>示例:1  单行 if语句
>
>```c++
>#include<iostream>
>using namespace std;
>
>int main()
>{
>	//选择结构    单行 if 语句
>	//用户输入分数,如果大于600,视为考入一本大学, 在屏幕上输出
>
>	//1.用户输入的分数
>	int score = 0;
>	cout << "请输入一个分数:" << endl;
>	cin >> score;
>
>	//2.打印用户输入的分数
>	cout << "您输入的分数为:" << score << endl;
>
>	//3.判断分数是否大于600 ,如果大于,呢么输出
>	//注意事项,if条件后面不要加分号
>	if (score > 600)
>	{
>		cout << "恭喜你考上一本" << endl;
>	}
>	system("pause");
>	return  0;
>}
>```
>
>注意: if表达式后面不要加分号



> 2.多行格式 if 语句: if(条件) { 条件满足执行语句 } else { 条件不满足执行的语句 };
>
> <img src="C:\Users\Administrator.PC-20200122YHZE\AppData\Roaming\Typora\typora-user-images\image-20200130175032212.png" alt="image-20200130175032212" style="zoom:80%;" />
>
> 示例:  多行 if语句
>
> ```c++
> #include<iostream>
> using namespace std;
> 
> int main()
> {
> 	//选择结构 - 多行if语句
> 	//输入考试分数,如果分数大于600,视为考上一本大学,在屏幕上输出
> 	//如果没考上一本大学,打印未考上一本大学
> 
> 	//1 输入考试分数
> 	int score = 0;
> 	cout << "请输入考试分数:" << endl;
> 	cin >> score;
> 	//2 提示用户输入的分数
> 	
> 	cout << "您输入的分数为: " << score << endl;
> 
> 	//3 判断 如果大于600 ,打印考上一本,否则打印未考上一本
> 	if (score > 600)
> 	{
> 		cout << "恭喜你考上一本大学" << endl;
> 	}
> 	else
> 	{
> 		cout << "抱歉你未考上一本" << endl;
> 	}
> 
> 
> 	system("pause");
> 	return  0;
> }
> ```
>
> 







> 多条件的 if语句 if (条件1){ 条件1满足执行语句 }else if (条件2){条件2满足执行的语句)...else{都不满足执行的语句} <img src="C:\Users\Administrator.PC-20200122YHZE\AppData\Roaming\Typora\typora-user-images\image-20200130180950099.png" alt="image-20200130180950099"  />
>
> 示例 3: 多条件 if 语句
>
> ```c++
> #include<iostream>
> using namespace std;
> 
> int main()
> {
> 	//选择结构   多条件if语句
> 	//输入考试分数, 如果大于600分 视为考上一本大学,在屏幕上输出
> 	//大于500 视为考上二本大学  屏幕输出
> 	//大于400 视为考上三本大学  屏幕输出
> 	//小于400 视为未考上本科	  屏幕输出
> 
> 	//1 用户输入分数
> 	int score = 0;
> 	cout << "请输入考试分数: " << endl;
> 	cin >> score;
> 
> 	//2.提示用户输入的分数
> 	cout << "您输入的分数为: " << score << endl;
> 	
> 	//判断
> 	//如果大于600 考上一本
> 	//如果大于500 考上二本
> 	//如果大于400 考上三本
> 	//小于400     未考上本科
> 	if (score > 600)
> 	{
> 		cout << "恭喜考入一本" << endl;
> 	}
> 	else if (score>500)
> 	{
> 		cout << "恭喜考入二本" << endl;
> 	}
> 	else if (score>400)
> 	{
> 		cout << "恭喜考入三本" << endl;
> 	}
> 	else
> 	{
> 		cout << "抱歉你没考上大学" << endl;
> 	}
> 	system("pause");
> 	return  0;
> }
> ```







> **嵌套 if 语句:** 在 if 语句中,可以嵌套使用 if 语句   达到更精确的条件判断

> 案例需求:
>
> * 提示用户输入一个高考考试分数,根据分数做如下判断
> * 分数如果大于600 视为考上一本,大于500视为考上二本,大于400考上三本 ,其余视为未考上本科;
> * 在一本中 如果大于700分 考入北大, 大于650分  考入清华  大宇600考入人大
>
> ```c++
> #include<iostream>
> using namespace std;
> 
> int main4()
> {
> 	/*
> 	* 提示用户输入一个高考考试分数,根据分数做如下判断
> * 分数如果大于600 视为考上一本,大于500视为考上二本,大于400考上三本 ,其余视为未考上本科;
> * 在一本中 如果大于700分 考入北大, 大于650分  考入清华  大于600考入人大
> 	*/
> 	//1 提示输入高考分数
> 	int score = 0;
> 	cout << "请输入分数" << endl;
> 	cin >> score;
> 
> 	//2.显示高考分数
> 	cout << "你输入的分数为:" << score << endl;
> 
> 	//判断
> 	//如果大于600 一本;
> 		//	如果大于700 考入北大
> 		//	如果大于650 考入清华
> 		//	其余    600 人大
> 	//如果大于500 二本
> 	//如果大于400 三本
> 	//其余情况 未考上本科
> 	if (score > 600)
> 	{
> 		cout << "恭喜你考入一本大学" << endl;
> 		if(score>700)
> 		{
> 			cout << "你能考入北大" << endl;	
> 		}
> 		else if(score>650)	
> 		{
> 			cout << "你能考入清华" << endl;
> 		}
> 		else
> 		{
> 			cout << "你能考入人大" << endl;
> 		}
> 	}
> 	else if (score > 500)
> 	{
> 		cout << "恭喜考入二本" << endl;
> 	}
> 	else if (score>400)
> 	{
> 		cout << "恭喜你考入三本" << endl;
> 	}
> 	else
> 	{
> 		cout << "你没考上本科" << endl;
> 	}
> 
> 
> 	system("pause");
> 	return  0;
> }
> ```
>
> 
>
> 
>
> 
>
> 
>
> 
>
> 
>
> 
>
> **练习案例:**  三只小猪称体重
>
> 有三只小猪A B C	**请分别输入三只小猪的体重**,并判断那只小猪最重？
>
> <img src="C:\Users\Administrator.PC-20200122YHZE\AppData\Roaming\Typora\typora-user-images\image-20200130222449130.png" alt="image-20200130222449130" style="zoom:80%;" />
>
> 示例：
>
> ```c++
> #include<iostream>
> using namespace std;
> 
> int main()
> {
> 	//三只小猪称体重 ，判断那个最重
> 
> 	//1创建三只小猪的体重变量
> 	int num1 = 0;
> 	int num2 = 0;
> 	int num3 = 0;
> 
> 	//让用户输入三只小猪的体重
> 	cout << "请输入小猪A的体重" << endl;
> 	cin >> num1 ;
> 	
> 	cout << "请输入小猪B的体重" << endl;
> 	cin >> num2;
> 	
> 	cout << "请输入小猪C的体重" << endl;
> 	cin >> num3;
> 
> 	cout << "你输入的小猪A=" << num1 << endl;
> 	cout << "你输入的小猪B=" << num2 << endl;
> 	cout << "你输入的小猪C=" << num3 << endl;
> 
> 	//判断那只最重
> 	//先判断A和B重量
> 	if (num1 > num2)//A比B重
> 	{
> 		if(num1>num3)//A比C重
> 		{
> 			cout << "小猪A最重" << endl;
> 		}
> 		else//C比A重
> 		{
> 			cout << "小猪C最重" << endl;
> 		}
> 	}
> 	else//B比A重
> 	{
> 		if (num2 > num3)//B比C重
> 		{
> 			cout << "小猪B最重" << endl;
> 		}
> 		else //C比B重
> 		{
> 			cout << "小猪C最重" <<endl;
> 
> 		}
> 	}
> 
> 
> 	system("pause");
> 	return  0;
> }
> ```
>
> 















#### 4.1.2 **三目运算符**

> **作用：**通过三目运算符实现简单判断
>
> **语法：** 表达式1？表达式2：表达式3
>
> **解释：**
>
> 如果表达式1的值为真，执行表达式2，返回表达式2的结果
>
> 如果表达式1的值为假，执行表达式3，返回表达式3的结果
>
> **示例：**
>
> ```c++
>  #include<iostream>
> using namespace std;
> 
> int main()
> {
> 	//三目运算符
> 	
> 	//创建三个变量 a b c
> 	//将a和b比较  将变量大的值赋值给变量c
> 	int a = 10;
> 	int b = 20;
> 	int c = 0;
> 
> 	c = (a > b ? a : b); 
> 	cout << "c=" << c << endl;
> 
> 	//c++中三目运算符返回的是变量，可以继续赋值
> 
> 	(a > b ? a:b) = 100;
> 
> 	cout << "a=" << a << endl;
> 	cout << "b=" << b << endl;
> 	cout << "c=" << c << endl;
> 
> 	system("pause");
> 	return  0;
> }
> ```
>
> 









####  **4.1.3	switch 语句**

> 作用:执行多条件分支语句
>
> 语法:
>
> ```c++
> switch(表达式)
> {
>     case 结果1: 
>         执行语句;
>         break;
>         ...
>     default:
>         执行语句;
>         break;
> }
>         
>         
>         
> }
> ```
>
> 示例:
>
> ```c++
> #include<iostream>
> using namespace std;
> 
> int main()
> {
> 	//switch 语句
> 	//给电影打分
> 	//10~9	经典
> 	//8~7	非常好
> 	//6~5	一般
> 	//5以下	烂片
> 
> 	//1 提示用户给电影评分
> 	cout << "请给电影评分" << endl;
> 
> 	//2 用户进行打分
> 	int score = 0;
> 	cin >> score;
> 	cout << "你输入的分数为 " << score << endl;
> 
> 	//根据用户输入的分数来提示用户最后结果
> 	switch (score)
> 	{
> 	case 10:
> 		cout << "是一部经典电影" << endl;
> 		break;
> 	case 9:
> 		cout << "是一部经典电影" << endl;
> 		break;
> 	case 8:
> 		cout << "是一部非常好的电影" << endl;
> 		break;
> 	case 7:
> 		cout << "是一部非常好的电影" << endl;
> 		break;
> 	case 6:
> 		cout << "是一部一般的电影" << endl;
> 		break;
> 	case 5:
> 		cout << "是一部一般的电影" << endl;
> 		break;
> 	default:
> 		cout << "是一部烂片" << endl;
> 		break;
> 	}
> 	//if 和 switch 区别
> 	//switch 缺点  判断时候只能是整型或者字符型,不可以是一个区间
> 	//switch 有点  结构清晰,执行效率高
> 
> 	system("pause");
> 	return  0;
> }
> ```
>
> 注意1: switch 语句中表达式类型只能是整型或者字符型
>
> 注意2: case 里面如果没有 break  那么程序会一直向下执行
>
> 总结: 与 if 语句比  对于多条件判断时  switch 的结构清晰  执行效率高  缺点是 switch 不可以判断区间

















### 4.2 循环结构

#### 4.2.1 while 循环语句

> **作用:**满足循环条件,执行循环语句
>
> **语法:** while (循环条件){循环语句}
>
> **解释:只要循环条件结果为真, 就执行循环语句**
>
> <img src="C:\Users\Administrator.PC-20200122YHZE\AppData\Roaming\Typora\typora-user-images\image-20200131010359274.png" alt="image-20200131010359274"  />
>
> 示例:
>
> ```c++
> #include<iostream>
> using namespace std;
> 
> int main()
> {
> 	//while 循环
> 	//在屏幕中大于0~9 这10个数字
> 	
> 	/*int num = 0;
> 	cout << num << endl;
> 
> 	num++;
> 	cout << num << endl;
> 	
> 	num++;
> 	cout << num << endl;
> 	
> 	num++;
> 	cout << num << endl;
> 	
> 	num++;
> 	cout << num << endl;
> 	
> 	num++;
> 	cout << num << endl;
> 
> 	num++;
> 	cout << num << endl;
> 
> 	num++;
> 	cout << num << endl;
> 	
> 	num++;
> 	cout << num << endl;
> 
> 	num++;
> 	cout << num << endl;
> 
> 	num++;
> 	cout << num << endl;
> 	*/
> 	int num = 0;
> 
> 	//while()中填入循环条件
> 	//注意事项:在写循环一定要避免死循环的出现
> 	while(num<10)
> 	{
> 		cout << num << endl;
> 		num++;
> 	}
> 	
> 	system("pause");
> 	return  0;
> }
> ```
>
> 注意:在执行循环语句的时候,程序必须提供跳出循环的出口,否则出现死循环



> **while循环练习案例:彩数字**
>
> 案例描述:系统随机生成一个1到100之间的数,晚间进行猜测,如果猜错,提示玩家数字过大或者过小 ,如果猜对了恭喜玩家胜利,并退出游戏.

<img src="C:\Users\Administrator.PC-20200122YHZE\AppData\Roaming\Typora\typora-user-images\image-20200131013408053.png" alt="image-20200131013408053" style="zoom:80%;" />



> 逻辑结构图:<img src="C:\Users\Administrator.PC-20200122YHZE\AppData\Roaming\Typora\typora-user-images\image-20200131013531058.png" alt="image-20200131013531058" style="zoom:80%;" />
>
> 示例代码:
>
> ```c++
> #include<iostream>
> using namespace std;
> //time系统时间头文件包含
> #include<ctime>
> 
> int main()
> {
> 	//添加随机数种子  作用 利用当前系统时间生成随机数,防止每次随机数都一样
> 	srand((unsigned int)time(NULL));
> 
> 	//1 系统生成随机数
> 	int num = rand() % 100 + 1;	// rand()%100+1  s生成 0+1 ~ 99+1 随机数
> 	//cout << num << endl;
> 
> 
> 	//2 玩家进行猜测
> 	int val = 0;//玩家输入猜错的数据
> 	cout << "请输入你猜的数" << endl;
> 
> 	
> 	while (1) 
> 	{
> 		cin >> val;
> 		//3判断玩家的猜测
> 		
> 		//猜错 提示猜的结果 过大或者过小 重新返回第2步
> 		if (val > num)
> 		{
> 			cout << "猜测过大" << endl;
> 		}
> 		else if (val < num)
> 		{
> 			cout << "猜测过小" << endl;
> 		}
> 		else
> 		{
> 			cout << "猜对了" << endl;
> 			//猜对  退出游戏
> 			break;// break 可以利用改关键字来退出当前循环
> 		}
> 	}
> 
> 	system("pause");
> 	return  0;
> }
> ```
>
> 











#### 4.2.2 do...while 循环语句

> 作用:满足循环条件,执行循环语句
>
> 语法: do {循环语句}while(循环条件);
>
> 注意:与while的区别在于do...while 会先执行一次循环语句,在判断循环条件
>
> ![image-20200131021200663](C:\Users\Administrator.PC-20200122YHZE\AppData\Roaming\Typora\typora-user-images\image-20200131021200663.png)
>
> 示例: 
>
> ```c++
> #include<iostream>
> using namespace std;
> 
> int main()
> {
> 	//do...while循环
> 	//在屏幕上输出0~9这10个数
> 	int num = 0;
> 	do
> 	{
> 		cout << num << endl;
> 		num++;
> 	} while (num<10);
> 
> 
> 
> 	//while(num<10)
> 	//{
> 	//	cout << num << endl;
> 	//	num++;
> 	//}
> 
> 	system("pause");
> 	return  0;
> }
> ```
>
> 总结:与while 循环区别在于,do...while 先执行一次循环语句,在判断循环条件





练习案例: 水仙花数

案例描述 :水仙花数是指一个3位数,它的每个位上的数字的3次幂之和等于它本身

列入: 1^3+5^3+3^3=153

请利用do...while 语句,求出有3位数中的水仙花数

```c++
#include<iostream>
using namespace std;

int main()
{
	//1.将所有的三位数进行输出 (100~999)
	int num = 100;
	do
	{
	
		//2.在所有三位数中找到水仙花数
		int a = 0;//个位
		int b = 0;//十位
		int c = 0;//百位

		a = num % 10;//获取数字个位
		b = num / 10 % 10;//获取数字的十位
		c = num / 100;//获取数字的百位 
		if (a*a*a+b*b*b+c*c*c==num)//如果是水仙花数 才打印
		{
			cout << num << endl;
		}
		num++;
	
	} while (num<1000 );
	
		
	//	水仙花数     153
	//获取个位		153%10=3	对数字取模于10 可以获取到个位
	//获取十位		153/!0=15	15%10=5 先整除于10,得到两位数 在取模于10 得到十位
	//获取百位		153/100=1	直接整除于100 获取百位

	//判断	个位 ^3	+	十位^3 + 百位^3 = 本身

	system("pause");
	return  0;
}
```

  















#### 4.2.3 for循环语句

作用:满足循环条件,执行循环语句

语法: for(起始表达式;条件表达式;末尾循环表达式){循环语句;}



示例:

```c++
#include<iostream>
using namespace std;

int main()
{
	for(int i=0;i<10;i++)
	{
	cout<<i<<endl;
	}

system ("pause");
    return 0;
}
```

详解: 

![image-20200131145229718](C:\Users\Administrator.PC-20200122YHZE\AppData\Roaming\Typora\typora-user-images\image-20200131145229718.png)

注意:for循环中的表达式,要用分号进行分隔

总结:  while , do...while , for 都是开发中常用的循环语句,for循环结构比较清晰,比较常用













**练习案例 :敲桌子**

案例描述:从1 开始到数字100 ,如果数字个位含有7,或者十位含有7,或者该数字是7的倍数,我们打印敲桌子,其余数字直接打印输出



案例分析:

![image-20200201001730367](C:\Users\Administrator.PC-20200122YHZE\AppData\Roaming\Typora\typora-user-images\image-20200201001730367.png)

```c++
#include<iostream>
using namespace std;

int main()
{
	//敲桌子案例
	//先输出1~100数字
	for (int i = 0; i <= 100; i++)
	{
		if(i%10==7||i%7==0||i/10==7)//判断出那些是特殊数字
		{
			cout << "敲桌子" << endl;//是特殊数字就打印敲桌子
		}
		else//不是特殊数字就输出这个数
		{
			cout << i << endl;
		}

	}

	system("pause");
	return  0;
}
```

















#### 4.2.4 嵌套循环

作用:在循环体中再嵌套一层循环,解决一些实际问题

例如我们想在屏幕中打印如下图片,就需要利用嵌套循环

![image-20200202154842001](C:\Users\Administrator.PC-20200122YHZE\AppData\Roaming\Typora\typora-user-images\image-20200202154842001.png)

示例:

```c++
#include<iostream>
using namespace std;

int main()
{
	//利用嵌套循环打印10*10的星图
	for (int i = 0; i < 10; i++)//外层循环
	{
		for (int j = 0; j <10; j++)//内层循环
		{
			cout << "* " ;
		}
		cout<<endl;
	}

	system("pause");
	return  0;
}

```

**练习案例**:乘法口诀表

案例描述:利用嵌套循环,实现九九乘法表

![image-20200202160036357](C:\Users\Administrator.PC-20200122YHZE\AppData\Roaming\Typora\typora-user-images\image-20200202160036357.png)

```c++
#include<iostream>
using namespace std;

int main()
{
	//案例九九乘法表
	for (int i = 1; i <= 9; i++)//行
	{cout << endl;
		for (int j = 1; j <= i	; ++j)//列
		{
			cout << j << "*" << i << "=" << j * i<<" ";

			
		}
		cout << endl;

	}

	system("pause");
	return  0;
}

```







### 4.3 跳转语句	

#### 4.3.1  break 语句

**作用**:用于跳出 **选择结构** 或者 **循环结构**

break 使用的时机:

* 出现在switch 条件语句中,作用是终止case 并跳出switch
* 出现在循环语句中,作用是跳出当前的循环语句
* 出现在嵌套循环中,跳出最近的内层循环语句

示例: 

```c++
#include<iostream>
using namespace std;

int main1()
{
	//break的使用时机
	//1.出现在switch语句中
	cout << "请选择副本难度" << endl;
	cout << "1.普通" << endl;
	cout << "2.中等" << endl;
	cout << "3.困难" << endl;

	int select = 0;//创建选择结果的变量
	cin >> select;//等待用户输入
	switch (select) 
	{
	case 1:
		cout << "普通难度" << endl;
		break;
	case 2:
		cout << "中等难度" << endl;
		break;
	case 3:
		cout << "困难难度" << endl;
		break;
	default:
		break;
	}

	//2.出现在循环语句中
	for	(int i = 0; i < 10; i++)
	{
		if (i == 5)
		{
			break;
		}
		cout << i << endl;
	}
	//3.出现在嵌套循环语句中
	for (int i = 0; i < 10; i++)
	{

		
		for (int j = 0; j < 10; j++)
		{
			if (j == 5)
			{
				break;
			}
			cout << "* " ;
			break;
		}
		cout << endl;

	}
	system("pause");
	return  0;
}

```









#### 4.3.2 continue 语句

作用:在循环语句中,跳过本次循环中余下尚未执行的语句,继续执行下一次循环

示例:

```c++
#include<iostream>
using namespace std;

int main()
{
    
	//continue语句
	for (int i = 0; i <=100; i++)
	{
		//如果是奇数输出,偶数不输出
		if (i % 2 == 0)//0 2 4 6 8 10 
		{
			continue;//可以筛选条件,执行到此就不在向下执行,执行下一次循环
			//break 会退出循环,而continue 不会
		}
		cout << i << endl;
	}
 
    system("pause");
    return 0;
}
```

注意: continue 并没有使整个循环终止, 而break 会跳出循环















#### 4.3.3 goto 语句

作用: 可以无条件跳转语句

语法: goto 标记;

解释:如果标记的名称存在, 执行到 goto 语句时, 会跳转到标记的位置

示例:

```c++
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
    return 0;
}
```

注意:尽量不要使用goto  语句   以免造成流程混乱.





















## 5 数组

### 5.1概述

所谓数组 ,就是一个集合,里面存放了相同类型的数据元素



特点1:数组中的每个元素都是相同的数据类型

特点2:数组是有连续的存储位置组成的



<img src="D:\c-cpp\学习笔记\数组的特点.png" style="zoom:80%;" />











### 5.2 一维数组

#### **5.2.1 一维数组定义方式**

一维数组定义的三种方式:

> 1. 数据类型  数组名 [ 数组长度];
> 2. 数据类型  数组名[ 数组长度 ] = {值 1,值 2,...};
> 3. 数据类型  数组名[  ] ={ 值1,值2 ,...};

示例:

```c++
#include<iostream>
using namespace std;

int main()
{
	//数组定义方式有以下3种
	/*
	1.数据类型  数组名 [ 数组长度];

	2.数据类型  数组名[ 数组长度 ] = {值 1,值 2,...};

	3.数据类型  数组名[  ] ={ 值1,值2 ,...};
	
	*/
    //
	//1.数据类型 数组名 [数组长度];
	//int arr[5];
	////给数组中的元素进行赋值
	////数组元素的下标是从0开始索引的 
	//arr[0] = 10;
	//arr[1] = 20;
	//arr[2] = 30;
	//arr[3] = 40;
	//arr[4] = 50;

	////访问数据元素

	//cout << arr[0] << endl;
	//cout << arr[1] << endl;
	//cout << arr[2] << endl;
	//cout << arr[3] << endl;
	//cout << arr[4] << endl;


	////2.数据类型 数组名 [数组长度]={值1,值2...};
	//int arr2[5] = { 10,20,30,40,50 };
	//
	////cout << arr2[0] << endl;
	////cout << arr2[1] << endl;
	////cout << arr2[2] << endl;
	////cout << arr2[3] << endl;
	////cout << arr2[4] << endl;

	////利用循环  输出数组中的元素
	//for (int i = 0; i < 5; i++)
	//{
	//	cout << arr2[i] << endl;
	//
	//}

	//3.数据类型  数组名[] = { 值1,值2 ,... };
	//定义数组的时候必须有初始长度
	int arr3[] = { 10,20,30,40,50 };
	for (int i = 0; i < 5; i++)
	{
		cout << arr3[i] << endl;
	}
	system("pause");
	return  0;
}
```

总结1:数组名的命名规范与变量名命名规范一致,不要和变量重名

总结2:数组中的下标是从0开始索引的









#### **5.2.2一维数组数组名**

一维数组名称**用途**:

> 1.可以统计整个数组在内存中的长度
>
> 2.可以获取数组在内存中的首地址

示例:

```c++
#include<iostream>
using namespace std;

int main()
{
	//数组名用途
	//1.可以通过数组名统计整个数组所占用内存大小
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << "整个数组占用内存为:  " << sizeof(arr) << endl;
	cout << "每个元素占用内存空间为 " << sizeof(arr[0]) << endl;
	cout << "数组中元素的个数为" << sizeof(arr) / sizeof(arr[0]) << endl;

	//可以通过数组名查看数组的首地址
	cout << "数组的首地址为" << arr << endl;
	cout << "第一个元素的地址" << arr[0] << endl;
	cout << "第二个元素的地址" << arr[1] << endl;

	//数组名是常量不可以进行赋值操作
	//arr=100;

	system("pause");
	return  0;
}
```













练习案例1:五只小猪比体重

案例描述:

在一个数组中记录五只小猪的体重,如:int arr[5]={300,350,200,400,250};

找出并打印最重的小猪体重

```c++
#include<iostream>
using namespace std;

int main()
{
	//五只小猪称体重
	//创建5只小猪体重数组
	int arr[5] = { 0 };
	int max = 0;//用来保存最大值
	//输入五只小猪的体重
	cout << "请输入五只小猪的体重" << endl;
	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
	}
	for (int j = 0; j < 5; j++)
	{
		cout << "你输入的五只小猪体重分别是" << arr[j] << endl;

	}
	//比较五只小猪的体重那只小猪的体重最重
	for (int i = 0; i < 5; i++)
	{
		if (arr[i] > max)//访问数组中的元素比我认定的最大值还大,就更新最大值
		{
			max = arr[i];

		}

	}
	cout << max << endl;

	system("pause");
	return  0;
}
```













案例2:数组元素逆置

案例描述:请声明一个5个元素的数组,并且将元素逆置

(如原数组元素为:1,3,2,5,4;   逆置后输出结果为:4,5,2,3,1);

```c++
#include<iostream>
using namespace std;

int main()
{

	//实现数组元素逆置
	
	//1.创建数组
	int arr[10] = { 1,5,3,4,6,8,2,9,7,0 };
	cout << "数组逆置前" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i]<< endl;
	}
	//2.实现逆置
	//2.1记录起始下标位置
	//2.2记录结束下标位置
	//2.3起始下标与结束下标的元素互换
	//2.4起始位置++ ,结束位置--
	//2.5循环执行2.1操作 直到起始位置>=结束位置
	
	int start = 0;//起始下标
	int end = sizeof(arr) / sizeof(arr[0])-1;//结束下标
	
	while (start < end)
	{
		//实现元素互换
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		//下标更新
		start++;
		end--;
	}

	//3.打印逆置后的数组
	cout << "数组逆置后" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;

	}
	system("pause");
	return  0;
}
```

















#### 5.2.3 冒泡排序

**作用**:最常用的排序算法,对数组元素进行排序

> 1. 比较相邻的元素,如果第一个比第二个大,就交换他们两个
> 2. 对每个相邻的元素做同样的工作,执行完毕后,找到最大值,
> 3. 重复以上的步骤,每次比较次数-1 直到不需要比较
>
> 4  2  8  0  5  7  1  3  9 
>
> 示例:将数组{4,2,8,0,5,7,1,3,9}进行升序排序
>
> ```c++
> #include<iostream>
> using namespace std;
> 
> int main()
> {
>     //利用冒泡排序实现生序序列
>     int arr[9]={4,2,8,0,5,7,1,3,9};
>     
>     cout<<"排序前:"<<endl;
>     for(int i=0;i<9;i++)
>     {
>         cout<<arr[i]<<endl;
>     }
>     
>     system("pause");
>     return 0;
> }
> ```
>
> 















































































































































































































