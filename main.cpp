#include "zerg.h"
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	
	Zerg player1;
	char key = '0';

	int time = 0;

	do {

		cout << endl << "Starcraft II Simulator" << endl;
		cout << "Contributed by Brandon Dahn, Roger Lam, Anna Ma" << endl << endl;
		player1.print();
			
			
		cout << endl << "Press i to make drone" << endl;
		cout << "Press n to advance one second" << endl;
		cout << "Press q to quit" << endl;
		cout << "Ingame time: " << time << endl;
		key = getch();

		system("cls");

		
		if(key == 'i') {
			player1.make_unit(0);
		}

		if(key == 'n') {
			player1.change_minerals(player1.minerals_per_min() / 60);
			player1.change_gas(player1.gas_per_min() / 60);
			time++;
		}

	} while(key != 'q');



	
	

	return 1;
}
