#pragma once
#include <vector>
#include "toh.hpp"

using namespace std;

class Solver {
	private:
		ToH game;
		void moveStack(int ring, int fromidx, int toidx);
	public:
		explicit Solver(const ToH &newGame);
		void solve();

};
