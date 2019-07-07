#include<iostream>
using namespace std;
int main(){
	int p=10;
	int n=0,m=0;
	for(int i=0;i<2;i++){
		n++;
		--p;
		m+=n*p;
	}
	cout<<m;
	int a=7;
	cout<<a%3;
	return 0;
}