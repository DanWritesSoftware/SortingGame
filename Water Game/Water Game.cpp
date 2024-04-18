#include <iostream>
#include <array>
#include <map>
#include "glass.h"
#include "display.h"
#include "validation.h"
#include "access.h"

int main()
{
    /*
    Glass g1({ 4,4,3,2,2 });
    Glass g2({ 0,0,4,5,5 });
    Glass g3({ 0,0,0,5,5 });
    Glass g4({ 0,0,0,0,0 });

    std::map<int, Glass> inputMap = {
        {1,g1},
        {2,g2},
        {3,g3},
        {4,g4},
    };
    */

    Access a;
    std::map<int, Glass> gameState = a.readLevel();
    Display d(gameState);
    Validation v;
 
    std::string from, to;
    int moves = 0;
    bool run = true;
    while (run = true) {
        d.updateOut();
        std::cout << "Pour from which bottle?: ";
        std::cin >> from;
        std::cout << "Pour to which bottle?: ";
        std::cin >> to;
        if (v.validateSingleIntInput(from) && v.validateSingleIntInput(to)) {
            gameState[stoi(to)].add(gameState[stoi(from)]);
            d.updateData(gameState);
            moves++;
            if (gameState[1].isComplete() && gameState[2].isComplete() && gameState[3].isComplete() && gameState[4].isComplete()) { // TODO: Update to dynamic num of objects
                std::cout << "\n\n All Bottles Completed, You Won in " << moves << " moves! \n\n";
                break;
            }
        }
        else {
            d.displayInputError();
            continue;
        }
    }
}