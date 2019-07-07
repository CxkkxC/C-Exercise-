#include <stdlib.h>                                                 //防止生成文件闪退  
#include<iostream>
#include<math.h>
using namespace std;
 int main()
 {
	 double a,b,c,d,x1,x2,e;                                        //求解方程 ax^2+bx+c	 
	 while(true)                                                    //陷入死循环
	 {
	 e=sqrt(d);                                                     //根号（d）
	 cout<<"根据判别式求解二元一次方程。(ax^2+bx+c)"<<endl;         //程序目的
	 cout<<"请依次输入二元一方程中的a,b,c,并按回车键结束。"<<endl;  //提示用户输入方程a,b,c的值
	 cout<<"a=";
		 cin>>a;                                                    //键盘输入有效值a
		
		 cout<<"b=";
	 cin>>b;                                                        //键盘输入有效值b
	 cout<<"c=";
	 cin>>c;                                                        //键盘输入有效值c
	 cout<<"此方程为:"<<a<<"x^2+"<<b<<"x+"<<c<<endl;                //显示用户输入的方程
	 d=b*b-4*a*c;                                                   //判别式
	 x1=(-b-sqrt(d))/(2*a);                                         //解出x1
	 x2=(-b+sqrt(d))/(2*a);                                         //解出x2	
	 if(d<0)                                                        //如果判别式小于0显示无解
		 cout<<"此方程无解。"<<endl;                               
	 else
		 if(d>0)                                                    //如果判别式大于0就显示出解
	 cout<<"凯哥大帅哥大声的告诉你此方程的解是:"<<"x1="<<x1<<","<<"x2="<<x2<<endl;
	 cout<<"----------凯哥----帅气-----分割----线---------------"<<endl;//为了好看
	 	if(a<=1) break;
	 }
	 system("pause");                                               //防止生成文件闪退，显示“请按任意键继续”  
		 return 0;
	}