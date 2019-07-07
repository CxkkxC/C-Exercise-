#include<iostream>
#include<conio.h>
#include <unistd.h>
using namespace std;
int main()
{
	int hour = 0;
	int minute = 0;
	int second;
	while (1)
	{
	for (second = 1;second<=3;)
	{
		cout<<"\033[;36;m\n\n                       "<<hour<<":"<<minute<<":"<<second<<"\033[m"<<endl;
		usleep(1000000);
	//	fflush(stdout);
	clrscr();//清屏函数
//	system("CLS");
second++;
		if (second==3)
	{
		minute++;
	if (minute==3)
	hour++;
	}
	}
	}
		return 0;
	}