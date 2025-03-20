#include "../include/sudoku.h"
#include <iostream>

Sudoku::Sudoku(short subGridSize, RuleSet& puzzleRules) {
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
    // Deep copy of the rules
    mRules = new RuleSet(puzzleRules);
};
bool Sudoku::setValue(const char& row, const char& col, const char& value) {
    int index = (row * mGridSize) + col; // Calculate board index
    if (index < 0 || index >= mGridArea) { return false; } // Index out of bounds
    mBoard[index] = value; // Set vlaue
    return true;
};
bool Sudoku::setValue(const short& index, const char& value) {
    if (index < 0 || index >= mGridArea) { return false; } // Index out of bounds
    mBoard[index] = value; // Set valaue
    return true;
};
char Sudoku::getValue(const char& row, const char& col) const {
    return mBoard[(row * mGridSize) + col]; // NOT CHECKING BOUNDS
};
char Sudoku::getValue(const short& index) const {
    return mBoard[index]; // NOT CHECKING BOUNDS
};
void Sudoku::displayBoard() const {
    std::cout << "\n -------------------------" << std::endl;
    for (char row = 0; row < mGridSize; row++) {
        if (row % mSubGridSize == 0 && row > 0) { std:: cout << " | --------------------- |\n"; }
        for (char col = 0; col < mGridSize; col++) {
            if (col % mSubGridSize == 0) {std::cout << " |" << std::flush;}
            // Ensures that spacing is consistent
            short val = short(getValue(row, col));
            if (mGridSize > 9 && val <= 9) {
                if (val == 0) {
                    std::cout <<  "  " << "." << std::flush;
                } else{
                    std::cout <<  "  " << val << std::flush;
                }
            } else {
            std::cout <<  " " << val << std::flush;
            }
        }
        std::cout << " |" << std::endl;
    }
    std::cout << " -------------------------" << std::endl;
};
bool Sudoku::isValid() {
    // Check entire board to ensure it is valid
    char* tmpBoard = new char[mGridArea]{0};
    bool valid = true;
    for (short i = 0; i < mGridArea; i++) {
        char value = mBoard[i];
        if (value > 0) {
            if (valid &= mRules->applyRules(value, i, tmpBoard, mGridSize); !valid) { std::cout << "Invalid index: " << i << "\n"; break;}
            tmpBoard[i] = value;
        }
    }
    delete [] tmpBoard;
    return valid;
};
bool Sudoku::isValid(const char value, const char& row, const char& col) {
    // Check if a specific cell is valid
    char gridSize = mGridSize;
    short index = (row * gridSize) + col;
    return mRules->applyRules(value, index, mBoard, mGridSize);
};
bool Sudoku::isValid(const char value, const short& index) {
    // Check if a specific cell is valid
    return mRules->applyRules(value, index, mBoard, mGridSize);
};
Sudoku::~Sudoku() {
    delete [] mBoard;
    std::cout << "Deleted mBoard\n";
    delete mRules;
    std::cout << "Deleted mRules";
}