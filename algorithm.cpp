#include <iostream>
#include "solver.hpp"

using namespace std;

int main() {
	cout << "Hello World!" << endl;
	ToH game = ToH(9);
	Solver solver = Solver(game);
	game.printState();
	return 0;
}
