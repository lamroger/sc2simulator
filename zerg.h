#include "race.h"
#include <string>

class Zerg: public Race {

	/*
	Not implementing Nested classes yet. 
	Trying to get basic model working. 
	*/
	
	// Buildings
 

	// Defensive Structures
	// calculate when defending?
	//class spore_crawler;
	//class spine_crawler;
  
public:
	Zerg();
	int minerals_per_min();
	int gas_per_min();
	ostream& operator<< (ostream&);
	void print();
	void make_unit(int index);
	bool make_building(int index);
	int get_mineral() const;
	int get_gas() const;
	void change_minerals(int i);
	void change_gas(int i);
	int get_army();
	int army_health();
	int army_attack();
	int howmanyunits(int);
	int howmanybuildings(int);
	bool unitCheckReq(int i);
	bool sendToGas();
	bool sendToMin();
	void addLarva();
	int getLarva();

	class Units{
	public:
		Units();
		void add(int i);
		void subdrone(){count[0]--; return;};
		int howmany(int i);
		int getMinCost(int index){ return minCost[index]; };
		int getGasCost(int index){ return gasCost[index]; };
		int getSupplyCost(int index){ return supplyCost[index]; };
		int getBuildingReq(int index){ return buildingReq[index]; };
		//void getStats(int i);, getattack, def, etc

	private:
		int count[15];
		int attack[15];
		int health[15];
		int armor[15];
		int minCost[15];
		int gasCost[15];
		int supplyCost[15];
		int buildingReq[15];

	};	
	// Building class
	class zergbuildings{
		public:
   			zergbuildings();   
   			bool add(int); //when player builds new building
   			int howmany(int);
		private:
   			int count[15];	//keeps track of the number of each building
	};
  
private:
	int mineral_workers;
	int gas_workers;
	int mining_bases;
	int army_value;
	int larva;
	int max_supply;
  
	int minerals;
	int gas;
  
	// 13 different units (You guys should watch 13 Assassins.) 
	int unit_count[13];
	
	zergbuildings buildings;
	Units zergUnits;
};
