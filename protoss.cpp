#include "protoss.h"
#include <iostream>
#include <conio.h>


using namespace std;

extern int P_MIN_COST[];
extern int P_GAS_COST[];
extern int P_SUP_COST[];
extern int P_BLD_REQ[];

extern int P_ATT[];
extern double P_SPEED[];
extern int P_HLT[];
extern int P_ARM[];

extern int P_UNIT_TOT;

extern int P_MIN_COST[];
extern int P_GAS_COST[];
extern int P_SUP_COST[];
extern int P_BUILDING_MIN_COST[];
extern int P_BUILDING_GAS_COST[];

Protoss::Protoss() {
	//unit_count[0] = 6; //Initial Probe
	//for(int i = 1; i<15; i++)
		//unit_count[i] = 0;
  
	mineral_workers = 6;
	gas_workers = 0;
	mining_bases = 1;
	army_value = 6;
	max_supply = 10;
  
	minerals = 50;
	gas = 0;

  	string units[15] = {"probe", "zealot", "stalker", "sentry", "high templar", "dark templar", "immortal", "colossus", "archon",
						"observer", "warp prism", "phoenix", "void ray", "carrier", "mothership"};
	string buildings[15] = {"nexus", "pylon", "assimlator", "gateway", "forge", "photon cannon", "warpgate", "cybernetics core", 
							"twilight council", "robotics facility", "stargate", "templar archives", "dark shrine", "robotics bay", "fleet beacon" };
	for(int i = 0; i < 15; i++)
		buildingnames[i] = buildings[i];

	for(int i = 0; i < 15; i++)
		unitnames[i] = units[i];
		
	for(int i = 0; i < 15; i++)
		unit_min[i] = P_MIN_COST[i];
	
	for(int i = 0; i < 15; i++)
		unit_gas[i] = P_GAS_COST[i];

	for(int i = 0; i < 15; i++)
		unit_supply[i] = P_SUP_COST[i];

	for(int i = 0; i < 15; i++)
		building_min[i] = P_BUILDING_MIN_COST[i];

	for(int i = 0; i < 15; i++)
		building_gas[i] = P_BUILDING_GAS_COST[i];
}

int Protoss::minerals_per_min() {
	return mineral_workers*40;
}

int Protoss::gas_per_min() {
	return gas_workers*38;
}

ostream& Protoss::operator<< (ostream& out)
{
	cout << "Current Minerals: " << this->get_mineral() << "\n";
	cout << "Current Gas: " << this->get_gas() << "\n\n";
	cout << "Minerals per Minute: " << this->minerals_per_min()  << "\n";
	cout << "Gas per Minute: " << this->gas_per_min()  << "\n";
	cout << "\n";
	cout << "Mineral Workers: " << this->mineral_workers  << "\n";
	cout << "Gas Workers: " << this->gas_workers  << "\n\n";
	cout << "Mining Bases: " << this->mining_bases  << "\n";
	cout << "Max Supply: " << this->max_supply  << "\n";
	cout << "Army Value: " << this->army_value  << "\n";
	cout << "Larva: " << this->larva  << "\n";
	return out;
}


void Protoss::print() {
	cout << "Current Minerals: " << get_mineral() << "\n";
	cout << "Current Gas: " << get_gas() << "\n\n";
	cout << "Minerals per Minute: " << minerals_per_min()  << "\n";
	cout << "Gas per Minute: " << gas_per_min()  << "\n";
	cout << "\n";
	cout << "Mineral Workers: " << mineral_workers  << "\n";
	cout << "Gas Workers: " << gas_workers  << "\n\n";
	cout << "Mining Bases: " << mining_bases  << "\n";
	cout << "Max Supply: " << max_supply  << "\n";
	cout << "Army Value: " << army_value  << "\n";
}

int Protoss::get_mineral() const
{
	return minerals;
}

int Protoss::get_gas() const
{
	return gas;
}

void Protoss::make_unit(int index) {

	if (unitCheckReq(index)){ 
		protossUnits.add(index); //increments number of units
		change_minerals(protossUnits.getMinCost(index)*(-1));
		change_gas(protossUnits.getGasCost(index)*(-1));
		army_value = army_value + protossUnits.getSupplyCost(index);
		if (index == 0)
			mineral_workers++;
		
	}else
		cout << "Build failed" << endl;
}

