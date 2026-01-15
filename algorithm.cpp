#include <iostream>
#include "solver.hpp"

using namespace std;

int main() {
	cout << "Hello World!" << endl;
	ToH game = ToH(3);
	Solver solver = Solver(game);
	solver.solve();
	game.printState();
	// vector<int> a = {1, 2, 3, 4, 5};
	// cout << (a.at(0) > a.at(1)) << endl;
	return 0;
}
