#include<iostream>
using namespace std;

int main()
{
     float x;     //����һ��float�ͱ���x
	 cin >> x;    //�Ӽ����������x��ֵ

	 int sgn;     //����һ��int�ͱ���sgn�����ڱ�����

     if(x==0)     //���Ƚ�x��Ϊ����0�Ͳ�����0�������
		 sgn=0;   //x����0ʱ��sgn=0
	 else         //��x������0������£��ٽ�һ������x>0��x<0���������
	 {
	 if(x>0) sgn=1;  //x����0ʱ��sgn=1
	 else sgn=-1;    //xС��0ʱ��sgn=-1

	 }
	 cout<<sgn<<endl;  // ��ʾ����sgn��ֵ�������ź�������Ľ��
	 return 0;
 }