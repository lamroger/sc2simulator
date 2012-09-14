#include "race.h"
#include <conio.h>

int Race::gas_per_min() {
	return 0;
}

int Race::minerals_per_min(){
	return 0;
}

ostream& Race::operator<< (ostream& out)
{
	return out;
}

void Race::print() {
	return ;
}
void Race::make_unit(int index){
	return ;
}
void Race::change_minerals(int i){
	return ;
}
void Race::change_gas(int i){
	return ;
}
int Race::get_army(){
	return 0;
}

int Race::howmanyunits(int)
{
	return 0;
}

int Race::howmanybuildings(int)
{
	return 0;
}

bool Race::make_building(int index)
{
	return true;
}

bool Race::unitCheckReq(int i)
{
	return true;
}

bool Race::sendToGas() {
	return false;
}

void Race::addLarva() {
	return;
}

int Race::getLarva() {
	return 0;
}

int Race::get_mineral() const {
	return 0;
}

int Race::get_gas() const {
	return 0;
}

int Race::army_health()
{
	return 0;
}

int Race::army_attack()
{
	return 0;
}