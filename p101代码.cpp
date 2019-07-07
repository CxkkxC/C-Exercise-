#include<iostream>
using namespace std;
 int main()
 {
	 int N;
	 cin>>N;
	 int*F=new int[N];
	 F[0]=0;F[1]=1;
	 
	 int n;
	 for(n=2;n<N;n++)
	 F[N]=F[n-1]+F[n-2];
	 for(n=0;n<N;n++)
	 {
		 cout<<F[n]<<",";
		 if((n+1)%5==0)  cout<<endl;
		 
		 }
		 delete[]F;
		 return 0;
	 }