#include <iostream>
#include <utility>
#include "solver.hpp"
#include "toh.hpp"

using namespace std;

Solver::Solver(ToH newGame) : game(std::move(newGame)) {}

void Solver::solve() {
    // Never move an odd numbered ring onto another odd numbered ring & vice versa

    // moveStack(game.countDiscs(), 0, 2);

    game.move(0,1);

    int counter = 1;
    int lastMoved = 1;

    while (!game.isSolved()) {
        vector<vector<int>> rods = game.getState();
        int ring1 = 0;
        int ring2 = 0;
        int ring3 = 0;

        if (!rods.at(0).empty()) ring1 = rods.at(0).at(0);
        if (!rods.at(1).empty()) ring2 = rods.at(1).at(0);
        if (!rods.at(2).empty()) ring3 = rods.at(2).at(0);

        vector<int> rings = {ring1, ring2, ring3};
        vector<int> rodidx = {0, 1, 2};

        if (rings.at(0) > rings.at(1)) {
            int hold = rings.at(0);
            rings.at(0) = rings.at(1);
            rings.at(1) = hold;
            rodidx.at(1) = 0;
            rodidx.at(0) = 1;
        }
        if (rings.at(1) > rings.at(2)) {
            int hold = rings.at(1);
            int holdRod = rodidx.at(1);
            rings.at(1) = rings.at(2);
            rings.at(2) = hold;
            rodidx.at(1) = rodidx.at(2);
            rodidx.at(2) = holdRod;
        }
        if (rings.at(0) > rings.at(1)) {
            int hold = rings.at(0);
            int holdRod = rodidx.at(0);
            rings.at(0) = rings.at(1);
            rings.at(1) = hold;
            rodidx.at(0) = rodidx.at(1);
            rodidx.at(1) = holdRod;
        }

        int ringToMove = rings.at(0);
        int idx = 0;

        while (ringToMove == 0 || ringToMove == lastMoved) {
            idx++;
            ringToMove = rings.at(idx);
        }

        int rodToMove = rodidx.at(idx);

        int destinationRod = 0;
        int destinationRing = 0;

        if (!rods.at(destinationRod).empty()) destinationRing = rods.at(destinationRod).at(0);

        while (destinationRod == rodToMove || (destinationRing != 0 && (destinationRing < ringToMove || ringToMove % 2 == destinationRing % 2))) {
            destinationRod++;
            destinationRing = 0;
            if (!rods.at(destinationRod).empty()) destinationRing = rods.at(destinationRod).at(0);
        }

        // TODO: INSTEAD OF DOING A LOOP, TEST THE VIABILITY OF ALL 3 RINGS, AND RANK THEM
        int score1 = 0;
        int score2 = 0;
        int score3 = 0;

        if (rodToMove == 0) {

        } else if (rodToMove == 1) {

        } else {

        }

        game.move(rodToMove, destinationRod);

        game.printState();
        counter++;
        lastMoved = ringToMove;
    }
    cout << "Finished in " << counter << " steps." << endl;
}

void Solver::moveStack(int largestRing, int fromidx, int toidx) {
    if (largestRing != 0) {
        moveStack(largestRing-1, fromidx, toidx);
    }
}
