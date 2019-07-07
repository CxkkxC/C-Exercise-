/* 
   考虑如下的序列生成算法：从整数 n 开始，如果 n
   是偶数，把它除以 2；如果 n 是奇数，把它乘 3
   加1。用新得到的值重复上述步骤，直到 n = 1
   时停止。例如，n = 22 时该算法生成的序列是：

   22，11，34，17，52，26，13，40，20，10，5，16，8，4，2，1



   人们猜想（没有得到证明）对于任意整数
   n，该算法总能终止于 n = 1。这个猜想对于至少 1 000
   000内的整数都是正确的。



   对于给定的 n，该序列的元素（包括 1）个数被称为 n
   的循环节长度。在上述例子中，22 的循环节长度为
   16。输入两个数 i 和 j，你的任务是计算 i 到 j（包含 i 和 
   j）之间的整数中，循环节长度的最大值。

 */
#include<iostream>
using namespace std;
int e=0;
int cxk(int n)
{
	e++;
	if (n == 1)
	{
	//	cout<<1<<endl;
		return e;
	}
	if (n % 2 == 0)
	{
		//cout << n << endl;
		n /= 2;
	}
	else
	{
		//cout << n << endl;
		n = n * 3 + 1;
	}
	cxk(n);

}

int main()
{
//cout<<cxk(20);
	int i,j;
	cin>>i>>j;
	int b[j-i];
	for(int a=i,c=1;a<=j;a++)
	{
		b[c++]=cxk(a);
		}
	for(int d=1;d<=j-i;d++)
	cout<<b[d]<<" ";
	return 0;
	}