#include<iostream>
#include<cstdlib>
#include <iomanip>
#include"random.h"
// 伪随机数包含头文件
using namespace std;
int main()
{
	double x,y;
	double sum=0;
	for (int i = 1; i <= 10000; i++)
	{
		x=randomReal(-1,1);
		y=randomReal(-1,1);
		if(x*x+y*y<1)
		sum+=1;
		}
	double pi=sum/10000*4;
	cout << "pi=" << setprecision(20) << pi <<endl;
	return 0;
	
	}