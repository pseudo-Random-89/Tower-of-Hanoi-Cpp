#include "toh.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

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
    string toPrint;

    vector<int> rod1 = rods.at(0);
    vector<int> rod2 = rods.at(1);
    vector<int> rod3 = rods.at(2);

    reverse(rod1.begin(), rod1.end());
    reverse(rod2.begin(), rod2.end());
    reverse(rod3.begin(), rod3.end());

    for (int i=0; i < numDiscs ; i++) {
        if (numDiscs - 1 - i < rod1.size()) toPrint += buildRing(rod1.at(numDiscs - 1 - i));
        else toPrint += buildRing(0);

        if (numDiscs - 1 - i < rod2.size()) toPrint += buildRing(rod2.at(numDiscs - 1 - i));
        else toPrint += buildRing(0);

        if (numDiscs - 1 - i < rod3.size()) toPrint += buildRing(rod3.at(numDiscs - 1 - i));
        else toPrint += buildRing(0);

        toPrint += "\n";
    }

    cout << toPrint << endl;
}

string ToH::buildRing(int ring) const {
    string toReturn;

    while (ring--) toReturn += "||";
    if (toReturn.empty()) toReturn = "-";
    else toReturn += "|";
    while (toReturn.size() < numDiscs * 2) toReturn = " " + toReturn + " ";
    toReturn += " ";

    return toReturn;
}

int ToH::countDiscs() const {
    return numDiscs;
}

bool ToH::isSolved() const {
    return rods.at(0).empty() && rods.at(1).empty() && rods.at(2).size() == numDiscs;
}
