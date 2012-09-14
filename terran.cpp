#include "terran.h"
#include <conio.h>

extern int T_MIN_COST[];
extern int T_GAS_COST[];
extern int T_SUP_COST[];
extern int T_BLD_REQ[];

extern int T_ATT[];
extern double T_SPEED[];
extern int T_HLT[];
extern int T_ARM[];

extern int T_UNIT_TOT;

extern int T_MIN_COST[];
extern int T_GAS_COST[];
extern int T_SUP_COST[];
extern int T_BUILDING_MIN_COST[];
extern int T_BUILDING_GAS_COST[];

Terran::Terran() {
	//unit_count[0] = 6; //Initial SCV
	//for(int i = 1; i <T_UNIT_TOT; i++)
	//	unit_count[i] = 0;
  
	mineral_workers = 6;
	gas_workers = 0;
	mining_bases = 1;
	army_value = 6;
	max_supply = 10;
  
	minerals = 50;
	gas = 0;
  
	string units[15] = {"scv", "marine", "marauder", "reaper", "ghost", "hellion", "seige tank", "thor", "viking", 
						"medivac", "banshee", "raven", "battlecruiser", "mule", ""};
	string buildings[15] = {"command center", "orbital command", "planetary fortress", "supply depot", "refinery", "barracks", "engineering bay",
						"bunker", "factory", "ghost academy", "armory", "starport", "fusion core", "tech lab", "reactor"};
	for(int i = 0; i < 15; i++)
		buildingnames[i] = buildings[i];

	for(int i = 0; i < 15; i++)
		unitnames[i] = units[i];

	for(int i = 0; i < 14; i++)
		unit_min[i] = T_MIN_COST[i];
	
	for(int i = 0; i < 14; i++)
		unit_gas[i] = T_GAS_COST[i];

	for(int i = 0; i < 14; i++)
		unit_supply[i] = T_SUP_COST[i];

	for(int i = 0; i < 15; i++)
		building_min[i] = T_BUILDING_MIN_COST[i];

	for(int i = 0; i < 15; i++)
		building_gas[i] = T_BUILDING_GAS_COST[i];
}

int Terran::minerals_per_min() {
	return mineral_workers*40;
}

int Terran::gas_per_min() {
	return gas_workers*38;
}

int Terran::get_mineral() const
{
	return minerals;
}

int Terran::get_gas() const
{
	return gas;
}

ostream& Terran::operator<< (ostream& out)
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

void Terran::print() {
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

void Terran::make_unit(int index) {
		if (unitCheckReq(index)){ 
		terranUnits.add(index); //increments number of units
		change_minerals(terranUnits.getMinCost(index)*(-1));
		change_gas(terranUnits.getGasCost(index)*(-1));
		army_value = army_value + terranUnits.getSupplyCost(index);
		if (index == 0)
			mineral_workers++;
		
	}else
		cout << "Build failed" << endl;
}

bool Terran::make_building(int index) {
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
			if (minerals >= 150 && howmanybuildings(0) >= 1) {
				if(buildings.add(index))
					minerals -= 150;
			} else {
				throw "we require more minerals";
			}
			break;

		case 2:
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

		case 3:
			if (minerals >= 100 ) {
				if(buildings.add(index))
				{
					minerals -= 100;
					max_supply += 8;
				}
			} else {
				throw "we require more minerals";
			}
			break;

		case 4:
			if (minerals >= 75) {
				if(buildings.add(index))
					minerals -= 75;
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
			if (minerals >= 125) {
				if(buildings.add(index))
				minerals -= 125;
			} else {
				throw "we require more minerals";
			}
			break;

		case 7:
			if (minerals >= 100) {
				if(buildings.add(index))
					minerals -= 100;
			} else {
				throw "we require more minerals";
			}
			break;

		case 8:
			if (minerals >= 150 && gas >= 100) {
				minerals -= 150;
				gas -= 100;
				buildings.add(index);
			} else {
				throw "we require more minerals";
			}
			break;

		case 9:
			if (minerals >= 150 && gas >= 50) {
				if(buildings.add(index))
				{
					minerals -= 150;
					gas -= 50;
				}
			} else {
				throw "we require more minerals";
			}
			break;

		case 10:
			if (minerals >= 150 && gas >= 100) {
				if(buildings.add(index))
				{
					minerals -= 150;
					gas -= 100;
				}

			} else {
				throw "we require more minerals";
			}
			break;

		case 11:
			if (minerals >= 150 && gas >= 100) {
				if(buildings.add(index))
				{
					minerals -= 150;
					gas -= 100;
				}

			} else {
				throw "we require more minerals";
			}
			break;

		case 12:
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

		case 13:
			if (minerals >= 50 && gas >= 25) {
				if(buildings.add(index))
				{
					minerals -= 50;
					gas -= 25;
				}
				
			} else {
				throw "we require more minerals";
			}
			break;

		case 14:
			if (minerals >= 50 && gas >= 50) {
				if(buildings.add(index))
				{
					minerals -= 50;
					gas -= 50;
				}
				
			} else {
				throw "we require more minerals";
			}
			break;

		default:
			throw "index not valid";
			break;
	}
	}

	catch(char* e)
	{
		cout << e << endl;
		return false;
	}

	return true;
}

