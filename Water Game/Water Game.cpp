#include <iostream>
#include <array>
#include <map>
#include "glass.h"
#include "display.h"
#include "validation.h"
#include "access.h"

int main()
{
    Access a;
    std::map<int, Glass> gameState = a.readLevel();
    Display d(gameState);
    Validation v;

    std::string from, to;
    int moves = 0;
    bool run = true;
    while (run == true) {
        while (run == true) {

            int completeBottles = 0; // resets each cycle
            d.updateOut();
            std::cout << "Pour from which bottle?: ";
            std::cin >> from;
            std::cout << "Pour to which bottle?: ";
            std::cin >> to;
            if (v.validateSingleIntInput(from) && v.validateSingleIntInput(to)) {
                gameState[stoi(to)].add(gameState[stoi(from)]);
                d.updateData(gameState);
                moves++;
                // check for win condition:
                for (const auto& pair : gameState) {
                    Glass g = pair.second;
                    if (g.isComplete()) {
                        completeBottles++;
                    }
                }
                if (completeBottles == gameState.size()) {
                    std::cout << "\n\n All Bottles Completed, You Won in " << moves << " moves! \n\n";
                    break;
                }
            }
            else {
                d.displayInputError();
                continue;
            }
        }
        gameState = a.readLevel(); // advance to next level
    }

    return 0;
}