bool Protoss::make_building(int index){
	try{
	switch (index) {
		case 0:
			if (minerals >= 400) {
				if(buildings.add(index))
					minerals -= 400;
			} else {
				throw "we require more minerals";
			}
			break;

		case 1:
			if (minerals >= 100) {
				if (buildings.add(index))
				{
					minerals -= 100;
					max_supply += 8;
				}
			} else {
				throw "we require more minerals";
			}
			break;

		case 2:
			if (minerals >= 75) {
				if(buildings.add(index))
				{
					minerals -= 75;
				}

			} else {
				throw "we require more minerals";
			}
			break;

		case 3:
			if (minerals >= 150 ) {
				if(buildings.add(index))
					minerals -= 150;
			} else {
				throw "we require more minerals";
			}
			break;

		case 4:
			if (minerals >= 150) {
				if(buildings.add(index))
					minerals -= 150;
	
			} else {
				throw "we require more minerals";
			}
			break;

		case 5:
			if (minerals >= 150) {
				if(buildings.add(index))
					minerals -= 150;
			} else {
				throw "we require more minerals";
			}
			break;

		case 6:
			if (minerals >= 50 && gas >= 50) {
				if(buildings.add(index)){
					minerals -= 50;
					gas -= 50;
					//upgrading gateway
				}
			} else {
				throw "we require more minerals";
			}
			break;

		case 7:
			if (minerals >= 150) {
				if(buildings.add(index))
					minerals -= 150;
			} else {
				throw "we require more minerals";
			}
			break;

		case 8:
			if (minerals >= 150 && gas >=100) {
				if(buildings.add(index)){
					gas -= 100;
					minerals -= 150;
			} else {
				throw "we require more minerals";
			}
			break;

		case 9:
			if (minerals >= 200 && gas >= 100) {
				if(buildings.add(index))
				{
					minerals -= 200;
					gas -= 100;
				}

			} else {
				throw "we require more minerals";
			}
			break;

		case 10:
			if (minerals >= 150 && gas >= 150) {
				if(buildings.add(index))
				{
					minerals -= 150;
					gas -= 150;
				}
	
			} else {
				throw "we require more minerals";
			}
			break;

		case 11:
			if (minerals >= 150 && gas >= 200) {
				if(buildings.add(index))
				{
					minerals -= 150;
					gas -= 200;
				}
				
			} else {
				throw "we require more minerals";
			}
			break;

		case 12:
			if (minerals >= 100 && gas >= 250) {
				if(buildings.add(index))
				{
					minerals -= 100;
					gas -= 250;
				}

			} else {
				throw "we require more minerals";
			}
			break;

		case 13:
			if (minerals >= 200 && gas >= 200) {
				if(buildings.add(index))
				{
					minerals -= 200;
					gas -= 200;
				}

			} else {
				throw "we require more minerals";
			}
			break;

		case 14:
			if (minerals >=300 && gas >=200){
				if(buildings.add(index)){
					minerals-= 300;
					gas -= 200;
			}
				else
					throw "we require more minerals";
			}
		default:
			throw "index not valid";
			break;
	}
	}
	}

	catch(const char* e)
	{
		cout << e << endl;
		char tmp = getch();
		return false;
	}

	return true;
}

void Protoss::change_minerals(int i)
{
	minerals = minerals + i;
}

void Protoss::change_gas(int i)
{
	gas += i;
}

int Protoss::howmanyunits(int i)
{
	return protossUnits.howmany(i);
}

int Protoss::howmanybuildings(int i)
{
	return buildings.howmany(i);
}

int Protoss::get_army()
{
	return army_value;
}

int Protoss::army_health()
{
	int health = 0;
	for(int i = 0; i <P_UNIT_TOT; i++)
		health += (protossUnits.howmany(i)*P_HLT[i]);
	return health;
}

int Protoss::army_attack()
{
	double attack = 0;
	for(int i = 0; i<P_UNIT_TOT; i++)
		attack += (protossUnits.howmany(i)*P_ATT[i]*P_SPEED[i]);
	return (int)attack;
}

bool Protoss::unitCheckReq(int i){
		try{
			if (i >= P_UNIT_TOT)
				throw "Invalid Index";
			if (protossUnits.getMinCost(i) > minerals)
				throw "Insufficient Minerals";
			if (protossUnits.getGasCost(i) > gas)
				throw "Insufficient Vespene Gas";
			if (protossUnits.getSupplyCost(i) > max_supply - army_value)
				throw "You must construct additional Plyons";
			if (buildings.howmany(protossUnits.getBuildingReq(i))==0)
				throw "Required building has not been constructed";
			return true; //All requirements fulfilled
		}
		catch(const char* err){
			cout << err << endl << endl << "Press any key to return to main menu...";
			//char control = getch();
			return false;
		}

	}

bool Protoss::buildingCheckReq(int i){

	return false;
}

bool Protoss::sendToGas() {
	if (mineral_workers >= 1 && gas_workers < buildings.howmany(2)*3) {
		mineral_workers--;
		gas_workers++;
		return true;
	}
	return false;
}

