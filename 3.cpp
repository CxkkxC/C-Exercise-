#include<iostream>
#include<math.h>
#define PI 3.14159
using namespace std;
int main()
{
int i=10;
float a,b,k;
while(i<=180)
{
   k = PI / 180;
   a = sin(i*k);
   b = cos(i*k);  
   cout<<"�Ƕ�:       \t "<<i<<"         \t ����:      \t "<<a<<"                 \t ����:  \t  "<<b<<endl;
i+=10;
}
	return 0;
}