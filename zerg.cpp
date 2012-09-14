#include "zerg.h"
#include <conio.h>

extern int Z_MIN_COST[];
extern int Z_GAS_COST[];
extern int Z_SUP_COST[];
extern int Z_BLD_REQ[];

extern int Z_ATT[];
extern double Z_SPEED[];
extern int Z_HLT[];
extern int Z_ARM[];

extern int Z_UNIT_TOT;

extern int Z_MIN_COST[];
extern int Z_GAS_COST[];
extern int Z_SUP_COST[];
extern int Z_BUILDING_MIN_COST[];
extern int Z_BUILDING_GAS_COST[];

Zerg::Zerg() {
 // unit_count[0] = 6; //Initial Drones
 // unit_count[1] = 1; //Initial Overlord
 // for(int i = 2; i < 13; i++)
 //	  unit_count[i] = 0;
  
  mineral_workers = 6;
  gas_workers = 0;
  mining_bases = 1;
  army_value = 6;
  larva = 3;
  max_supply = 10;
  
  minerals = 50;
  gas = 0;
  
  string units[15] = {"drone", "overlord", "zergling", "queen", "overseer", "roach", "baneling", 
						"hydralisk", "infestor", "mutalisk", "corruptor", "ultralisk", "broodlord", "", ""};
	for(int i = 0; i < 15; i++)
		unitnames[i] = units[i];
	
  string building[15] = {"hatchery", "lair", "hive", "spine crawler", "spore crawler", "extractor", "spawning pool", "evolution chamber", 
							"roach warren", "baneling nest", "hydralisk den", "spire", "greater spire", "ultralisk cavern", ""};

	for(int i = 0; i < 13; i++)
		buildingnames[i] = building[i];

	for(int i = 0; i < 13; i++)
		unit_min[i] = Z_MIN_COST[i];
	
	for(int i = 0; i < 13; i++)
		unit_gas[i] = Z_GAS_COST[i];

	for(int i = 0; i < 13; i++)
		unit_supply[i] = Z_SUP_COST[i];

	for(int i = 0; i < 14; i++)
		building_min[i] = Z_BUILDING_MIN_COST[i];

	for(int i = 0; i < 14; i++)
		building_gas[i] = Z_BUILDING_GAS_COST[i];
}

int Zerg::minerals_per_min() {
  return mineral_workers*40;
}

int Zerg::gas_per_min() {
  return gas_workers*38;
}

ostream& Zerg::operator<< (ostream& out)
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

void Zerg::print() {	
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
	cout << "Larva: " << larva  << "\n";
}

