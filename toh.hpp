#pragma once
#include <vector>

using namespace std;

class ToH {
    private:
        int numDiscs;
		vector<vector<int>> rods;
		string buildRing(int ring) const;
	public:
        explicit ToH(int rings);
		void move(int fromidx, int toidx);
		vector<vector<int>> getState();
		void printState() const;
		int countDiscs() const;
		bool isSolved() const;
};
