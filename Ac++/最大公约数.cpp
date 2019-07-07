#include<iostream>
using namespace std;
/* 
   用while循环完成求 最大公约数 欧几里得算法
   1.用x除以y并计算余数r
   2.若r等于0，则算法结束，最大公约数为y 3.若r不等于0，则令x的值为y，y的值为r，重复该过程。 
   Cxk  2019.1.12 */
int gcd(int x, int y)
{
	int r = x % y;
	while (r != 0)
	{
		x = y;
		y = r;
		r = x % y;
	}
	return y;
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << gcd(a, b);
	return 0;
}

