#include "race.h"

class Terran: public Race {

	/*
	Not implementing Nested classes yet. 
	Trying to get basic model working. 
	*/
	
	// Units
	class scv; // Index 0
	class marine; // Index 1
	class marauder; // Index 2
	class reaper; // Index 3
	class ghost; // Index 4
	class hellion; // Index 5
	class siege_tank; // Index 6
	class thor; // Index 7
	class viking; // Index 8
	class medivac; // Index 9
	class banshee; // Index 10
	class raven; // Index 11
	class battlecruiser; // Index 12
	class mule; // Index 13
  
	// Buildings
	class command_center; // Index 0
	class orbital_command; // Index 1
	class planetary_fortress; // Index 2
	class supply_depot; // Index 3
	class refinery; // Index 4
	class barracks; // Index 5
	class engineering_bay; // Index 6
	class bunker; // Index 7
	class factory; // Index 8
	class ghost_academy; // Index 9
	class armory; // Index 10
	class starport; // Index 11
	class fusion_core; // Index 12
	class tech_lab; // Index 13
	class reactor; // Index 14
	
  
	// Defensive Structures
	// calculate when defending?
	//class missle_turret;
	//class sensor_tower
  
public:
	Terran();
	int minerals_per_min();
	int gas_per_min();
	void print();
	void make_unit(int index);
	void change_minerals(int i);
	void change_gas(int i);
  
private:
	int mineral_workers;
	int gas_workers;
	int mining_bases;
	int army_value;
	int max_supply;
  
	int minerals;
	int gas;
  
	// 13 different units (You guys should watch 13 Assassins.) 
	int unit_count[14];

};
