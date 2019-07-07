#include<iostream>
#include<malloc.h>
#include<string>
#include"LQueue.h"
using namespace std;
void main(){
	int sel,flag=1;
	char name[10];
	LQueue *lq;
	InitQueue(lq);
	while(flag==1){
		cout<<"1：排队  2：看医生  3:排队查看  0：下班  \n"<<"请输入选择：";
		cin>>sel;
		switch(sel)
		{
		case 0:
			if(!QueueEmpty(lq))
				cout<<">>请排队的患者明天就医。"<<endl;
			DestroyQueue(lq);
			flag=0;
			break;
		case 1:
			cout<<"请输入患者姓名：";
			cin>>name;
			EnQueue(lq,name);
			break;
		case 2:
			if(!DeQueue(lq,name))
				cout<<">>没有排队的患者"<<endl;
			else
				cout<<"患者 "<<name<<" 看医生"<<endl;
			break;
		case 3:
			cout<<">>排队患者：";
			if(!DispQueue(lq))
				cout<<">>没有排队的患者"<<endl;
			break;
		}
	}
}