bool Zerg::make_building(int index)
{
try{
	switch (index) {
		case 0:
			if (minerals >= 300 && mineral_workers + gas_workers > 0 ) {
				if(buildings.add(index))
					minerals -= 300;
					if(mineral_workers > 0) {
						mineral_workers--;
					} else {
						gas_workers--;
					}
			} else {
				throw "we require more minerals";
			}
			break;

		case 1:
			if (minerals >= 150 && gas >=100 && mineral_workers + gas_workers > 0 ) {
				if (buildings.add(index)){
					minerals -= 150;
					gas -= 100;
					if(mineral_workers > 0) {
						mineral_workers--;
					} else {
						gas_workers--;
					}
				}
			} else {
				throw "we require more minerals";
			}
			break;

		case 2:
			if (minerals >= 200 && gas >= 150 && mineral_workers + gas_workers > 0 ) {
				if(buildings.add(index))
				{
					minerals -= 150;
					gas -= 150;
					if(mineral_workers > 0) {
						mineral_workers--;
					} else {
						gas_workers--;
					}
				}

			} else {
				throw "we require more minerals";
			}
			break;

		case 3:
			if (minerals >= 100  && mineral_workers + gas_workers > 0 ) {
				if(buildings.add(index))
					minerals -= 100;
					if(mineral_workers > 0) {
						mineral_workers--;
					} else {
						gas_workers--;
					}
			} else {
				throw "we require more minerals";
			}
			break;

		case 4:
			if (minerals >= 75 && mineral_workers + gas_workers > 0 ) {
				if(buildings.add(index))
					minerals -= 75;
					if(mineral_workers > 0) {
						mineral_workers--;
					} else {
						gas_workers--;
					}
	
			} else {
				throw "we require more minerals";
			}
			break;

		case 5:
			if (minerals >= 25 && mineral_workers + gas_workers > 0 ) {
				if(buildings.add(index))
					minerals -= 25;
					if(mineral_workers > 0) {
						mineral_workers--;
					} else {
						gas_workers--;
					}
			} else {
				throw "we require more minerals";
			}
			break;

		case 6:
			if (minerals >= 200 && mineral_workers + gas_workers > 0 ) {
				if(buildings.add(index))
					minerals -= 200;
					if(mineral_workers > 0) {
						mineral_workers--;
					} else {
						gas_workers--;
					}
			} else {
				throw "we require more minerals";
			}
			break;

		case 7:
			if (minerals >= 75 && mineral_workers + gas_workers > 0 ) {
				if(buildings.add(index))
					minerals -= 75;
					if(mineral_workers > 0) {
						mineral_workers--;
					} else {
						gas_workers--;
					}
			} else {
				throw "we require more minerals";
			}
			break;

		case 8:
			if (minerals >= 150 && mineral_workers + gas_workers > 0 ) {
				if(buildings.add(index))
					minerals -= 150;
					if(mineral_workers > 0) {
						mineral_workers--;
					} else {
						gas_workers--;
					}
			} else {
				throw "we require more minerals";
			}
			break;

		case 9:
			if (minerals >= 100 && gas >= 50 && mineral_workers + gas_workers > 0 ) {
				if(buildings.add(index))
				{
					minerals -= 100;
					gas -= 50;
					if(mineral_workers > 0) {
						mineral_workers--;
					} else {
						gas_workers--;
					}
				}

			} else {
				throw "we require more minerals";
			}
			break;

		case 10:
			if (minerals >= 100 && gas >= 100 && mineral_workers + gas_workers > 0 ) {
				if(buildings.add(index))
				{
					minerals -= 100;
					gas -= 100;
					if(mineral_workers > 0) {
						mineral_workers--;
					} else {
						gas_workers--;
					}
				}
	
			} else {
				throw "we require more minerals";
			}
			break;

		case 11:
			if (minerals >= 200 && gas >= 200 && mineral_workers + gas_workers > 0 ) {
				if(buildings.add(index))
				{
					minerals -= 150;
					gas -= 150;
					if(mineral_workers > 0) {
						mineral_workers--;
					} else {
						gas_workers--;
					}
				}
				
			} else {
				throw "we require more minerals";
			}
			break;

		case 12:
			if (minerals >= 100 && gas >= 150 && mineral_workers + gas_workers > 0 ) {
				if(buildings.add(index))
				{
					minerals -= 50;
					gas -= 25;
					if(mineral_workers > 0) {
						mineral_workers--;
					} else {
						gas_workers--;
					}
				}

			} else {
				throw "we require more minerals";
			}
			break;

		case 13:
			if (minerals >= 150 && gas >= 200 && mineral_workers + gas_workers > 0 ) {
				if(buildings.add(index))
				{
					minerals -= 50;
					gas -= 50;
					if(mineral_workers > 0) {
						mineral_workers--;
					} else {
						gas_workers--;
					}
				}

			} else {
				throw "we require more minerals";
			}
			break;

		default:
			throw "index not valid";
			return false;
			break;
	}
	}

	catch(char* e)
	{
		cout << e << endl;
		return false;
	}

	zergUnits.subdrone();
	return true;
}

int Zerg::get_mineral() const
{
	return minerals;
}

int Zerg::get_gas() const
{
	return gas;
}

void Zerg::make_unit(int index) {

	if (unitCheckReq(index)){ 
		zergUnits.add(index); //increments number of units
		change_minerals(zergUnits.getMinCost(index)*(-1));
		change_gas(zergUnits.getGasCost(index)*(-1));
		army_value = army_value + zergUnits.getSupplyCost(index);
		if (index == 0)
			mineral_workers++;
		if (index == 1)
			max_supply += 8;
		
	}else
		cout << "Build failed" << endl;
}

void Zerg::change_minerals(int i)
{
	minerals += i;
}

void Zerg::change_gas(int i)
{
	gas += i;
}

int Zerg::get_army() {
	return army_value;
}

int Zerg::army_health()
{
	int health = 0;
	for(int i = 0; i <Z_UNIT_TOT; i++)
		health += (zergUnits.howmany(i)*Z_HLT[i]);
	return health;
}
int Zerg::army_attack()
{
	double attack = 0;
	for(int i = 0; i<Z_UNIT_TOT; i++)
		attack += (zergUnits.howmany(i)*Z_ATT[i]*Z_SPEED[i]);
	return (int)attack;
}

int Zerg::howmanybuildings(int i)
{
	return buildings.howmany(i);
}

int Zerg::howmanyunits(int i)
{
	return zergUnits.howmany(i);
}

bool Zerg::unitCheckReq(int i)
{
	try{
			if (i > 13)
				throw "Invalid Index";
			if (zergUnits.getMinCost(i) > minerals)
				throw "Insufficient Minerals";
			if (zergUnits.getGasCost(i) > gas)
				throw "Insufficient Vespene Gas";
			if (zergUnits.getSupplyCost(i) > max_supply - army_value)
				throw "You must construct additional Overlords";
			if (buildings.howmany(zergUnits.getBuildingReq(i))==0)
				if(zergUnits.getBuildingReq(i) == 0)
					if(buildings.howmany(0)==0 && buildings.howmany(1)==0 && buildings.howmany(2)==0)
						throw "Required building has not been constructed";
					else 
						throw "Required building has not been constructed";
				else 
					throw "Required building has not been constructed";
			return true; //All requirements fulfilled
		}
		catch(const char* err){
			cout << err << endl << endl << "Press any key to return to main menu...";
			char control = getch();
			return false;
		}

}



