#include "zerg.h"
#include "terran.h"
#include "protoss.h"
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <cctype>

using namespace std;


template<typename R>
void buildings(R* player)
{
	cout << "Buildings" << endl << endl;
	for(int i = 0; i < 15; i++)
		if(player->buildingnames[i] != "")
			cout << setw (20) << right << player->buildingnames[i] << ": " << player->howmanybuildings(i) << endl;
}

template<typename R>
void units(R* player)
{
	cout << "Units" << endl << endl;
	for(int i = 0; i<15; i++)
		if(player->unitnames[i] != "")
			cout << setw (15) << right << player->unitnames[i] << ": " << player->howmanyunits(i) << endl;
}
template<typename R>
void unitMakeKey(R* player){ 
	cout << "Unit Build Key: Select desired unit by entering corresponding number" << endl;
	cout << setw(3) << right << "#" << " - " << setw (20) << right <<  "Unit Name" << setw(8) << "Own" << setw(27) << "Mineral/Gas/Supply Cost" << endl;
	for (int i=0; i<15; i++){
		if(player->unitnames[i] != "")
			cout << setw(3) << i << " - " << setw (20) << right <<  player->unitnames[i] << setw(8) << player->howmanyunits(i) << setw(7) << player->unit_min[i] << '/' << setw(3) << player->unit_gas[i] << '/' << player->unit_supply[i] << endl;
	}
}

template<typename R>
void build_buildings(R* player)
{
	cout << "Building Build Key: Select desired unit by entering corresponding number" << endl;
	cout << setw(3) << "#" << " - " << setw (20) << right <<  "Building Name" << setw(8) << "Own" << setw(20) << "Mineral/Gas Cost" << endl;
	for(int i = 0; i < 15; i++)
		if(player->buildingnames[i] != "")
			cout << setw(3) << i << " - " << setw (20) << right <<  player->buildingnames[i] << setw(8) << player->howmanybuildings(i) << setw(7) << player->building_min[i] << '/' << player->building_gas[i] << endl;
}

ostream& operator<< (ostream& out, Race* r)
{
	r->print();
	/*cout << "Current Minerals: " << r->get_mineral() << "\n";
	cout << "Current Gas: " << r->get_gas() << "\n\n";
	cout << "Minerals per Minute: " << r->minerals_per_min()  << "\n";
	cout << "Gas per Minute: " << r->gas_per_min()  << "\n";
	cout << "\n";
	cout << "Mineral Workers: " << r->mineral_workers  << "\n";
	cout << "Gas Workers: " << r->gas_workers  << "\n\n";
	cout << "Mining Bases: " << r->mining_bases  << "\n";
	cout << "Max Supply: " << r->max_supply  << "\n";
	cout << "Army Value: " << r->army_value  << "\n";
	cout << "Larva: " << r->larva  << "\n";*/
	return out;
}

