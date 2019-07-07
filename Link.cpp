#include<stdio.h>
#include"SLink.h"
#include<iostream>
using namespace std;
 int main() {
  int i;
  ElemType e;
  SLink *L, *A;
  InitList(L);
  InitList(A);
  InsElem(L, 1, 1);
  InsElem(L, 2, 2);
  InsElem(L, 3, 3);
  InsElem(L, 4, 4);
  printf("线性表:");
  // DispList(L);
  // DeleteX(L,8);
  /* DispList(L); i = Increase(L); if (i == 0) cout <<
     "该链表并非递增单链表！" << endl; else cout <<
     "该链表是递增单链表！" << endl; Split(L, A); DispList(L);
     DispList(A); */
  //InsertX(L, 8);
  DispList(L);
  return 0;

}