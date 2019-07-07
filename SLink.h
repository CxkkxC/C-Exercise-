#include<stdlib.h>
#include<malloc.h>
#include<iostream>
using namespace std;
typedef int ElemType;
typedef struct node {
	ElemType data;
	struct node *next;
} SLink;

void InitList(SLink * &L) {
	L = (SLink *) malloc(sizeof(SLink));
	L->next = NULL;
}

void DestroyList(SLink * &L) {
	SLink *pre = L, *p = pre->next;
	while (p != NULL) {
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
}

int GetLength(SLink * L) {
	int i = 0;
	SLink *p = L->next;
	while (p != NULL) {
		i++;
		p = p->next;
	}
	return i;
}

int GetElem(SLink * L, int i, ElemType & e) {
	int j = 0;
	SLink *p = L;
	if (i <= 0)
		return 0;
	while (p != NULL && j < i) {
		j++;
		p = p->next;
	}
	if (p == NULL)
		return 0;
	else {
		e = p->data;
		return 1;
	}
}

int Locate(SLink * L, ElemType e) {
	
	SLink *p = L->next;
	int j = 1;
	while (p != NULL && p->data != e) {
		p = p->next;
		j++;
	}
	if (p == NULL)
		return (0);
	else
		return (j);
}

int InsElem(SLink * &L, ElemType x, int i) {
	int j = 0;
	SLink *p = L, *s;
	if (i <= 0)
		return 0;
	while (p != NULL && j < i - 1) {
		j++;
		p = p->next;
	}
	if (p == NULL)
		return 0;
	else {
		s = (SLink *) malloc(sizeof(SLink));
		s->data = x;
		s->next = p->next;
		p->next = s;
		return 1;
	}
}

int DelElem(SLink * &L, int i) {
	int j = 0;
	SLink *p = L, *q;
	if (i <= 0)
		return 0;
	while (p != NULL && j < i - 1) {
		j++;
		p = p->next;
	}
	if (p == NULL)
		return 0;
	else {
		q = p->next;
		if (q == NULL)
			return 0;
		else {
			p->next = q->next;
			free(q);
			return 1;
		}
	}
}

void DispList(SLink * L) {
	SLink *p = L->next;
	while (p != NULL) {
		cout << p->data;
		p = p->next;
	}
	printf("\n");
}

int DeleteX(SLink * &L, ElemType x) {
	SLink *pre = L, *p = pre->next;
	while (p != NULL && p->data != x) {
		pre = p;
		p = p->next;
	}
	if (p != NULL)               {
		pre->next = p->next;
		free(p);
		return 1;
	} 
	else
		return 0;                   }

int Increase(SLink * &L) {
	SLink *p = L->next, *q = p->next;
	while (q != NULL) {
		if (q->data >= p->data) {
			p = q;
			q = q->next;
		} else
			return 0;
	}
	return 1;
}

void Split(SLink * &L, SLink * &A) {
	SLink *s = L->next, *l, *a;
	l = L;
	A = (SLink *) malloc(sizeof(SLink));
	a = A;                        
	while (s != NULL) {          
		if (s->data % 2 == 0) {     
			l->next = s;
			l = s;
			s = s->next;
		} else {
			a->next = s;
			a = s;
			s = s->next;
		}
	}
	l->next = NULL;
	a->next = NULL;
}
void InsertX(SLink * &L, ElemType x) {
	int i = Increase(L);
	if (i == 0) {
		cout<<"no"<<endl;
	} else {
		SLink *p, *s, *q;
		s = (SLink *) malloc(sizeof(SLink));
		s->data = x;
		s->next = NULL;
		if (L == NULL || x < L->data) 		{
			s->next = L;
			L = s;
		} else {
			q = L;
			p = q->next;
			while (p != NULL && x > p->data)
				if (x > p->data) {
					q = p;
					p = p->next;
				}
				s->next = p;
				q->next = s;
		}
	}
