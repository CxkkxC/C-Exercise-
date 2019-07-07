#include<iostream>
using namespace std;
#define MaxSize 100
typedef int ElemType;
typedef struct{
	ElemType data[MaxSize];
	int top;
	}SqStack;

void InitStack(SqStack &st)//初始化栈运算算法
{
	st.top = -1;
	}
	
void DestroyStack(SqStack st)//销毁栈运算算法
{
	}
	
int Push(SqStack &st,ElemType x)//进栈运算算法
{
	if(st.top==MaxSize - 1)
	return 0;
	else
	{
		st.top++;
		st.data[st.top] = x;
		return 1;
		}
	}
	
int Pop(SqStack &st,ElemType &x)//出栈
{
	if(st.top==-1)
	return 0;
	else
	{
		x = st.data[st.top];
		st.top--;
		return 1;
		}
	}
	
int GetTop(SqStack st,ElemType &x)//取栈顶
{
	if(st.top==-1)
	return 0;
	else 
	{
		x = st.data[st.top];
		return 1;
		}
	}
	
int StackEmpty(SqStack st)//判断栈空
{
	if(st.top== -1)
	return 1;
	else
	return 0;
	}
