#include<iostream>
#include<malloc.h>
#include<string>
#include"LQueue.h"
using namespace std;
int main(){
	int sel,flag=1;
	char name[10];
	LQueue *lq;
	InitQueue(lq);
	while(flag==1){
		cout<<"1���Ŷ�  2����ҽ��  3:�ŶӲ鿴  0���°�   ������ѡ��";
		cin>>sel;
		switch(sel)
		{
		case 0:
			if(!QueueEmpty(lq))
				cout<<">>���ŶӵĻ��������ҽ��"<<endl;
			DestroyQueue(lq);
			flag=0;
			break;
		case 1:
			cout<<"�����뻼������";
			cin>>name;
			EnQueue(lq,name);
			break;
		case 2:
			if(!DeQueue(lq,name))
				cout<<">>û���ŶӵĻ���"<<endl;
			else
				cout<<"����"<<name<<"��ҽ��"<<endl;
			break;
		case 3:
			cout<<">>�Ŷӻ��ߣ�";
			if(!DispQueue(lq))
				cout<<">>û���ŶӵĻ���"<<endl;
			break;
		}
	}
	return 0;
}