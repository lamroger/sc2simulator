#include "Protoss.h"

Protoss::Protoss() {
	unit_count[0] = 6; //Initial Drones
	building_count[0] = 1; //initial nexus
  
	mineral_workers = 6;
	gas_workers = 0;
	mining_bases = 1;
	army_value = 0;
	max_supply = 10;
  
	minerals = 50;
	gas = 0;
  
}

int Protoss::minerals_per_min() {
	return mineral_workers*40;
}

int Protoss::gas_per_min() {
	return gas_workers*38;
}

void Protoss::print() {
	cout << "Minerals per Minute: " << minerals_per_min()  << "\n";
	cout << "Gas per Minute: " << gas_per_min()  << "\n";
	cout << "\n";
	cout << "Mineral Workers: " << mineral_workers  << "\n";
	cout << "Gas Workers: " << gas_workers  << "\n";
	cout << "Mining Bases: " << mining_bases  << "\n";
	cout << "Max Supply: " << max_supply  << "\n";
	cout << "Army Value: " << army_value  << "\n";
}


void Protoss::make_unit(int index) {
	switch (index) {
		case 0:
			if (minerals >= 50) {
				minerals -= 50;
				unit_count[index]++;
				mineral_workers++;
			} else {
				//Error: we require more minerals
			}
			break;

		case 1:
			if (minerals >= 100) {
				minerals -= 100;
				unit_count[index]++;
				army_value += 1;
			} else {
				//Error: we require more minerals
			}
			break;

		case 2:
			if (minerals >= 125 && gas >= 50) {
				minerals -= 125;
				gas -= 50;
				unit_count[index]++;
				army_value += 2;
			} else {
				//Error: we require more minerals
			}
			break;

		case 3:
			if (minerals >= 50 && gas >= 100) {
				minerals -= 50;
				gas -= 100;
				unit_count[index]++;
				army_value += 1;
			} else {
				//Error: we require more minerals
			}
			break;

		case 4:
			if (minerals >= 50 && gas >= 150) {
				minerals -= 50;
				gas -= 150;
				unit_count[index]++;
				army_value += 2;
			} else {
				//Error: we require more minerals
			}
			break;

		case 5:
			if (minerals >= 125 && gas >= 125) {
				minerals -= 125;
				gas -= 125;
				unit_count[index]++;
				army_value += 2;
			} else {
				//Error: we require more minerals
			}
			break;

		case 6:
			if (minerals >= 250 && gas >= 100) {
				minerals -= 250;
				gas -= 100;
				unit_count[index]++;
				army_value += 4;
			} else {
				//Error: we require more minerals
			}
			break;

		case 7:
			if (minerals >= 300 && gas >= 200) {
				minerals -= 300;
				gas -= 200;
				unit_count[index]++;
				army_value += 6;
			} else {
				//Error: we require more minerals
			}
			break;

		case 8:
			if (true){//there exists two templars
				unit_count[index]++;
			} else {
				//Error: we require more templars
			}
			break;

		case 9:
			if (minerals >= 25 && gas >= 75) {
				minerals -= 25;
				gas -= 75;
				unit_count[index]++;
				army_value += 1;
			} else {
				//Error: we require more minerals
			}
			break;

		case 10:
			if (minerals >= 200 && gas >= 0) {
				minerals -= 200;
				gas -= 0;
				unit_count[index]++;
				army_value += 2;
			} else {
				//Error: we require more minerals
			}
			break;

		case 11:
			if (minerals >= 150 && gas >= 100) {
				minerals -= 150;
				gas -= 100;
				unit_count[index]++;
				army_value += 2;
			} else {
				//Error: we require more minerals
			}
			break;

		case 12:
			if (minerals >= 250 && gas >= 150) {
				minerals -= 250;
				gas -= 150;
				unit_count[index]++;
				army_value += 3;
			} else {
				//Error: we require more minerals
			}
			break;

		case 13:
			if (minerals >= 350 && gas >= 250) {
				minerals -= 350;
				gas -= 250;
				unit_count[index]++;
				army_value += 3;
			} else {
				//Error: we require more minerals
			}
			break;
		case 14:
			if (minerals >= 400 && gas >= 400) {
				minerals -= 400;
				gas -= 400;
				unit_count[index]++;
				army_value += 8;
			} else {
				//Error: we require more minerals
			}
			break;

		default:
			// Error: index out of range, bad input
			break;
	}
}

Protoss::protossbuildings::protossbuildings(){
	for(int i =0; i<15; i++)
	{
		count[i] = 0;
	}
}

bool Protoss::protossbuildings::add(int building)
{
    switch(building) {


	case 0: // "nexus":     // count[0]
   	 count[0]++;
   	 
	case 1: // "pylon":   	 // count[1]
   	 count[1]++;
   	 
	case 2: // "assimilator":   	 // count[2]
   	 count[2]++;   

	case 3: // "gateway"://count[3]
   	 count[3]++;
   	 
	case 4: // "forge": //count[4]
   	 count[4]++;
   	 
	case 5: // "photon cannon":    //count[5]
   	 count[5]++;
   	 
	case 6: //"warpgate"://count[6]
   	 count[6]++;
   	 
	case 7: //"cybernetics core"://count[7]
   	 count[7]++;
    
	case 8: // "twilight council":    //count[8]
   	 count[8]++;
    
	case 9: //"robotics facility":    //count[9]
   	 count[9]++;
    
	case 10: // "stargate":    //count[10]
   	 count[10]++;
   	 
	case 11: // "templar archives":    //count[11]
   	 count[11]++;
   	 
	case 12: // "dark shrine":    //count[12]
   	 count[12]++;
    
	case 13: // "robotics bay"://count[13]
   	 count[13]++;
	 
	case 14: //"fleet beacon": // count[14]
		count[14]++;
    
    default:
   	 cout << "Not valid building" << endl;
   	 return false;
    
    }
    
    return;
}

int Protoss::protossbuildings::howmany(int building)
{
    switch(building) {
    
	case 0: //"nexus":     // count[0]
   	 return count[0]++;
   	 
	case 1: //"pylon":   	 // count[1]
   	 return count[1]++;
   	 
	case 2: //"assimilator":   	 // count[2]
   	 return count[2]++;   

	case 3:  //"gateway"://count[3]
   	 return count[3]++;
   	 
	case 4: //"forge"://count[4]
   	 return count[4]++;
   	 
	case 5: //"photon cannon":    //count[5]
   	 return count[5]++;
   	 
	case 6: //"warpgate"://count[6]
   	 return count[6]++;
   	 
	case 7: //"cybernetics core"://count[7]
   	 return count[7]++;
    
	case 8: //"twilight council":    //count[8]
   	 return count[8]++
    
	case 9: //"robotics facility":    //count[9]
   	 return count[9]++;
    
	case 10: //"stargate":    //count[10]
   	 return count[10]++;
   	 
	case 11: //"templar archives":    //count[11]
   	 return count[11]++;
   	 
	case 12: //"dark shrine":    //count[12]
   	 return count[12]++;
    
	case 13: //"robotics bay"://count[13]
   	 return count[13]++;
	 
	case 14: //"fleet beacon": // count[14]
	 return count[14]++;
    
    default:
   	 cout << "Not valid building" << endl;
   	 return false;
    
    }
    
    return;
}