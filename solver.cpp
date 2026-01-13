#include <iostream>
#include "solver.hpp"
#include "toh.hpp"

using namespace std;

Solver::Solver(const ToH &newGame) : game(newGame) {
    counter = 0;
    // depth = 0;
}

void Solver::solve() {
    // Never move an odd numbered ring onto another odd numbered ring & vice versa

    // moveStack(game.countDiscs(), 0, 2);

    while (!game.isSolved()) {


        counter++;
    }
    cout << "Finished in " << counter << " steps." << endl;
}

void Solver::moveStack(int largestRing, int fromidx, int toidx) {
    if (largestRing != 0) {
        moveStack(largestRing-1, fromidx, toidx);
    }
}
