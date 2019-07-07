#include<iostream>
#include<math.h>
using namespace std;

int bin(double n){
	int a=(int)n;
	int bin=0,j=1;
	while(a!=0)
	{
		bin = bin + j*(a%2);
		a = a/2;
		j = j*10;
	}
	return bin;
}
void binSmallNumber(double n){
		int a=(int)n;
		double b=n-a;
	int d=0,count=0; 
	while(b!=0){
		b=b*2;
		d=(int)b;
		cout<<d;
		b-=d;
		count++;
		if(count>9)
		break;
	}
}

int dec(string str){
	int len=str.length();
	double sum=0.0;
	int len_2=len-1;
	for(int i=0;i<len;++i,len_2--)
	{
		if(str[i]=='0')
		{ 
		sum+=0;
		} 
		/*else if(str[i]=='.')
		{
		for(j=i+1;j<len;j++,a++)
		{
			if(str[j]=='0')
		{ 
		sum+=0;
				}	 
			else
		{
		sum+=pow(1/2,a);	
				}
			}
		}	*/
		else {
			sum+=pow(2,len_2);
			} 
}
	return sum;
}
int main(){
string n;
	cin>>n;
	//int b=(int)n;
/*	cout<<bin(n)<<".";
	binSmallNumber(n);
	while(n!=0){	
		long c=(long)n%2;
		cout<<c<<endl;
		n/=2;
	}*/
	cout<<dec(n)<<endl;
	return 0;
	
} 