void Terran::change_minerals(int i)
{
	minerals += i;
}

void Terran::change_gas(int i)
{
	gas += i;
}

int Terran::howmanyunits(int i)
{
	return terranUnits.howmany(i);
}

int Terran::howmanybuildings(int i)
{
	return buildings.howmany(i);
}

bool Terran::unitCheckReq(int i)
{
	try{
			if (i >= T_UNIT_TOT)
				throw "Invalid Index";
			if (terranUnits.getMinCost(i) > minerals)
				throw "Insufficient Minerals";
			if (terranUnits.getGasCost(i) > gas)
				throw "Insufficient Vespene Gas";
			if (terranUnits.getSupplyCost(i) > max_supply - army_value)
				throw "You must construct additional Plyons";
			if (buildings.howmany(terranUnits.getBuildingReq(i))==0)
				throw "Required building has not been constructed";
			return true; //All requirements fulfilled
		}
		catch(const char* err){
			cout << err << endl << endl << "Press any key to return to main menu...";
			char control = getch();
			return false;
		}
}
int Terran::get_army() {
	return army_value;
}

int Terran::army_health()
{
	int health = 0;
	for(int i = 0; i <T_UNIT_TOT; i++)
		health += (terranUnits.howmany(i)*T_HLT[i]);
	return health;
}

int Terran::army_attack()
{
	double attack = 0;
	for(int i = 0; i<T_UNIT_TOT; i++)
		attack += (terranUnits.howmany(i)*T_ATT[i]*T_SPEED[i]);
	return (int)attack;
}

/***************Building class****************************/

bool Terran::terranbuildings::add(int building)
{
	try
	{
    switch(building) {
    
	case 0: // "command center":     // count[0]
   	 count[0]++;
	 break;
   	 
    case 1: //"orbital command":   	 // count[1]
   	 if(count[0] == 0) {
   		 cout << "No command centers to upgrade" << endl;
		 cout << count[0] << endl;
   		 break;
   	 }
	 count[1]++;
	 count[0]--;
	 break;
   	 
    case 2: //"planetary fortress":   	 // count[2]
   	 if(count[0] == 0) {
   		 cout << "No command centers to upgrade" << endl;
   		 break;
   	 }
	 count[2]++;  
	 count[0]--;

	case 3: // "supply depot"://count[3]
   	 count[3]++;
	 break;
   	 
	case 4: //"refinery"://count[4]
   	 count[4]++;
	 break;
   	 
	case 5: //"barracks":    //count[5]
	 if(count[0] > 0 || count[1] > 0 || count[2] > 0)
	 {
   		count[5]++;
		break;
	 }
	 else
		throw "we require a command center";
   	 
	case 6: //"engineering bay"://count[6]
	 if(count[0] > 0 || count[1] > 0 || count[2] > 0)
   		count[6]++;
	 else
		throw "we require a command center";
   	 
	case 7: //"bunker"://count[7]
	if(count[5] > 0)
   	 count[7]++;
	else
		throw "we require a barracks";
    
	case 8: //"missile turret":    //count[8]
	if(count[6] > 0)
   	 count[8]++;
	else
		throw "we require a engineering bay";
    
	case 9: //"sensor tower":    //count[9]
	if(count[6] > 0)
   	 count[9]++;
	else
		throw "we require a engineering bay";
    
	case 10: //"factory":    //count[10]
	if(count[5] > 0)
   	 count[10]++;
	else
		throw "we require a barracks";
   	 
	case 11: //"ghost academy":    //count[11]
	if(count[5] > 0)
   	 count[11]++;
	else
		throw "we require a barracks";
   	 
	case 12: //"armory":    //count[12]
	if(count[10] > 0)
   	 count[12]++;
	else
		throw "we require a factory";
    
	case 13: //"starport"://count[13]
	if(count[10] > 0)
   	 count[13]++;
	else
		throw "we require a factory";
	 
	case 14: //"tech lab barracks": // count[14]
	if(count[5] > 0)
   	 count[14]++;
	else
		throw "we require a barracks";

	case 15: //"tech lab starport": // count[14]
	if(count[13] > 0)
   	 count[15]++;
	else
		throw "we require a starport";
    
    default:
   	 cout << "Not valid building" << endl;
   	 return false;
    
    }
	}
	catch(string e)
	{
		cout << e;
		return false;
	}
    
    return true;
}

