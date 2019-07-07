#include<iostream>
#include"Circle.h"
#include"TriCircle.h"
using namespace std;
int main()
{
	TriCircle obj;
	obj.c0.Input();	cout<<obj.c0.CArea()<<","<<obj.c0.CLen()<<endl;
	return 0;
	}