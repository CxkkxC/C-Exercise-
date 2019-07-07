class Circle
{
private:
	double r;
public:
	void Input();
	double Radius();
	double CArea();
	double CLen();
	Circle()
	{
	r = 0;
	}
Circle(double x)
{
if (x<0)
r = 0;
else 
r = x;
}
Circle(Circle &x)
{
r = x.r;
}
};