int Terran::terranbuildings::howmany(int building)
{
    switch(building) {
    
	case 0: //"command center":     // count[0]
   	 return count[0];
   	 
    case 1: //"orbital command":   	 // count[1]
	 return count[1];
   	 
    case 2: //"planetary fortress":   	 // count[2]
	 return count[2];   

	case 3: //"supply depot"://count[3]
   	 return count[3];
   	 
	case 4: //"refinery"://count[4]
   	 return count[4];
   	 
	case 5: //"barracks":    //count[5]
   	 return count[5];
   	 
	case 6: //"engineering bay"://count[6]
   	 return count[6];
   	 
	case 7: //"bunker"://count[7]
   	 return count[7];
    
	case 8: //"missile turret":    //count[8]
   	 return count[8];
    
	case 9: //"sensor tower":    //count[9]
   	 return count[9];
    
	case 10: //"factor":    //count[10]
   	 return count[10];
   	 
	case 11: //"ghost academy":    //count[11]
   	 return count[11];
   	 
	case 12: //"armory":    //count[12]
   	 return count[12];
    
	case 13: //"starport"://count[13]
   	 return count[13];
	 
	case 14: //"tech lab": // count[14]
	 return count[14];
    
	default:
	 return 0;
	}

	return 0;
}

Terran::terranbuildings::terranbuildings(){
	count[0] = 1;
	for(int i =1; i<15; i++)
	{
		count[i] = 0;
	}
}

/*******Protoss Unit Class Functions**************/
Terran::Units::Units(){
	count [0] = 6;
	for (int i=1; i<T_UNIT_TOT; i++){
		count[i] = 0;
	}
	//Unit Property Arrays
	for (int i=0; i<T_UNIT_TOT; i++){
		attack[i] = T_ATT[i];
	}

	for (int i=0; i<T_UNIT_TOT; i++){
		health[i] = T_HLT[i];
	}

	for (int i=0; i<T_UNIT_TOT; i++){
		armor[i] = T_ARM[i];
	}

	//Cost Arrays
	for (int i=0; i<15; i++){
		minCost[i] = T_MIN_COST[i];
	}

	for (int i=0; i<T_UNIT_TOT; i++){
		gasCost[i] = T_GAS_COST[i];
	}

	for (int i=0; i<T_UNIT_TOT; i++){
		supplyCost[i] = T_SUP_COST[i];
	}
	for (int i=0; i<T_UNIT_TOT; i++){
		buildingReq[i] = T_BLD_REQ[i];
	}
}
void Terran::Units::add(int i){
	count[i]++;
}
int Terran::Units::howmany(int i){
	return count[i];
}


bool Terran::sendToGas() {
	if (mineral_workers >= 1 && gas_workers < buildings.howmany(3)*3) {
		mineral_workers--;
		gas_workers++;
		return true;
	}
	return false;
}

bool Terran::sendToMin() {
	if (gas_workers > 0) {
		mineral_workers++;
		gas_workers--;
		return true;
	}
	return false;
}

void Terran::addLarva() {

}

int Terran::getLarva() {
	return 0;
}