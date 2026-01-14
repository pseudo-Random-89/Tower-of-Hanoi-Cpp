#include <iostream>
#include "solver.hpp"

using namespace std;

int main() {
	cout << "Hello World!" << endl;
	ToH game = ToH(3);
	Solver solver = Solver(game);
	solver.solve();
	game.printState();
	return 0;
}
