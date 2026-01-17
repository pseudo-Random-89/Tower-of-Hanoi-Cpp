#include <iostream>
#include <string>
#include <vector>
#include "toh.hpp"

using namespace std;

ToH::ToH(int rings) {
    rods = {{}, {}, {}};
    numDiscs = rings;

    rods.at(0).resize(rings);

    for (int i=0; i < rings; i++) {
        rods.at(0).at(i) = i + 1;
    }
}

void ToH::move(int fromidx, int toidx) {
    rods.at(toidx).resize(rods.at(toidx).size() + 1);

    if (rods.at(toidx).size() > 1) {
        for (int i=rods.at(toidx).size()-1; i>0; i--) {
            rods.at(toidx).at(i) = rods.at(toidx).at(i-1);
        }
    } else {
        rods.at(toidx).at(0) = rods.at(fromidx).at(0);
    }

    rods.at(toidx).at(0) = rods.at(fromidx).at(0);


    for (int i=0; i < rods.at(fromidx).size() - 1; i++) {
        rods.at(fromidx).at(i) = rods.at(fromidx).at(i + 1);
    }

    rods.at(fromidx).resize(rods.at(fromidx).size() - 1);
}

vector<vector<int>> ToH::getState() {
    return rods;
}

void ToH::printState() const {
    string toReturn;

    for (const vector<int>& rod : rods) {
        for (const int j : rod) {
            toReturn += to_string(j) + " ";
        }
        toReturn += "\n";
    }
    cout << toReturn << endl;
}

int ToH::countDiscs() const {
    return numDiscs;
}

bool ToH::isSolved() const {
    return rods.at(0).empty() && rods.at(1).empty() && rods.at(2).size() == numDiscs;
}
