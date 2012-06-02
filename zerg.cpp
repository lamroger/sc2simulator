#include "zerg.h"

Zerg::Zerg() {
  unit_count[0] = 6; //Initial Drones
  unit_count[1] = 1; //Initial Overlord
  
  mineral_workers = 6;
  gas_workers = 0;
  mining_bases = 1;
  army_value = 0;
  larva = 3;
  max_supply = 10;
  
  minerals = 50;
  gas = 0;

  
}

int Zerg::minerals_per_min() {
  return mineral_workers*40;
}

int Zerg::gas_per_min() {
  return gas_workers*38;
}

void Zerg::print() {
	cout << "Minerals per Minute: " << minerals_per_min()  << "\n";
	cout << "Gas per Minute: " << gas_per_min()  << "\n";
	cout << "\n";
	cout << "Mineral Workers: " << mineral_workers  << "\n";
	cout << "Gas Workers: " << gas_workers  << "\n";
	cout << "Mining Bases: " << mining_bases  << "\n";
	cout << "Max Supply: " << max_supply  << "\n";
	cout << "Army Value: " << army_value  << "\n";
	cout << "Larva: " << larva  << "\n";
}

void Zerg::make_unit(int index) {
	switch (index) {
		case 0:
			if (larva > 0) {
				larva--;
				unit_count[index]++;
				mineral_workers++;
			} else {
				//Error: not enough larva
			}
			break;

		case 1:
			if (larva > 0) {
				larva--;
				unit_count[index]++;
				max_supply += 8;
			} else {
				//Error: not enough larva
			}
			break;

		case 2:
			if (larva > 0) {
				larva--;
				unit_count[index]++;
				army_value += 1;
			} else {
				//Error: not enough larva
			}
			break;

		case 3:
			
			//account for # hatches and build time
			unit_count[index]++;
			army_value += 2;
			break;

		case 4:
			//doesnt do much since we dont accout for cloaking/scouting
			break;

		case 5:
			if (larva > 0) {
				larva--;
				unit_count[index]++;
				army_value += 2;
			} else {
				//Error: not enough larva
			}
			break;

		case 6:
			// each supply of zerglings give 2 lings, baneling takes only one ling but we assume it take 1 supply instead
			if (unit_count[2] > 0) {
				unit_count[2]--;
				unit_count[index]++;
			} else {
				//Error: not enough larva
			}
			break;

		case 7:
			if (larva > 0) {
				larva--;
				unit_count[index]++;
				army_value += 2;
			} else {
				//Error: not enough larva
			}
			break;

		case 8:
			if (larva > 0) {
				larva--;
				unit_count[index]++;
				army_value += 2;
			} else {
				//Error: not enough larva
			}
			break;

		case 9:
			if (larva > 0) {
				larva--;
				unit_count[index]++;
				army_value += 2;
			} else {
				//Error: not enough larva
			}
			break;

		case 10:
			if (larva > 0) {
				larva--;
				unit_count[index]++;
				army_value += 2;
			} else {
				//Error: not enough larva
			}
			break;

		case 11:
			if (larva > 0) {
				larva--;
				unit_count[index]++;
				army_value += 6; //WHOPPING 6 SUPPLY!?!?!
			} else {
				//Error: not enough larva
			}
			break;

		case 12:
			if (unit_count[10] > 0) {
				unit_count[10];
				unit_count[index]++;
				army_value += 2; // total of 4 supply (corruptor + morphing)
			} else {
				//Error: not enough larva
			}
			break;
		default:
			// Error: index out of range, bad input
			break;
	}
}

Zerg::zergbuildings::zergbuildings(){
	for(int i =0; i<14; i++)
	{
		count[i] = 0;
	}
}

bool Zerg::zergbuildings::add(int building)
{
    switch(building) {
    
	case 0: // "hatchery":     // count[0]
   	 count[0]++;
   	 
	case 1: // "lair":   	 // count[1]
   	 if(count[0] == 0) {
   		 cout << "No hatcheries to upgrade" << endl;
   		 break;
   	 }
   	 count[1]++;
   	 count[0]--;
   	 
	case 2: // "hive":   	 // count[2]
   	 if(count[1] == 0) {
   		 cout << "No lairs to upgrade" << endl;
   		 break;
   	 }
   	 count[2]++;
   	 count[1]--;    

	case 3: //"spine crawler"://count[3]
   	 count[3]++;
   	 
	case 4: //"spore crawler"://count[4]
   	 count[4]++;
   	 
	case 5: // "extractor":    //count[5]
   	 count[5]++;
   	 
	case 6: // "spawning pool"://count[6]
   	 count[6]++;
   	 
	case 7: // "evolution chamber"://count[7]
   	 count[7]++;
    
	case 8: // "roach warren":    //count[8]
   	 count[8]++;
    
	case 9: // "baneling nest":    //count[9]
   	 count[9]++;
    
	case 10: // "hydralisk den":    //count[10]
   	 count[10]++;
   	 
	case 11: // "spire":    //count[11]
   	 count[11]++;
   	 
	case 12: // "greater spire":    //count[12]
   	 count[12]++;
    
	case 13: // "ultralisk cavern"://count[13]
   	 count[13]++;
    
    default:
   	 cout << "Not valid building" << endl;
   	 return false;
    
    }
    
    return;
}

int Zerg::zergbuildings::howmany(string building)
{
    switch(building) {
    
	case "hatchery":     // count[0]
   	 return count[0];
   	 
    case "lair":   	 // count[1]
   	 return count[1];

   	 
    case "hive":   	 // count[2]
   	 return count[2];

	case "spine crawler"://count[3]
   	 return count[3];
   	 
	case "spore crawler"://count[4]
   	 return count[4];
   	 
	case "extractor":    //count[5]
   	 return count[5];
   	 
	case "spawning pool"://count[6]
   	 return count[6];
   	 
	case "evolution chamber"://count[7]
   	 return count[7];
    
	case "roach warren":    //count[8]
   	 return count[8];
    
	case "baneling nest":    //count[9]
   	 return count[9];
    
	case "hydralisk den":    //count[10]
   	 return count[10];
   	 
	case "spire":    //count[11]
   	 return count[11];
   	 
	case "greater spire":    //count[12]
   	 return count[12];
    
	case "ultralisk cavern"://count[13]
   	 return count[13];
    
    default:
   	 cout << "Not valid building" << endl;
   	 return false;
    
    }
    
    return;
}