/********Zerg building class****************/

Zerg::zergbuildings::zergbuildings(){
	count[0] = 1;
	for(int i = 1; i<14; i++)
	{
		count[i] = 0;
	}
}

bool Zerg::zergbuildings::add(int building)
{
    switch(building) {
    
	case 0: // "hatchery":     // count[0]
   	 count[0]++;
	 break;
   	 
	case 1: // "lair":   	 // count[1]
   	 if(count[0] == 0) {
   		 cout << "No hatcheries to upgrade" << endl;
   		 break;
   	 }
   	 count[1]++;
   	 count[0]--;
	 break;
   	 
	case 2: // "hive":   	 // count[2]
   	 if(count[1] == 0) {
   		 cout << "No lairs to upgrade" << endl;
   		 break;
   	 }
   	 count[2]++;
   	 count[1]--;
	 break;

	case 3: //"spine crawler"://count[3]
   	 count[3]++;
	 break;
   	 
	case 4: //"spore crawler"://count[4]
   	 count[4]++;
	 break;
   	 
	case 5: // "extractor":    //count[5]
   	 count[5]++;
	 break;
   	 
	case 6: // "spawning pool"://count[6]
   	 count[6]++;
	 break;
   	 
	case 7: // "evolution chamber"://count[7]
   	 count[7]++;
	 break;
    
	case 8: // "roach warren":    //count[8]
   	 count[8]++;
	 break;
    
	case 9: // "baneling nest":    //count[9]
   	 count[9]++;
	 break;
    
	case 10: // "hydralisk den":    //count[10]
   	 count[10]++;
	 break;
   	 
	case 11: // "spire":    //count[11]
   	 count[11]++;
	 break;
   	 
	case 12: // "greater spire":    //count[12]
   	 count[12]++;
	 break;
    
	case 13: // "ultralisk cavern"://count[13]
   	 count[13]++;
	 break;
    
    default:
   	 cout << "Not valid building" << endl;
   	 return false;
    
    }
    
    return true;
}

int Zerg::zergbuildings::howmany(int building)
{
    switch(building) {
    
	case 0: // "hatchery":     // count[0]
   	 return count[0];
   	 
	case 1: // "lair":   	 // count[1]
   	 return count[1];

	case 2: // "hive":   	 // count[2]
   	 return count[2];

	case 3: // "spine crawler"://count[3]
   	 return count[3];
   	 
	case 4: // "spore crawler"://count[4]
   	 return count[4];
   	 
	case 5: // "extractor":    //count[5]
   	 return count[5];
   	 
	case 6: // "spawning pool"://count[6]
   	 return count[6];
   	 
	case 7: // "evolution chamber"://count[7]
   	 return count[7];
    
	case 8: // "roach warren":    //count[8]
   	 return count[8];
    
	case 9: // "baneling nest":    //count[9]
   	 return count[9];
    
	case 10: // "hydralisk den":    //count[10]
   	 return count[10];
   	 
	case 11: // "spire":    //count[11]
   	 return count[11];
   	 
	case 12: // "greater spire":    //count[12]
   	 return count[12];
    
	case 13: // "ultralisk cavern"://count[13]
   	 return count[13];
    
    default:
   	 cout << "Not valid building" << endl;
   	 return 0;
    
    }
    
    return 0;
}

/**************Zerg Unit Class**************/
Zerg::Units::Units(){
	count [0] = 6;
	count [1] = 1;
	for (int i=2; i<13; i++){
		count[i] = 0;
	}
	//Unit Property Arrays
	for (int i=0; i<Z_UNIT_TOT; i++){
		attack[i] = Z_ATT[i];
	}

	for (int i=0; i<Z_UNIT_TOT; i++){
		health[i] = Z_HLT[i];
	}

	for (int i=0; i<Z_UNIT_TOT; i++){
		armor[i] = Z_ARM[i];
	}

	//Cost Arrays
	for (int i=0; i<Z_UNIT_TOT; i++){
		minCost[i] = Z_MIN_COST[i];
	}

	for (int i=0; i<Z_UNIT_TOT; i++){
		gasCost[i] = Z_GAS_COST[i];
	}

	for (int i=0; i<Z_UNIT_TOT; i++){
		supplyCost[i] = Z_SUP_COST[i];
	}
	for (int i=0; i<Z_UNIT_TOT; i++){
		buildingReq[i] = Z_BLD_REQ[i];
	}
}
void Zerg::Units::add(int i){
	count[i]++;
}
int Zerg::Units::howmany(int i){
	return count[i];
}


bool Zerg::sendToGas() {
	if (mineral_workers >= 1 && gas_workers < buildings.howmany(5)*3) {
		mineral_workers--;
		gas_workers++;
		return true;
	}
	return false;
}

bool Zerg::sendToMin() {
	if (gas_workers > 0) {
		mineral_workers++;
		gas_workers--;
		return true;
	}
	return false;
}

void Zerg::addLarva() {
	larva++;
}

int Zerg::getLarva() {
	return larva;
}