#include<iostream>
using namespace std;
#include"Circle.h"
void Circle :: Input()
{
cin>>r;
while (r<0)
cin>>r;
}
double Circle :: Radius()
{
return r;
}
double Circle :: CArea()
{
return (3.14*r*r);
}
double Circle :: CLen()
{
return (3.14*2*r);
}
 int main ()
 {
	 Circle C1;
	 C1.Input();
	 cout<<C1.Radius()<<endl;
	 cout<<C1.CArea()<<endl;
	 cout<<C1.CLen()<<endl;
 return 0;
 }