int main() {
	Race* player1;
	Race* player2;
	char key = '0';
	char player1_race = '0';
	char player2_race = '0';

	int time = 0;

	cout <<  " _______                        _______" << endl
			<< "|  _____|_____         _____   / _____7_____          _______ _____" << endl
			<< " \\-\\    /_  __\\  <\\   <_  __\\ |-/     <_  __\\    <\\  /_  ___//_  __\\" << endl
			<< "  \\ \\   \\v| |    /_\\   | | \\\\ | |      | | \\\\    /_\\   | |_  \\v| |" << endl
			<< "   \\ \\    | |   //_\\\\  | | // \\ \\      | | //   //_\\\\  | _/    | |" << endl
			<< "    \\ \\   | |  / ___ \\ | |< \\  \\ \\     | |< \\  / ___ \\ | |     | |" << endl
			<< " /\\__\\ \\  |/  /_/   \\_\\|_| \\_\\  \\ \\____|_| \\_\\/_/   \\_\\|_|     |/" << endl
			<< "/______/                         \\____/" << endl;

	cout << endl << "Starcraft II Simulator" << endl;
	cout << "Contributed by Brandon Danh, Roger Lam, Anna Ma" << endl << endl;

	cout << "Please select the race for Player 1" << endl;
	cout << "[Z]erg, [P]rotoss, or [T]erran" << endl;

	player1_race = getch();
	player1_race = tolower(player1_race);
	while(player1_race != 'z' && player1_race != 'p' && player1_race != 't') {
		cout << "Please enter a valid selection." << endl;
		player1_race = getch();
		player1_race = tolower(player1_race);
	}
	if (player1_race == 'z'){
		player1 = new Zerg();
	}
	else if (player1_race == 't')
	{
		player1 = new Terran();
	}
	else{
		player1 = new Protoss();
	//	cout << "Protoss" << endl;
	}

	cout << endl;
	cout << "Please select the race for Player 2" << endl;
	cout << "[Z]erg, [P]rotoss, or [T]erran" << endl;

	player2_race = getch();
	player2_race = tolower(player2_race);
		while(player2_race != 'z' && player2_race != 'p' && player2_race != 't') {
		cout << "Please enter a valid selection." << endl;
		player2_race = getch();
		player2_race = tolower(player2_race);
	}
	if (player2_race == 'z'){
		player2 = new Zerg();
	}
	else if (player2_race == 't')
	{
		player2 = new Terran();
	}
	else{
		player2 = new Protoss();
	//	cout << "Protoss" << endl;
	}
	//player2 = new Zerg(); 
	//while(player2_race != 'z' && player2_race != 'p' && player2_race != 'p') {
	//	cin >> player2_race;
	//	cout << "Please enter a valid selection." << endl;
	//}

	char select = '0';

	do {
		system("cls");
		
		// cout << "Ingame time: " << time << endl << endl;

		cout << "Main menu             Ingame time: " << time << " seconds" << endl << endl;
		cout << "Player [1] Commands" << endl;
		cout << "Player [2] Commands" << endl;
		cout << "Increment [T]ime" << endl;
		cout << "[A]ttack" << endl;
		cout << "[Q]uit" << endl;

		//cout << "Ingame time: " << time << endl << endl;

		select = getch();
		select = tolower(select);

		if (select == '1') {
			char control;
			do {
			
				system("cls");
				cout <<"Player 1 ";
				if (player1_race == 'z')
					cout << setw(10) << left << "(Zerg)";
				else if (player1_race == 't')
					cout << setw(10) << left << "(Terran)";
				else
					cout << setw(10) << left << "(Protoss)";
				cout << setw(18) << right << "Ingame time: " << time << " seconds" << endl << endl;

				cout << player1;
				cout << endl;
				cout << "[U]nits" << endl;
				cout << "[B]uildings" << endl;
				cout <<	"[M]ake Units" << endl;
				cout << "Bu[i]ld buildings" << endl;
				cout << "B[a]ck to menu" << endl;

				control = getch();
				control = tolower(control);

				//Units
				if(control == 'u')
			   {
				   system("cls");
				   units(player1);
				   cout << endl << endl << "Press any key to return to main menu...";
				   control = getch();
			   }

				//Buildings
			   if(control == 'b')
			   {
				   system("cls");
				   buildings(player1);
				   cout << endl << endl << "Press any key to return to main menu...";
				   control = getch();
			   }

			   //Make Units!
					if(control == 'm') {
					
					system("cls");
					cout <<"Player 1 ";
					if (player1_race == 'z')
						cout << setw(10) << left << "(Zerg)";
					else if (player1_race == 't')
						cout << setw(10) << left << "(Terran)";
					else
						cout << setw(10)<< left << "(Protoss)";
					cout << setw(10) << right << "Minerals: " << setw(8) << left << player1->get_mineral() << "Gas: " << player1->get_gas() << endl << endl;

					unitMakeKey(player1);
					cout << "Press 'g' to move a worker to gather gas" << endl << endl;
					cout << "Unit number would you like to make: ";
					//cin >> key;
					int keyInt;
					cin >> key;
					keyInt = static_cast<int>(key);
					keyInt = keyInt - 48;
					if (key == 103) {
						if(!player1->sendToGas()) {
							cout << "You can only have 3 workers per gas" << endl;
							cout << endl << "Press any key to continue...";
							control = getch();
						}
					}
					else if(keyInt <= 15){
						player1->make_unit(keyInt);
						//getch();
					}
					else
					{
						cout << "Invalid Command" << endl;
						cout << endl << "Press any key to return to main menu";
						control = getch();
					}
				}


				//Make Building
			if(control == 'i')
			   {
				   system("cls");
				   	cout <<"Player 1 ";
					if (player1_race == 'z')
						cout << setw(10) << left << "(Zerg)";
					else if (player1_race == 't')
						cout << setw(10) << left << "(Terran)";
					else
						cout << setw(10)<< left << "(Protoss)";
					cout << setw(10) << right << "Minerals: " << setw(8) << left << player1->get_mineral() << "Gas: " << player1->get_gas() << endl << endl;
				   build_buildings(player1);
				   cout << "Building number would you like to make: ";
				   int unit;
				   char unitchar;
				   cin >> unitchar;
					unit = static_cast<int>(unitchar);
					unit = unit - 48;
				   if(!player1->make_building(unit))
				   {
					   cout << endl << "Press any key to return to main menu";
						 getch();
				   }
			   }
			} while (control != 'a') ;
		} else if (select == '2') {
			char control;
			do {
				system("cls");
				cout <<"Player 2 ";
				if (player2_race == 'z')
					cout << "(Zerg)";
				else if (player2_race == 't')
					cout << "(Terran)";
				else
					cout << "(Protoss)";
				cout << setw(18) << right << "Ingame time: " << time << " seconds" << endl << endl;

				cout << player2;
				cout << endl;
				cout << "[U]nits" << endl;
				cout << "[B]uildings" << endl;
				cout <<	"[M]ake Units" << endl;
				cout << "Bu[i]ld buildings" << endl;
				cout << "B[a]ck" << endl;

				control = getch();

				//Units
				if(control == 'u')
			   {
				   system("cls");
				   units(player2);
				   cout << endl << endl << "Press any key to return to main menu...";
				   control = getch();
			   }

				//Buildings
			   if(control == 'b')
			   {
				   system("cls");
				   buildings(player2);
				   cout << endl << endl << "Press any key to return to main menu...";
				   control = getch();
			   }
			   //Make units.
				if(control == 'm') {
					system("cls");
					cout <<"Player 2 ";
					if (player2_race == 'z')
						cout << setw(10) << left << "(Zerg)";
					else if (player2_race == 't')
						cout << setw(10) << left << "(Terran)";
					else
						cout << setw(10)<< left << "(Protoss)";
					cout << setw(10) << right << "Minerals: " << setw(8) << left << player2->get_mineral() << "Gas: " << player2->get_gas() << endl << endl;

					unitMakeKey(player2);
					cout << "Press 'g' to move a worker to gather gas" << endl << endl;
					cout << "Unit number would you like to make: ";
					//cin >> key;
					int keyInt;
					cin >> key;
					keyInt = static_cast<int>(key);
					keyInt = keyInt - 48;
					if (key == 'g') {
						if(!player2->sendToGas()) {
							cout << "You can only have 3 workers per gas" << endl;
							cout << endl << "Press any key to continue...";
							control = getch();
						}
					}
					else if(keyInt <= 15){
						player2->make_unit(keyInt);
						//control = getch();
					}
					else
					{
						cout << "Invalid Command" << endl;
						cout << endl << "Press any key to return to main menu";
						key = getch();
					}
				}

				//Make Building
					if(control == 'i')
			   {
				   system("cls");
				   	cout <<"Player 2 ";
					if (player1_race == 'z')
						cout << setw(10) << left << "(Zerg)";
					else if (player1_race == 't')
						cout << setw(10) << left << "(Terran)";
					else
						cout << setw(10)<< left << "(Protoss)";
					cout << setw(10) << right << "Minerals: " << setw(8) << left << player2->get_mineral() << "Gas: " << player2->get_gas() << endl << endl;
				   
					build_buildings(player2);
				   cout << "Building number would you like to make: ";
				   int unit;
				   char unitchar;
				   cin >> unitchar;
					unit = static_cast<int>(unitchar);
					unit = unit - 48;
				   if(!player2->make_building(unit))
					   cout << endl << "Press any key to return to main menu";
				   getch();
			   }
			} while (control != 'a');
		} else if (select == 't') {
			player1->change_minerals(player1->minerals_per_min() / 60);
			player1->change_gas(player1->gas_per_min() /60);
			player2->change_minerals(player2->minerals_per_min() /60);
			player2->change_gas(player2->gas_per_min() /60);

			if(player1_race == 'z' && time % 15 == 0 && player1->larva < 3) {
				for(int i = 0; i < (player1->howmanybuildings(0) + player1->howmanybuildings(1) + player1->howmanybuildings(2)); i++)
					player1->addLarva();
			}
			if(player2_race == 'z' && time % 15 == 0 && player2->larva < 3) {
				player2->addLarva();
			}

			time++;
		} else if(select == 'a') {
			system("cls");
			cout << "Player 1:" << endl
				<< "Total Health: " << player1->army_health() << endl
				<< "Total DPS:    " << player1->army_attack() << endl << endl;
			
			cout << "Player 2:" << endl
				<< "Total Health: " << player2->army_health() << endl
				<< "Total DPS:    " << player2->army_attack() << endl << endl;

			if(double(player1->army_health())/player2->army_attack() > double(player2->army_health())/player1->army_attack()) {
				cout << "Player 1 Wins!" << endl;
			} else if (double(player1->army_health())/player2->army_attack() < double(player2->army_health())/player1->army_attack()) {
				cout << "Player 2 Wins!" << endl;
			} else {
				cout << "Tie." << endl;
			}
			select = 'q';
		}

	} while(select != 'q');


	return 1;
}
