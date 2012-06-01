#include "race.h"
#include <string>

class Zerg: public Race {

	/*
	Not implementing Nested classes yet. 
	Trying to get basic model working. 
	*/
	
	// Units
	class drone; // Index 0
	class overlord; // Index 1
	class zergling; // Index 2
	class queen; // Index 3
	class overseer; // Index 4
	class roach; // Index 5
	class baneling; // Index 6
	class hydralisk; // Index 7
	class infestor; // Index 8
	class mutalisk; // Index 9
	class corruptor; // Index 10
	class ultralisk; // Index 11
	class broodlord; // Index 12
  
	// Buildings
 

	// Defensive Structures
	// calculate when defending?
	//class spore_crawler;
	//class spine_crawler;
  
public:
	Zerg();
	int minerals_per_min();
	int gas_per_min();
	void print();
	void make_unit(int index);
	void change_minerals(int i);
	void change_gas(int i);
	
	// Building class
	class zergbuildings{
		public:
   			zergbuildings();   
   			bool add(int); //when player builds new building
   			int howmany(string);
		private:
   			int count[14];	//keeps track of the number of each building
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
};
