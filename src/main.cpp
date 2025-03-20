// Standard imports
#include <iostream>
#include <string>

// Relative imports
#include "../include/ruleSet.h"
#include "../include/sudoku.h"
#include "../include/sudokuRules.h"

template <typename T> void userInput(T& buff) {
    std::cout << ">>> ";
    std::cin >> buff;
}
int main() {

    // User input gridSize
    short subGridSize = 3;
    userInput<short>(subGridSize);

    // Check for valid subGridSize
    if (subGridSize > 11)  {
        std::cout << "subGrid size of: " << subGridSize << " is too large! Causes an overflow in (char) Sudoku::mGridSize\n";
        std::cout << "Using a default size of 9x9 sudoku.\n";
        subGridSize = 3;
    } else if (subGridSize <= 0) {
        std::cout << "subGridSize of: " << subGridSize << " does not make sense.\nUsing a default size of 9x9 sudoku\n";
        subGridSize = 3;
    }   

    // Init sudoku
    Sudoku* sudoku;
    {
        short numRules = 3;
        ClassicSudoku classic;
        ForwardDiagonal forwardDiagonal;
        BackwardDiagonal backwardDiagonal;
        SudokuRules* rules[] = {&classic, &forwardDiagonal, &backwardDiagonal};
        RuleSet ruleSet{rules, numRules};
        sudoku = new Sudoku(subGridSize, ruleSet);
    }

    std::cout << "\nMade sudoku\n\n";
    std::cin >> subGridSize;

    // Fill each row from 1 to subGridSize^2 (if placement would be valid)
    for (int i = 0; i < sudoku->getGridArea(); i++){
        for (int val = 1; val <= sudoku->getGridSize(); val++){
            if (!sudoku->isValid(val, i)) { continue; }
            sudoku->setValue(i, val);
            break;
        }
    }

    if (!sudoku->isValid()) {
        std::cout << "Board is invalid";
        return 0;
    }

    // Display board again
    sudoku->displayBoard();

    // Check mBoard is being deleted
    delete sudoku;

    return 0;
}