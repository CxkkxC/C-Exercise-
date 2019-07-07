/*
冰雹序列
如果n=1，那么已经到终点，可以停止；
如果n是偶数，将他除以2；
如果n是奇数，将他乘以3加1；
*/
#include <iostream>
#include <string>
using namespace std;
int Hs(int n);
int main(){
	cout<<"Enter a number:";
	int N;
	cin>>N;
	Hs(N);
	return 0;
}
int Hs(int n){
	if(n==1){
		return 0;
	}
	else if(n%2!=0)
	{
		cout<<n;
		n=n*3+1;
		cout<<"is odd,so I multiply it by 3 add 1 to get "<<n<<endl;
		Hs(n);
	}	
	
	else if(n%2==0)
	{
		cout<<n;
		n=n/2;
		cout<<"is even,so I divide it by 2 to get "<<n<<endl;
		Hs(n);
	}
	return 0;
}
	