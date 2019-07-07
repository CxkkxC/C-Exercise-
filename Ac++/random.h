#include <cstdlib>
#include <cmath>
#include <ctime>
 
/* Private function prototype */
void initRandomSeed();
/*随机数列随着时间不断变化函数*/
 
/*
 * Implementation notes: randomInteger
 * -----------------------------------
 * The code for randomInteger produces the number in four step:
 * 1. Generate a random real number d in the range [0..1).
 * 2. Scale the number to the range [0..N) where N is the number of values.
 * 3. Translate the number so that the range starts at the appropriate value.
 * 4. Convert the result to the next lower integer.
 *
 * The implementation is complicated by the fact that both the expression
 *      RAND_MAX + 1
 * and the expression for the number of values
 *      high - low + 1
 * can overflow the integer range.
 * These calculations must therefore be performed using doubles instead of ints.
 */
 
int randomInteger(int low, int high) {
    initRandomSeed();
    double d = rand() / (double(RAND_MAX) + 1);
    double s = d *(double(high) - low + 1);
    return int(floor(low + s));
}
 
double randomReal(double low, double high) {
    initRandomSeed();
    double d = rand() / (double(RAND_MAX) + 1);
    double s = d * (high - low);
    return low + s;
}
 
/*
 * Implementation notes: reanomChance
 * ----------------------------------
 * The code for randomChange calls randomReal(0, 1) and the checks
 * whether the result is less than the requested probability.
 */
 
bool randomChance(double p) {
    initRandomSeed();
    return randomReal(0, 1) < p;
}
 
void setRandomSeed(int seed) {
    initRandomSeed();
    srand(seed);
}
 
void initRandomSeed() {
    static bool initialized = false;
    if (!initialized) {
        srand(int(time(NULL)));
        initialized = true;
    }
}
// This interface exports functions for generating pseudorandom numbers.
#ifndef RANDOM_H
#define RANDOM_H
 
// Returns a random integer in the range low to high, inclusive.
int randomInteger(int low, int high);
 
// Returns a random real number in the half-open interval [low .. high).
double randomReal(double low, double high);
 
// Returns true with the probability indicate by p.
bool randomChance(double p);
 
// Sets the internal random number seed to the specified value.
void setRandomSeed(int seed);
 
#endif // RANDOM_H