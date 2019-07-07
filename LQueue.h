#include<iostream>
#include<malloc.h>
#include<string.h>
using namespace std;
typedef int ElemType;
typedef struct Lnode
{
	char data[10];
	struct Lnode * next;
}QType;
typedef struct
{
	QType * front;
	QType * rear;
}LQueue;

//-----初始化队列运算-----
void InitQueue(LQueue *&lq)
{
	lq = (LQueue *)malloc(sizeof(LQueue));
	lq -> rear = lq -> front = NULL;
}
//-----销毁队列-----
void DestroyQueue(LQueue *&lq)
{
	QType *pre = lq -> front,*p;
	if(pre!=NULL)
	{
		if(pre == lq->rear)
			free(pre);
		else 
		{
			p = pre ->next;
			while(p!=NULL){
				free(pre);
				pre = p;p = p->next;
			}
			free(pre);
		}
		
	}
	free(pre);
}
//-----进队运算算法-----
void EnQueue(LQueue *&lq,char x[])
{
	QType *s;
	s = (QType *)malloc(sizeof(QType));
	strcpy(s->data,x);
	s->next = NULL;
	if(lq -> front == NULL)
		lq ->rear = lq->front = s;
	else
	{
		lq->rear->next = s;
		lq->rear= s;
	}
}
//-----出队运算-----
int DeQueue(LQueue *&lq,char x[]){
	QType *p;
	if(lq->front==NULL)
		return 0;
	p=lq->front;
	strcpy(x,p->data);
	if(lq->rear == lq->front){
		lq->rear= lq->front = NULL;
	}
	else{
		lq->front = lq->front->next;
		free(p);
	}
	return 1;
}
//----判断队空运算算法----
int QueueEmpty(LQueue *lq)
{
	if(lq->front == NULL) return 1;
	else return 0;
}
//----输出队中所有元素-----
int DispQueue(LQueue *lq)
{
	QType *p;
	if(QueueEmpty(lq)) return 0;
	else{
		p= lq->front;
		while(p!=NULL)
		{
			cout<<p->data<<" ";
			p=p->next;
		}
		cout<<endl;
		return 1;
	}
}
