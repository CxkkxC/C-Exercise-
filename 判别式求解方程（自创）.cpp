#include <stdlib.h>                                                 //��ֹ�����ļ�����  
#include<iostream>
#include<math.h>
using namespace std;
 int main()
 {
	 double a,b,c,d,x1,x2,e;                                        //��ⷽ�� ax^2+bx+c	 
	 while(true)                                                    //������ѭ��
	 {
	 e=sqrt(d);                                                     //���ţ�d��
	 cout<<"�����б�ʽ����Ԫһ�η��̡�(ax^2+bx+c)"<<endl;         //����Ŀ��
	 cout<<"�����������Ԫһ�����е�a,b,c,�����س���������"<<endl;  //��ʾ�û����뷽��a,b,c��ֵ
	 cout<<"a=";
		 cin>>a;                                                    //����������Чֵa
		
		 cout<<"b=";
	 cin>>b;                                                        //����������Чֵb
	 cout<<"c=";
	 cin>>c;                                                        //����������Чֵc
	 cout<<"�˷���Ϊ:"<<a<<"x^2+"<<b<<"x+"<<c<<endl;                //��ʾ�û�����ķ���
	 d=b*b-4*a*c;                                                   //�б�ʽ
	 x1=(-b-sqrt(d))/(2*a);                                         //���x1
	 x2=(-b+sqrt(d))/(2*a);                                         //���x2	
	 if(d<0)                                                        //����б�ʽС��0��ʾ�޽�
		 cout<<"�˷����޽⡣"<<endl;                               
	 else
		 if(d>0)                                                    //����б�ʽ����0����ʾ����
	 cout<<"�����˧������ĸ�����˷��̵Ľ���:"<<"x1="<<x1<<","<<"x2="<<x2<<endl;
	 cout<<"----------����----˧��-----�ָ�----��---------------"<<endl;//Ϊ�˺ÿ�
	 	if(a<=1) break;
	 }
	 system("pause");                                               //��ֹ�����ļ����ˣ���ʾ���밴�����������  
		 return 0;
	}