#include "terran.h"

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
			if (true)//there exists two templars
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