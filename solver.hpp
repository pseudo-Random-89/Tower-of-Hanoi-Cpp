#pragma once
#include <vector>
#include "toh.hpp"

using namespace std;

class Solver {
	private:
		ToH game;
		int counter;
		// int depth;
	public:
		explicit Solver(const ToH &newGame);
		void solve();
		void moveStack(int ring, int fromidx, int toidx);

};
