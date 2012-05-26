#include "zerg.h"
#include <iostream>

using namespace std;

int main() {
  Zerg player1;
  cout << "Player 1 Minerals per Minute: " << player1.minerals_per_min()  << "\n";
  cout << "Player 1 Gas per Minute: " << player1.gas_per_min()  << "\n";
  return 1;
}
