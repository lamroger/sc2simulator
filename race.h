#ifndef race_h

#define race_h

// Race is a abstract base class (interface) for zerg, protoss, and terran. 
#include <iostream>
#include <string>

using namespace std;
class Race {
public:
	virtual int minerals_per_min() = 0 ;
	virtual int gas_per_min() = 0;
	virtual int get_mineral() const = 0;
	virtual int get_gas() const = 0;

	virtual ostream& operator<< (ostream&) = 0;
	virtual void print() = 0;

	virtual void make_unit(int index) = 0;
	virtual bool make_building(int index) = 0;
	virtual void change_minerals(int i) = 0;
	virtual void change_gas(int i) = 0;
	virtual int get_army() = 0;
	virtual int army_health() = 0;
	virtual int army_attack() = 0;

	virtual int howmanyunits(int) = 0;
	virtual int howmanybuildings(int) = 0;

	virtual bool unitCheckReq(int i) = 0;

	virtual bool sendToGas() = 0;

	virtual void addLarva() = 0;
	virtual int getLarva() = 0;


	string unitnames[15];
	string buildingnames[15];
	int unit_min[15];
	int unit_gas[15];
	int unit_supply[15];
	int building_min[15];
	int building_gas[15];

	int mineral_workers;
	int gas_workers;
	int mining_bases;
	int army_value;
	int max_supply;
  
	int minerals;
	int gas;

	int larva;
};

#endif