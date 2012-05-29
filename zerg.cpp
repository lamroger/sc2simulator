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