#include <iostream>
#include <array>
#include <map>
#include "glass.h"
#include "display.h"
#include "validation.h"

int main()
{
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
    
    Display d(g1, g2, g3, g4);
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
            inputMap[stoi(to)].add(inputMap[stoi(from)]);
            d.updateData(inputMap[1], inputMap[2], inputMap[3], inputMap[4]);
            moves++;
            if (inputMap[1].isComplete() && inputMap[2].isComplete() && inputMap[3].isComplete() && inputMap[4].isComplete()) {
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