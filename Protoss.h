#include "race.h"

class Protoss: public Race {
public:
	Protoss();
	int minerals_per_min();
	int gas_per_min();
	ostream& operator<< (ostream&);
	void print();
	int get_mineral() const;
	int get_gas() const;
	void make_unit(int index);
	bool make_building(int index); //need to make this
	void change_minerals(int i);
	void change_gas(int i);
	int howmanyunits(int);
	int howmanybuildings(int);
	int get_army();
	int army_health();
	int army_attack();
	bool sendToGas();
	bool sendToMin();
	void addLarva();
	int getLarva();

class Units{
	public:
		Units();
		void add(int i);
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

	bool unitCheckReq(int i);
	Units protossUnits;

	// buildings
	class protossbuildings{
	public:
   		protossbuildings();   
   		bool add(int); //when player builds new building
   		int howmany(int);
   	private:
   		int count[15];	//keeps track of the number of each building
	};

	bool buildingCheckReq(int i);
	protossbuildings buildings;


  
private:
	int mineral_workers;
	int gas_workers;
	int mining_bases;
	int army_value;
	int max_supply;
  
	int minerals;
	int gas;
  
	
	//int unit_count[15]; //15 different units
};