bool Protoss::sendToMin() {
	if (gas_workers > 0) {
		mineral_workers++;
		gas_workers--;
		return true;
	}
	return false;
}

void Protoss::addLarva() {
}

int Protoss::getLarva() {
	return 0;
}
/**********Protoss Building Class Functions*************/


Protoss::protossbuildings::protossbuildings(){
	count[0] = 1;
	for(int i=1; i<15; i++)
	{
		count[i] = 0;
	}
}

bool Protoss::protossbuildings::add(int building)
{
    switch(building) {


	case 0: // "nexus":     // count[0]
   	 count[0]++;
	 break;
   	 
	case 1: // "pylon":   	 // count[1]
   	 count[1]++;
   	 break;

	case 2: // "assimilator":   	 // count[2]
   	 count[2]++;   
	 break;

	case 3: // "gateway"://count[3]
   	 count[3]++;
   	 break;

	case 4: // "forge": //count[4]
   	 count[4]++;
   	 break;

	case 5: // "photon cannon":    //count[5]
   	 count[5]++;
   	 break;

	case 6: //"warpgate"://count[6]
   	 count[6]++;
   	 break;

	case 7: //"cybernetics core"://count[7]
   	 count[7]++;
     break;

	case 8: // "twilight council":    //count[8]
   	 count[8]++;
     break;

	case 9: //"robotics facility":    //count[9]
   	 count[9]++;
     break;
	
	case 10: // "stargate":    //count[10]
   	 count[10]++;
   	 break;

	case 11: // "templar archives":    //count[11]
   	 count[11]++;
   	 break;

	case 12: // "dark shrine":    //count[12]
   	 count[12]++;
     break;
	
	case 13: // "robotics bay"://count[13]
   	 count[13]++;
	 break; 
	
	case 14: //"fleet beacon": // count[14]
	 count[14]++;
     break;
    
	default:
   	 cout << "Not valid building" << endl;
   	 return false;
    
    }
    
    return true;
}

int Protoss::protossbuildings::howmany(int building)
{
    switch(building) {
    
	case 0: //"nexus":     // count[0]
   	 return count[0];
   	 
	case 1: //"pylon":   	 // count[1]
   	 return count[1];
   	 
	case 2: //"assimilator":   	 // count[2]
   	 return count[2];   

	case 3:  //"gateway"://count[3]
   	 return count[3];
   	 
	case 4: //"forge"://count[4]
   	 return count[4];
   	 
	case 5: //"photon cannon":    //count[5]
   	 return count[5];
   	 
	case 6: //"warpgate"://count[6]
   	 return count[6];
   	 
	case 7: //"cybernetics core"://count[7]
   	 return count[7];
    
	case 8: //"twilight council":    //count[8]
   	 return count[8];
    
	case 9: //"robotics facility":    //count[9]
   	 return count[9];
    
	case 10: //"stargate":    //count[10]
   	 return count[10];
   	 
	case 11: //"templar archives":    //count[11]
   	 return count[11];
   	 
	case 12: //"dark shrine":    //count[12]
   	 return count[12];
    
	case 13: //"robotics bay"://count[13]
   	 return count[13];
	 
	case 14: //"fleet beacon": // count[14]
	 return count[14];
    
    default:
   	 cout << "Not valid building" << endl;
   	 return 0;
    
    }
    
    return 0;
}




/*******Protoss Unit Class Functions**************/
Protoss::Units::Units(){
	count [0] = 6;
	for (int i=1; i<P_UNIT_TOT; i++){
		count[i] = 0;
	}
	//Unit Property Arrays
	for (int i=0; i<P_UNIT_TOT; i++){
		attack[i] = P_ATT[i];
	}

	for (int i=0; i<P_UNIT_TOT; i++){
		health[i] = P_HLT[i];
	}

	for (int i=0; i<P_UNIT_TOT; i++){
		armor[i] = P_ARM[i];
	}

	//Cost Arrays
	for (int i=0; i<P_UNIT_TOT; i++){
		minCost[i] = P_MIN_COST[i];
	}

	for (int i=0; i<P_UNIT_TOT; i++){
		gasCost[i] = P_GAS_COST[i];
	}

	for (int i=0; i<P_UNIT_TOT; i++){
		supplyCost[i] = P_SUP_COST[i];
	}
	for (int i=0; i<P_UNIT_TOT; i++){
		buildingReq[i] = P_BLD_REQ[i];
	}
}
void Protoss::Units::add(int i){
	count[i]++;
}
int Protoss::Units::howmany(int i){
	return count[i];
}

