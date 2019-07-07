#include<iostream>
#include<malloc.h>
#include<string.h>
#define front head
using namespace std;
typedef int ElemType;
typedef struct Lnode {
  char data[10];
  struct Lnode *next;
} QType;
typedef struct
{
  QType * front;
  QType * rear;
} LQueue;
// -----��ʼ����������-----
void InitQueue(LQueue * &lq) {
  lq = (LQueue *) malloc(sizeof(LQueue));
  lq->rear = lq->front = NULL;
}
// -----��ٶ���-----
void DestroyQueue(LQueue * &lq) {
  QType *pre = lq->front, *p;
  if (pre != NULL) {
    if (pre == lq->rear)
      free(pre);
    else {
      p = pre->next;
      while (p != NULL) {
        free(pre);
        pre = p;
        p = p->next;
      }
      free(pre);
    }

  }
  free(lq);
}
// -----��������㷨-----
void EnQueue(LQueue * &lq, char x[]) {
  QType *s;
  s = (QType *) malloc(sizeof(QType));
  strcpy(s->data, x);
  s->next = NULL;
  if (lq->front == NULL)
    lq->rear = lq->front = s;
  else {
    lq->rear->next = s;
    lq->rear = s;
  }
}
// -----�������-----
int DeQueue(LQueue * &lq, char x[]) {
  QType *p;
  if (lq->front == NULL)
    return 0;
  p = lq->front;
  strcpy(x, p->data);
  if (lq->rear == lq->front)
    lq->rear = lq->front = NULL;
 else
    lq->front = lq->front->next;
    free(p);
  return 1;
}
// ----�ж϶ӿ������㷨----
int QueueEmpty(LQueue * lq) {
  if (lq->front == NULL)
    return 1;
  else
    return 0;
}
// ----����������Ԫ��-----
int DispQueue(LQueue * lq) {
  QType *p;
  if (QueueEmpty(lq))
    return 0;
  else {
    p = lq->front;
    while (p != NULL) {
      cout << p->data;
      p = p->next;
    }
    cout << endl;
    return 0;
  }
}