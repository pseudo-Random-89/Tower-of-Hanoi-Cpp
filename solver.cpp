#include <iostream>
#include "solver.hpp"
#include "toh.hpp"

using namespace std;

Solver::Solver(const ToH &newGame) : game(newGame) {}

void Solver::solve() {
    // Never move an odd numbered ring onto another odd numbered ring & vice versa

    // moveStack(game.countDiscs(), 0, 2);

    game.move(0,game.countDiscs() % 2 + 1);

    int counter = 1;
    int lastMoved = 1;

    while (!game.isSolved()) {
        vector<vector<int>> rods = game.getState();
        int rod1 = rods.at(0).at(0);
        int rod2 = rods.at(1).at(0);
        int rod3 = rods.at(2).at(0);

        // if (rod1 != lastMoved && rod1 < rod2 && rod1 < rod3) {
        //     if (rod1 % 2 == rod2 % 2) {
        //         game.move(rod1, rod2);
        //     } else if (rod1 % 2 == rod3 % 2) {
        //         game.move(rod1, rod3);
        //     }
        // } else if (rod2 != lastMoved && rod2 < rod1 && rod2 < rod3) {
        //     if (rod2 % 2 == rod1 % 2) {
        //         game.move(rod2, rod1);
        //     } else if (rod2 % 2 == rod3 % 2) {
        //         game.move(rod2, rod3);
        //     }
        // } else if (rod3 != lastMoved && rod3 < rod1 && rod3 < rod2) {
        //     if (rod3 % 2 == rod1 % 2) {
        //         game.move(rod3, rod1);
        //     } else if (rod3 % 2 == rod2 % 2) {
        //         game.move(rod3, rod2);
        //     }
        // } else return;

        // TODO: ALL OF THIS WILL ONLY WORK IF THE SMALLEST ROD WAS NOT MOVED (PHYSICALLY IMPOSSIBLE FOR EVEN A SINGLE ITERATION)

        game.printState();
        counter++;
    }
    cout << "Finished in " << counter << " steps." << endl;
}

void Solver::moveStack(int largestRing, int fromidx, int toidx) {
    if (largestRing != 0) {
        moveStack(largestRing-1, fromidx, toidx);
    }
}
