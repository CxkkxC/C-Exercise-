#include<iostream>
using namespace std;
int main()
{
int i,j;
cout<<"���������������������:";
cout<<'\n'<<"����Ϊ:";
cin>>i;
cout<<"����Ϊ:";
cin>>j;
int a,b;
int ** m=new int*[i];
//int *m[i];
//Ԥ�ȶ���һ��ָ������m,���ڱ���i��һά������׵�ַ��
for(a=0; a<i; a++)
//ʹ��ѭ���ṹ��Ϊÿ�ж�̬����һ��һά���顣
 {
m[a]=new int[j];
//��̬����һά���飬Ԫ�ظ���Ӧ���ڶ�ά���������j��
}
//��ֵ����
for(a=0;a<i;a++)
for(b=0;b<j;b++)
{
cout<<"����������a["<<a<<"]["<<b<<"]��ֵ:";
cin>>m[a][b];
cout<<endl;
}
//��ʾ����
for(a=0;a<i;a++)//��
{
for(b=0;b<j;b++)//��
{
cout<<m[a][b]<<" ";
}
cout<<endl;
}

/*�㷨:���Խ���֮��:�±���ͬ���ζԽ���֮��:�±����Ϊ�л�������1��*/
int c,d,e,f,sum=0;
for (c=0;c<i;c++)
for (d=0;d<j;d++)
{
if (c==d)
sum+=m[c][d];
}
cout<<"���Խ��ߵĺ�Ϊ:"<<sum<<endl;
sum=0;
for(c=0;c<i;c++)
for(d=0;d<j;d++)
{
if(d==(j-1)-c)
sum+=m[c][d];
}
cout<<"�ζԽ��ߵĺ�Ϊ:"<<sum<<endl;
return 0;
}