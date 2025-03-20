#include <iostream>
#include <string>

#include "../include/ruleSet.h"
#include "../include/sudoku.h"
#include "../include/sudokuRules.h"

int main() {

    std::string buff;
    short subGridSize = 3;
    std::cout << ">>> ";
    std::cin >> subGridSize;

    std::cout << "subGridSize: " << subGridSize << std::endl;

    if (subGridSize > 11)  {
        std::cout << "subGrid size of: " << subGridSize << " is too large! Causes an overflow in (char) Sudoku::mGridSize\n";
        std::cout << "Using a default size of 9x9 sudoku.\n";
        subGridSize = 3;
    } else if (subGridSize <= 0) {
        std::cout << "subGridSize of: " << subGridSize << " does not make sense.\nUsing a default size of 9x9 sudoku\n";
        subGridSize = 3;
    }   

    // Init sudoku
    short numRules = 3;
    SudokuRules* classic = new ClassicSudoku();
    SudokuRules* forwarddiagonal = new ForwardDiagonal();
    SudokuRules* backwardDiagonal = new BackwardDiagonal();
    SudokuRules* rules[] = {classic, forwarddiagonal, backwardDiagonal};
    RuleSet* ruleSet = new RuleSet(rules, numRules);
    Sudoku* sudoku = new Sudoku(subGridSize, ruleSet);

    // Display board (all 0s)
    // sudoku->displayBoard();

    // sudoku->setValue(40, 1);

    // Fill each row from 1 to subGridSize^2
    for (int i = 0; i < sudoku->getGridArea(); i++){
        for (int val = 1; val <= sudoku->getGridSize(); val++){
            // char val = (i % sudoku->getGridSize()) + 1;
            // std::cout << "Val to place: " << int(val) << " at index: " << i << "\n";
            if (!sudoku->isValid(val, i)) { continue; }
            // if (!forwarddiagonal->isValid(val, i, sudoku->getBoard(), sudoku->getGridSize())) { continue; }
            // if (!backwardDiagonal->isValid(val, i, sudoku->getBoard(), sudoku->getGridSize())) { continue; };
            // std::cout << "Inside the if statement.\n";
            sudoku->setValue(i, val);
            break;
        }
    }

    // Display board again
    sudoku->displayBoard();

    std::cout << "\n" << sudoku->getGridArea() << "\n";
    std::cout << "GridSize: " << int(sudoku->getGridSize());
    // Check mBoard is being deleted
    delete sudoku;
    std::cout << "\n";
    // delete forwarddiagonal;
    // delete backwardDiagonal;

    return 0;
}