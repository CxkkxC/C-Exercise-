#include<stdlib.h>
#include<math.h>
#include<time.h>
using namespace std;
void initRandomSeed();
int randomInteger(int low, int hight)
{
	initRandomSeed();
	double d = rand() / (double (RAND_MAX) + 1);
	double s = d * (double (hight) - low + 1);
	return int (floor(low + s));
}

double randomReal(double low, double hight)
{
	initRandomSeed();
	double d = rand() / (double (RAND_MAX) + 1);
	double s = d * (hight - low);
	return low + s;
}

bool randomChance(double p)
{

	initRandomSeed();
	return randomReal(0, 1) < p;
}

void setRandomSeed(int seed)
{
	initRandomSeed();
	srand(seed);

}

void initRandomSeed()
{
	static bool initialized = false;
	if (!initialized)
	{
		srand(int (time(NULL)));
		initialized = true;
	}
} 