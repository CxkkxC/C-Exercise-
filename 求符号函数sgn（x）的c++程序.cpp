#include<iostream>
using namespace std;

int main()
{
     float x;     //定义一个float型变量x
	 cin >> x;    //从键盘输入变量x的值

	 int sgn;     //定义一个int型变量sgn，用于保存结果

     if(x==0)     //首先将x分为等于0和不等于0两种情况
		 sgn=0;   //x等于0时，sgn=0
	 else         //在x不等于0的情况下，再进一步区分x>0和x<0这两种情况
	 {
	 if(x>0) sgn=1;  //x大于0时，sgn=1
	 else sgn=-1;    //x小于0时，sgn=-1

	 }
	 cout<<sgn<<endl;  // 显示变量sgn的值，即符号函数运算的结果
	 return 0;
 }