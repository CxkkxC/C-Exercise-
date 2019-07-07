#include<iostream>
using namespace std;
class Vehicle
{
private:
	int speed;
	int weight;
public:
	Vehicle(int s,int w)
	{
		speed = s;
		weight = w;
	}
	void show()
	{
		cout<<speed<<endl;
		cout<<weight<<endl;
	}
};
class Bicycle : public Vehicle
{
private:
	int high;
public:
	Bicycle(int s,int w,int h) : Vehicle(int s,int w)
	{
		hight = h;
	}
	void show()
	{
		cout<<speed<<endl;
		cout<<weight<<endl;
		cout<<high<<endl;
	}
};
class Car : public Vehicle
{
private:
	int Seatnum;
public:
	Car(int s,int w,int S) : Vehicle(int s,int w)
	{
		Seatnum = S;
	}
	void show()
	{
		cout<<speed<<endl;
		cout<<weight<<endl;
		cout<<Seatnum<<endl;
	}
};
int main()
{
	Vehicle v1(1,2);
	v1.show();
	Bicycle b1(3,4,5);
	b1.show();
	Car c1(6,7,8);
	c1.show();
	return 0;
}