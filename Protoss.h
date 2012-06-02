#include "race.h"

class Protoss: public Race {

	// Units
	class probe; // Index 0
	class zealot; // Index 1
	class stalker; // Index 2
	class sentry; // Index 3
	class highTemplar; // Index 4
	class darkTemplar; // Index 5
	class immortal; // Index 6
	class colossus; // Index 7
	class archon; // Index 8
	class observer; // Index 9
	class warpPrism; // Index 10
	class Pheonix; // Index 11
	class voidRay; // Index 12
	class carrier; //Index 13
	class mothership; //Index 14
  
public:
	Protoss();
	int minerals_per_min();
	int gas_per_min();
	void print();
	void make_unit(int index);
	void make_building(int index);
	void change_minerals(int i);
	void change_gas(int i);
	
	// buidlings
	class Protoss::protossbuildings{
	public:
   		protossbuildings();   
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
	int max_supply;
  
	int minerals;
	int gas;
  
	
	int unit_count[15]; //15 different units
	int building_count[15]; 
};
