	#include<iostream>
	#include<algorithm>
	#include<cstring>
	using namespace std;
	int main()
	{
	int n;
	cin>>n;
	int b[n];
	int a[n];

	for(int i = 0;i<n;i++)
	{
		cin>>a[i]>>b[i];
	}
	cout<<endl;
		sort(a,a+n);
	sort(b,b+n);
	for(int i = 0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	for(int i = 0;i<n;i++)
	{
		cout<<b[i]<<" ";
	}
	cout<<endl;
	string str="cxkcxk";
	cout<<str.length()<<endl;
	cout<<endl;
	return 0;
}
 
