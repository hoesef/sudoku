#include "../include/sudoku.h"
#include <iostream>

Sudoku::Sudoku(short subGridSize) {
    // Invalid subgrid size given
    if (subGridSize <= 0) { return; }

    // Initialize member attributes
    mSubGridSize = subGridSize;
    mGridSize = subGridSize * subGridSize;
    mGridArea = mGridSize * mGridSize;

    // Delete any board already made
    if (mBoard) { delete [] mBoard; }
    // Initialize board and set all elements to 0
    mBoard = new char[mGridArea]{0};
}
bool Sudoku::setValue(const short& row, const short& col, const char& value) {
    int index = (row * mGridArea) + col; // Calculate index
    if (index < 0 || index >= mGridArea) { return false; } // Index out of bounds
    mBoard[(row * mGridSize) + col] = value; // Set vlaue
    return true;
};
bool Sudoku::setValue(const int& index, const char& value) {
    if (index < 0 || index >= mGridArea) { return false; } // Index out of bounds
    mBoard[index] = value; // Set valaue
    return true;
};
char Sudoku::getValue(const short& row, const short& col) const {
    return mBoard[(row * mGridSize) + col]; // NOT CHECKING BOUNDS
}
char Sudoku::getValue(const int& index) const {
    return mBoard[index]; // NOT CHECKING BOUNDS
}

ClassicSudoku::ClassicSudoku(short subGridSize): Sudoku(subGridSize){}
bool ClassicSudoku::loadFromFile(const char* fileName) {
    // TODO: fill out function
    return false;
};
void ClassicSudoku::displayBoard() const {
    short size = getGridSize();
    short subGrid = getSubGridSize();
    std::cout << "\n -------------------------" << std::endl;
    for (short row = 0; row < size; row++) {
        if (row % subGrid == 0 && row > 0) { std:: cout << " | --------------------- |\n"; }
        for (short col = 0; col < size; col++) {
            if (col % subGrid == 0) {std::cout << " |" << std::flush;}
            // Ensures that spacing is consistent
            int val = int(getValue(row, col));
            if (size > 9 && val <= 9) {
                std::cout <<  " 0" << int(getValue(row, col)) << std::flush;
            } else {
            std::cout <<  " " << int(getValue(row, col)) << std::flush;
            }
        }
        std::cout << " |" << std::endl;
    }
    std::cout << " -------------------------" << std::endl;
};
bool ClassicSudoku::isValid() {
    // Check entire board to ensure it is valid
    int area = getGridArea();
    for (int i = 0; i < area; i ++) {
        if (!isValid(i)) { return false; }
    }
    return true;
};
bool ClassicSudoku::isValid(const short& row, const short& col) {
    // TODO: code up function
    // Check if a specific cell is valid
    return false;
};
bool ClassicSudoku::isValid(const int& index) {
    // TODO: code up function
    // Check if a specific cell is valid
    return false;
};
bool ClassicSudoku::generate() {
    // TODO: code generation function
    // Creates a valid random sudoku
    return false;
}