// Race is a abstract base class (interface) for zerg, protoss, and terran. 
#include <iostream>

using namespace std;
class Race {
	virtual int minerals_per_min();
	virtual int gas_per_min();

	virtual void print();
};