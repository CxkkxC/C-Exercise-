#include<iostream>
#include <stdlib.h>
using namespace std;
class Value_input
{
public:
		int year()
	{
		int Year;
		while (1)
	{
		cout<<"请输入你的出生年份：";
		cin>>Year;
			if(Year >= 1000 && Year <=2018 )
			break;
			else
			continue;
			}
			return Year;
		}
		int month()
		{
			int Month;
			while (1)
			{
				cout<<"请输入你的出生月份：";
				cin>>Month;
				if(Month >= 1 && Month <=12)
				break;
				else
				continue;
				}
				return Month;
			}
			int day()
			{
				int Day;
				while (1)
			{
				cout<<"请输入你的出生日期：";
				cin>>Day;
				if(Day >= 1 && Day <=31)
				break;
				else
				continue;
				}
				return Day;
				}
	};
	int main()
	{
		Value_input value_input;
	/*	value_input.year();
		value_input.month();
		value_input.day();*/
		int Y,D,M;
		Y = value_input.year();
		M = value_input.month();
		if ( ((0 == Y%4)&&(0 != Y%100)) ||(0 == Y %400))
			1
			/*能被4整除且不能被100整除或者能被400整除的。*/
		{
			while (M==2)
		{
		   D = value_input.day();
		if (D<=29)
			break;
		else
			continue;
			}
			}
	   else if (M==2)
	   {
	   	while (M==2)
	   	{
	   			D = value_input.day();
	   			if (D<=28)
	   			break;
	   			else
	   			continue;
	   		}
	   		}
	   		else
	{
	   D = value_input.day();
	   }
		cout<<"你的出生年月日为:";
		switch (M)
		{
			case 1: cout<<"January,";
			break;
			case 2: cout<<"February,";
			break;
			case 3: cout<<"March,";
			break;
			case 4: cout<<"April,";
			break;
			case 5: cout<<"May,";
			break;
			case 6: cout<<"June,";
			break;
			case 7: cout<<"July,";
			break;
			case 8: cout<<"August,";
			break;
			case 9: cout<<"September,";
			break;
			case 10: cout<<"October,";
			break;
			case 11: cout<<"November,";
			break;
			case 12: cout<<"December,";
			break;
			}
		cout<<D<<","<<Y<<endl;
		system ("pause");
		return 0;
		}