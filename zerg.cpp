#include "zerg.h"

Zerg::Zerg() {
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
