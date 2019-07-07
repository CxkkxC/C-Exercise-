#include <stdio.h>
#define MaxSize 100
void trans(int d,char b[]) //b用于存放d转换成的二进制数
{	
	char st[MaxSize],ch;
	int i=0,top=-1;
	while (d!=0)
	{	ch='0'+d%2;				//求余数并转换成字符
		top++; st[top]=ch;		//字符ch进栈
		d/=2;					//继续求更高位
	}
	while (top!=-1)
	{	b[i]=st[top];
		top--;					//出栈并存放在数组b中
		i++;
	}
	b[i]='\0';					//加入字符串结束标志
}

void trans_8(int d,char b[]) //b用于存放d转换成的八进制数
{	
	char st[MaxSize],ch;
	int i=0,top=-1;
	while (d!=0)
	{	ch='0'+d%8;				//求余数并转换成字符
		top++; st[top]=ch;		//字符ch进栈
		d/=8;					//继续求更高位
	}
	while (top!=-1)
	{	b[i]=st[top];
		top--;					//出栈并存放在数组b中
		i++;
	}
	b[i]='\0';					//加入字符串结束标志
}
void trans_16(int d,char b[]) //b用于存放d转换成的十六进制数
{	
	char st[MaxSize],ch;
	int i=0,top=-1,s;
	while (d!=0)
	{	ch='0'+d%16;	
		s=int(ch-'0');		//求余数并转换成字符，大于9把字符换为数字
	if(ch>'0'+9)
	ch=char('A'+s-10);//把大于9的数字换为字母
		top++; st[top]=ch;		//字符ch进栈
		d/=16;					//继续求更高位
	}
	while (top!=-1)
	{	b[i]=st[top];
		top--;					//出栈并存放在数组b中
		i++;
	}
	b[i]='\0';					//加入字符串结束标志
}
int main()
{
	int d;
	char str[MaxSize];
	do
	{
		printf("输入一个正整数:");
		scanf("%d",&d);
	} while (d<0);
	trans(d,str);
	printf("对应的二进制数:%s\n",str);
	trans_8(d,str);
		printf("对应的八进制数:%s\n",str);
	trans_16(d,str);
		printf("对应的十六进制数:%s\n",str);

}