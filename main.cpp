#include "zerg.h"
#include <iostream>

using namespace std;

int main() {
  Zerg player1;
  player1.print();
  cout << "\n";
  player1.make_unit(0);
  player1.print();

  return 1;
}
