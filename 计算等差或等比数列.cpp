#include<iostream>
using namespace std;
int main()
{
	while(true){
	int m;	
cout<<"�������Ǽ���Ȳ�ǵȱ����У�\n����Ȳ���������������1��\n����ȱ���������������2��"<<endl;
cin>>m;
if(m==1)	
{
int N,sum=0,d,m,a0;
cout<<"������Ȳ����е������͹���d��"<<endl;
cout<<"����Ϊ:";
cin>>N;
cout<<"������Ȳ����е�����a0=";
cin>>a0;
cout<<"����dΪ:";
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
cout<<"\n��������Ҫ���ǰm��͵�ֵ,m=";
cin>>m;
for(n=0;n<m;n++)
sum+=F[n];
cout<<"�Ȳ����еĺ�Ϊ:"<<sum<<endl;
}
 else if(m==2)
 {
 int M,sum=0,q,p,a0;
cout<<"������ȱ����е������͹���q��"<<endl;
cout<<"����Ϊ:";
cin>>M;
cout<<"������ȱ����е�����a0=";
cin>>a0;
cout<<"����qΪ:";
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
cout<<"\n��������Ҫ���ǰp��͵�ֵ,p=";
cin>>p;
for(o=0;o<p;o++)
sum+=F[o];
cout<<"�ȱ����еĺ�Ϊ:"<<sum<<endl;
}
	}
return 0;

}
