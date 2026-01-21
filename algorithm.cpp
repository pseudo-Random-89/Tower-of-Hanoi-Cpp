#include <iostream>
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

		int rings;
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

		while (true) {
			cout << "Go fast? (y/n)" << endl;
			cin >> input;

			if (tolower(input.at(0)) != 'y' && tolower(input.at(0)) != 'n') {
				cout << "Not a valid input, try again." << endl;
				continue;
			}

			break;
		}


		cout << endl;
		ToH game = ToH(rings);
		Solver solver = Solver(game);
		solver.solve(tolower(input.at(0)) == 'n');
	}
	return 0;
}
