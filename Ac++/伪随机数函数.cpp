#include<iostream>
#include<cstdlib>
#include <iomanip>
#include"random.h"
// 伪随机数包含头文件
using namespace std;
int main()
{
	for (int i = 1; i <= 3; i++)
	{
		cout << "范围1到6的数：" << randomInteger(1, 6) << endl;
		// randomInteger函数需要传入两个整型参数并返回一个在这两个参数范围内的随机整数。
		cout << "范围0到1的浮点数：" << randomReal(0, 1) << endl;
		// randomReal函数返回一个不小于0到小于1的浮点数。
		cout << "0或1的一个个数：" << randomChance(0.50) << endl;
		// randomChance函数被用来模拟具有特定概率的随机事件。

	}

	return 0;
}
