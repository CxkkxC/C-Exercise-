#include<iostream>
using namespace std;
class Clock{
	private:
		int hour,minute,second;
	public:
		void set();
		void set(int h,int m,int s);
		void show()
		{
			cout<<hour<<":"<<minute<<":"<<second<<endl;
		}
}; 

void Clock::set()
{
	cin>>hour>>minute>>second;
}

void Clock::set(int h,int m,int s){
	hour=h;
	minute=m;
	second=s; 
}

int main(){
	Clock c1,c2;
	c1.set();
	c1.show();
	c2.set(12,12,12);
	c2.show();
	return 0;
}
