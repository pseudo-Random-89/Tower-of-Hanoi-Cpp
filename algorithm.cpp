#include <charconv>
#include <iostream>
#include <bits/parse_numbers.h>

#include "solver.hpp"

using namespace std;

int main() {
	while (true) {
		string input;
		cout << "How many rings? (x to exit)" << endl;

		cin >> input;
		if (input.empty()) {
			cout << "Not a valid input, try again." << endl;
			continue;
		}
		if (tolower(input.at(0)) == 'x') break;

		int rings = 3;
		try {
			rings = stoi(input);

			if (rings <= 0) {
				cout << "Not a valid input, try again." << endl;
				continue;
			}
		} catch (...) {
			cout << "Not a valid input, try again." << endl;
			continue;
		}
		ToH game = ToH(rings);
		game.printState();
		Solver solver = Solver(game);
		solver.solve();
	}
	return 0;
}
