#include<iostream>
using namespace std;

const int SENTINEL = 10;

int main()
{
	int total = 0;
	cout << " this program adds a List of number." << endl;
	cout << "use " << SENTINEL << " to signal the endl." << endl;
	while (true)
	{
		int value;
		cout << "?";
		cin >> value;
		total += value;
		if (value == SENTINEL)
			break;
	}
	cout << "The total is " << total << endl;
	return 0;
}

