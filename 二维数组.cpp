#include<iostream>
using namespace std;
int main()
{
int i,j;
cout<<"请输入数组的行数和列数:";
cout<<'\n'<<"行数为:";
cin>>i;
cout<<"列数为:";
cin>>j;
int a,b;
int ** m=new int*[i];
//int *m[i];
//预先定义一个指针数组m,用于保存i个一维数组的首地址。
for(a=0; a<i; a++)
//使用循环结构，为每行动态分配一个一维数组。
 {
m[a]=new int[j];
//动态分配一维数组，元素个数应等于二维数组的列数j。
}
//赋值过程
for(a=0;a<i;a++)
for(b=0;b<j;b++)
{
cout<<"请输入数组a["<<a<<"]["<<b<<"]的值:";
cin>>m[a][b];
cout<<endl;
}
//显示过程
for(a=0;a<i;a++)//行
{
for(b=0;b<j;b++)//列
{
cout<<m[a][b]<<" ";
}
cout<<endl;
}

/*算法:主对角线之和:下标相同。次对角线之和:下标相加为行或列数减1。*/
int c,d,e,f,sum=0;
for (c=0;c<i;c++)
for (d=0;d<j;d++)
{
if (c==d)
sum+=m[c][d];
}
cout<<"主对角线的和为:"<<sum<<endl;
sum=0;
for(c=0;c<i;c++)
for(d=0;d<j;d++)
{
if(d==(j-1)-c)
sum+=m[c][d];
}
cout<<"次对角线的和为:"<<sum<<endl;
return 0;
}