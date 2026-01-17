#include <iostream>
#include <utility>
#include <cmath>
#include "solver.hpp"
#include "toh.hpp"

using namespace std;

Solver::Solver(ToH newGame) : game(std::move(newGame)) {}

void Solver::solve() {
    game.move(0,game.countDiscs() % 2 + 1);
    game.printState();

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

        int scores[3] = { 0, 0, 0 };

        if (rodToMove == 0) {
            scores[0] = -1000;
            scores[1]++;
            scores[2]++;

            scores[1] += (ring2 != 0) * -((ringToMove % 2 == ring2 % 2) * 10 - 5);
            scores[2] += (ring3 != 0) * -((ringToMove % 2 == ring3 % 2) * 10 - 5);

            scores[1] -= 10 * (ringToMove > ring2 && ring2 != 0);
            scores[2] -= 10 * (ringToMove > ring3 && ring3 != 0);
        } else if (rodToMove == 1) {
            scores[1] = -1000;
            scores[0]++;
            scores[2]++;

            scores[0] += (ring1 != 0) * -((ringToMove % 2 == ring1 % 2) * 10 - 5);
            scores[2] += (ring3 != 0) * -((ringToMove % 2 == ring3 % 2) * 10 - 5);

            scores[0] -= 10 * (ringToMove > ring1 && ring1 != 0);
            scores[2] -= 10 * (ringToMove > ring3 && ring3 != 0);
        } else {
            scores[2] = -1000;
            scores[0]++;
            scores[1]++;

            scores[0] += (ring1 != 0) * -((ringToMove % 2 == ring1 % 2) * 10 - 5);
            scores[1] += (ring2 != 0) * -((ringToMove % 2 == ring2 % 2) * 10 - 5);

            scores[0] -= 10 * (ringToMove > ring1 && ring1 != 0);
            scores[1] -= 10 * (ringToMove > ring2 && ring2 != 0);
        }

        int destinationRodProp[3] = {0, 1, 2};

        if (scores[0] > scores[1]) {
            int holdScore = scores[0];
            destinationRodProp[0] = 1;
            destinationRodProp[1] = 0;
            scores[0] = scores[1];
            scores[1] = holdScore;
        }
        if (scores[1] > scores[2]) {
            int holdRod = destinationRodProp[1];
            int holdScore = scores[1];
            destinationRodProp[1] = destinationRodProp[2];
            destinationRodProp[2] = holdRod;
            scores[1] = scores[2];
            scores[2] = holdScore;
        }
        if (scores[0] > scores[1]) {
            int holdRod = destinationRodProp[0];
            int holdScore = scores[0];
            destinationRodProp[0] = destinationRodProp[1];
            destinationRodProp[1] = holdRod;
            scores[0] = scores[1];
            scores[1] = holdScore;
        }

        game.move(rodToMove, destinationRodProp[2]);

        game.printState();
        counter++;
        lastMoved = ringToMove;
    }

    cout << "Finished in " << counter << " steps." << endl;

    if (pow(2, game.countDiscs()) - 1 == counter) {
        cout << "This is optimal." << endl;
    } else {
        cout << "This is not optimal." << endl;
    }
}
