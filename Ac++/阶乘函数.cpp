#include<iostream>
using namespace std;
/* 
   用for循环完成阶乘 Cxk 2019.1.12
 */
int fact(int n)
{
	int result = 1;
	for (int i = 1; i <= n; i++)
	{
		result *= i;
	}
	return result;
}

int main()
{
	int a;
	cin >> a;
	cout << fact(a);
	return 0;
}

