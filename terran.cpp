#include "terran.h"

Terran::Terran() {
	unit_count[0] = 6; //Initial Drones
	unit_count[1] = 1; //Initial Overlord
  
	mineral_workers = 6;
	gas_workers = 0;
	mining_bases = 1;
	army_value = 0;
	max_supply = 10;
  
	minerals = 50;
	gas = 0;
  
}

int Terran::minerals_per_min() {
	return mineral_workers*40;
}

int Terran::gas_per_min() {
	return gas_workers*38;
}

void Terran::print() {
	cout << "Minerals per Minute: " << minerals_per_min()  << "\n";
	cout << "Gas per Minute: " << gas_per_min()  << "\n";
	cout << "\n";
	cout << "Mineral Workers: " << mineral_workers  << "\n";
	cout << "Gas Workers: " << gas_workers  << "\n";
	cout << "Mining Bases: " << mining_bases  << "\n";
	cout << "Max Supply: " << max_supply  << "\n";
	cout << "Army Value: " << army_value  << "\n";
}


void Terran::make_unit(int index) {
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
			if (minerals >= 50) {
				minerals -= 50;
				unit_count[index]++;
				army_value += 1;
			} else {
				//Error: we require more minerals
			}
			break;

		case 2:
			if (minerals >= 100 && gas >= 25) {
				minerals -= 100;
				gas -= 25;
				unit_count[index]++;
				army_value += 2;
			} else {
				//Error: we require more minerals
			}
			break;

		case 3:
			if (minerals >= 50 && gas >= 50) {
				minerals -= 50;
				gas -= 50;
				unit_count[index]++;
				army_value += 1;
			} else {
				//Error: we require more minerals
			}
			break;

		case 4:
			if (minerals >= 200 && gas >= 100) {
				minerals -= 200;
				gas -= 100;
				unit_count[index]++;
				army_value += 2;
			} else {
				//Error: we require more minerals
			}
			break;

		case 5:
			if (minerals >= 100) {
				minerals -= 100;
				unit_count[index]++;
				army_value += 2;
			} else {
				//Error: we require more minerals
			}
			break;

		case 6:
			if (minerals >= 150 && gas >= 125) {
				minerals -= 150;
				gas -= 125;
				unit_count[index]++;
				army_value += 3;
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
			if (minerals >= 150 && gas >= 75) {
				minerals -= 150;
				gas -= 75;
				unit_count[index]++;
				army_value += 2;
			} else {
				//Error: we require more minerals
			}
			break;

		case 9:
			if (minerals >= 100 && gas >= 100) {
				minerals -= 100;
				gas -= 100;
				unit_count[index]++;
				army_value += 2;
			} else {
				//Error: we require more minerals
			}
			break;

		case 10:
			if (minerals >= 150 && gas >= 100) {
				minerals -= 150;
				gas -= 100;
				unit_count[index]++;
				army_value += 3;
			} else {
				//Error: we require more minerals
			}
			break;

		case 11:
			if (minerals >= 100 && gas >= 200) {
				minerals -= 100;
				gas -= 200;
				unit_count[index]++;
				army_value += 2;
			} else {
				//Error: we require more minerals
			}
			break;

		case 12:
			if (minerals >= 400 && gas >= 300) {
				minerals -= 400;
				gas -= 300;
				unit_count[index]++;
				army_value += 6;
			} else {
				//Error: we require more minerals
			}
			break;

		case 13:
			//Only gathers minerals - need orbital
			break;

		default:
			// Error: index out of range, bad input
			break;
	}
}

void Terran::make_building(int index) {
	switch (index) {
		case 0:
			if (minerals >= 400) {
				minerals -= 400;
				building_count[index]++;
			} else {
				//Error: we require more minerals
			}
			break;

		case 1:
			if (minerals >= 150 && building_count[0] >= 1) {
				minerals -= 150;
				building_count[index]++;
				building_count[0]--;
			} else {
				//Error: we require more minerals
			}
			break;

		case 2:
			if (minerals >= 150 && gas >= 150 && building_count[0] >= 1 && building_count[6] >= 1 ) {
				minerals -= 150;
				gas -= 150;
				building_count[index]++;
				building_count[0]--;
			} else {
				//Error: we require more minerals
			}
			break;

		case 3:
			if (minerals >= 100 ) {
				minerals -= 100;
				building_count[index]++;
				max_supply += 8;
			} else {
				//Error: we require more minerals
			}
			break;

		case 4:
			if (minerals >= 75) {
				minerals -= 75;
				building_count[index]++;
			} else {
				//Error: we require more minerals
			}
			break;

		case 5:
			if (minerals >= 150) {
				minerals -= 150;
				building_count[index]++;
			} else {
				//Error: we require more minerals
			}
			break;

		case 6:
			if (minerals >= 125) {
				minerals -= 125;
				building_count[index]++;
			} else {
				//Error: we require more minerals
			}
			break;

		case 7:
			if (minerals >= 100) {
				minerals -= 100;
				building_count[index]++;
			} else {
				//Error: we require more minerals
			}
			break;

		case 8:
			if (minerals >= 150 && gas >= 100) {
				minerals -= 150;
				gas -= 100;
				building_count[index]++;
			} else {
				//Error: we require more minerals
			}
			break;

		case 9:
			if (minerals >= 150 && gas >= 50) {
				minerals -= 150;
				gas -= 50;
				building_count[index]++;
			} else {
				//Error: we require more minerals
			}
			break;

		case 10:
			if (minerals >= 150 && gas >= 100) {
				minerals -= 150;
				gas -= 100;
				building_count[index]++;
			} else {
				//Error: we require more minerals
			}
			break;

		case 11:
			if (minerals >= 150 && gas >= 100) {
				minerals -= 150;
				gas -= 100;
				building_count[index]++;
			} else {
				//Error: we require more minerals
			}
			break;

		case 12:
			if (minerals >= 150 && gas >= 150) {
				minerals -= 150;
				gas -= 150;
				building_count[index]++;
			} else {
				//Error: we require more minerals
			}
			break;

		case 13:
			if (minerals >= 50 && gas >= 25) {
				minerals -= 50;
				gas -= 25;
				building_count[index]++;
			} else {
				//Error: we require more minerals
			}
			break;

		case 14:
			if (minerals >= 50 && gas >= 50) {
				minerals -= 50;
				gas -= 50;
				building_count[index]++;
			} else {
				//Error: we require more minerals
			}
			break;

		default:
			// Error: index out of range, bad input
			break;
	}
}