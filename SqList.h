#include<stdio.h>
/*˳���Ķ���*/
#define MaxSize 100
typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int length;
}SqList;
void InitList(SqList &L) //��ʼ�����Ա������㷨
{	
	L.length = 0;
}
void DestroyList(SqList L)  //�������Ա������㷨
{  }
int GetLength(SqList L)  //�����Ա��������㷨
{
	return L.length;
}
int GetElem(SqList L,int i,ElemType &e)  //�����Ա��е� i ��Ԫ�������㷨
{
	if(i<1 || i>L.length)
		return 0;
	else 
	{	
		e = L.data[i-1];
		return 1;
	}
}
int Locate(SqList L,ElemType x)  //��ֵ���������㷨
{
	int i = 0;
	while(i<L.length && L.data[i]!=x)
		i++;
	if(i>L.length) return (0);
	else return (i+1);
}
int InsElem(SqList &L,ElemType x,int i)  //����Ԫ�������㷨
{
	int j;
	if(i<1 || i>L.length+1) return 0;
	for (j = L.length;j>i;j--)
		L.data[j] = L.data[j-1];
	L.data[i-1] = x;
	L.length++;
	return 1;
}
int DelElem(SqList &L,int i)  // ɾ��Ԫ�������㷨
{
	int j;
	if(i<1 || i>L.length) return 0;
	for (j = i;j < L.length;j++)
		L.data[j-1] = L.data[j];
	L.length--;
	return 1;
}
void DispList(SqList L)  // ���Ԫ��ֵ�����㷨
{
	int i;
	for(i = 0;i<L.length;i++)
		printf("%d",L.data[i]);
	printf("\n");
}
void move(SqList &L) //������ż��ǰ��
{
	int i = 0,j = L.length-1;
	ElemType temp;
	while(i <=j)
	{
		while(L.data[i]%2 == 1) i++;
		while(L.data[j]%2 == 0) j--;
		if(i < j)
		{
			temp = L.data[i];
			L.data[i] = L.data[j];
			L.data[j] = temp;
		}
	}
}
void merge(SqList A,SqList B,SqList &C) //��·�鲢
{
	int i = 0,j = 0, k = 0;
	while(i<A.length && j<B.length)
	{
		if(A.data[i]<B.data[j])
		{
			C.data[k] = A.data[i];
			i++;k++;
		}
		else if(A.data[i]> B.data[j])
		{
			C.data[k] = B.data[j];
			j++;k++;
		}
		else
		{
			C.data[k] = A.data[i];
			i++;k++;
				C.data[k] = B.data[j];
			j++;k++;
		}
	}
	while(i < A.length){
		C.data[k] = A.data[i];
		i++;k++;
	}
	while(i < B.length){
		C.data[k] = B.data[j];
		j++;k++;
	}
}