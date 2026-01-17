#include <iostream>
#include "solver.hpp"

using namespace std;

int main() {
	cout << "Hello World!" << endl;
	ToH game = ToH(16);
	game.printState();
	Solver solver = Solver(game);
	solver.solve();
	return 0;
}
