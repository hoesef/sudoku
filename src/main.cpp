#include <iostream>

#include "../include/sudoku.h"

int main() {

    // Init sudoku
    short subGridSize = 4;
    Sudoku* sudoku = new Sudoku{subGridSize};

    // Display board (all 0s)
    sudoku->displayBoard();

    // Fill each row from 1 to subGridSize^2
    bool success = true;
    for (int i = 0; i < sudoku->getGridArea(); i++){
        success = success & sudoku->setValue(i, (i%sudoku->getGridSize())+1);
    }

    // Display board again
    sudoku->displayBoard();

    // Check mBoard is being deleted
    delete sudoku;

    return 0;
}