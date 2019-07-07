#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int aDD(int a,int b){
return a<b;
}
int main(){
	string str;
	int sum=0;
	cin>>str;
	int len=str.length();
	for(int i=0;i<len;i++)
	{
	if(str[i]==' ')
	sum++;
	}
	cout<<sum<<endl;
	int a[]={1,2,2,3,2,4,5};
	sort(a,a+7,aDD);
	for(int i=0;i<7;i++)
	cout<<a[i]<<" "<<endl;
	return 0;
}
