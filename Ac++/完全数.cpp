#include<iostream>
using namespace std;
bool isPerfect(int n);
int main()
{
	// cout<<isPerfect(6);
	for (int i = 1; i <= 9999; i++)
	{
		if (isPerfect(i) == 1)
			cout << i << endl;
	}
	return 0;
}

bool isPerfect(int n)
{
	int sum = 0;
	for (int i = 1; i < n; i++)
	{
		if (n % i == 0)
			sum += i;
	}
	if (sum == n)
		return true;
	else
		return false;
}

