#pragma once
#include <vector>
#include "toh.hpp"

using namespace std;

class Solver {
	private:
		ToH game;
	public:
		explicit Solver(ToH newGame);
		void solve();

};
