#include<iostream>
using namespace std;
int main()
{
    int i,j,n;
    cout<<"请输入行数n:";
    cin>>n;
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n-i;j++)//n-j是直角三角形
    	cout<<" ";
    	for(j=0;j<2*i+1;j++)
    	cout<<"*";
    	cout<<endl;
    	}
    	   i=0,j=0;
    for(i=0;i<n+1;i++)
    {
    	for(j=0;j<i;j++)
    	cout<<" ";
    	for(j=0;j<(2*n+1)-2*i;j++)
    	cout<<"*";
    	cout<<endl;
    	}
  cout<<"有时候只想自己一个人静静的待会。                                      尽管外面的世界早已闹得天翻地覆。"<<endl;
 
 i=0,j=0;
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n-i;j++)
    	cout<<" ";
    	for(j=0;j<2*i+1;j++)
    	cout<<"*";
    	cout<<endl;
    	}
    	
    	cout<<"——————————"<<endl;
  i=0,j=0;
    for(i=0;i<n+1;i++)
    {
    	for(j=0;j<i;j++)
    	cout<<" ";
    	for(j=0;j<(2*n+1)-2*i;j++)
    	cout<<"*";
    	cout<<endl;
    	}
    return 0;
}
