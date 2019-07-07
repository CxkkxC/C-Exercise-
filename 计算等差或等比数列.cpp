#include<iostream>
using namespace std;
int main()
{
	while(true){
	int m;	
cout<<"请问您是计算等差还是等比数列？\n计算等差数列请输入数字1。\n计算等比数列请输入数字2。"<<endl;
cin>>m;
if(m==1)	
{
int N,sum=0,d,m,a0;
cout<<"请输入等差数列的项数和公差d。"<<endl;
cout<<"项数为:";
cin>>N;
cout<<"请输入等差数列的首项a0=";
cin>>a0;
cout<<"公差d为:";
cin>>d;
int *F=new int[N];
F[0]=a0;
int n;
for(n=1;n<N;n++)
F[n]=F[n-1]+d;
for(n=0;n<N;n++)
{
cout<<F[n]<<" , ";
if((n+1)%10==0) cout<<endl;
}
cout<<"\n请输入需要求的前m项和的值,m=";
cin>>m;
for(n=0;n<m;n++)
sum+=F[n];
cout<<"等差数列的和为:"<<sum<<endl;
}
 else if(m==2)
 {
 int M,sum=0,q,p,a0;
cout<<"请输入等比数列的项数和公比q。"<<endl;
cout<<"项数为:";
cin>>M;
cout<<"请输入等比数列的首项a0=";
cin>>a0;
cout<<"公比q为:";
cin>>q;
double *F=new double[M];
F[0]=a0;
int o;
for(o=1;o<M;o++)
F[o]=F[o-1]*q;
for(o=0;o<M;o++)
{
cout<<F[o]<<" , ";
if((o+1)%10==0) cout<<endl;
}
cout<<"\n请输入需要求的前p项和的值,p=";
cin>>p;
for(o=0;o<p;o++)
sum+=F[o];
cout<<"等比数列的和为:"<<sum<<endl;
}
	}
return 0;

}
