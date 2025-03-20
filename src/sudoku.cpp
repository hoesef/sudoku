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

    // 
    std::cout << "Doing the do...\n";

    mRules = new RuleSet(puzzleRules);
    std::cout << "Do done...\n";
};
bool Sudoku::setValue(const char& row, const char& col, const char& value) {
    int index = (row * mGridArea) + col; // Calculate index
    if (index < 0 || index >= mGridArea) { return false; } // Index out of bounds
    mBoard[(row * mGridSize) + col] = value; // Set vlaue
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
    char size = getGridSize();
    char subGrid = getSubGridSize();
    std::cout << "\n -------------------------" << std::endl;
    for (char row = 0; row < size; row++) {
        if (row % subGrid == 0 && row > 0) { std:: cout << " | --------------------- |\n"; }
        for (char col = 0; col < size; col++) {
            if (col % subGrid == 0) {std::cout << " |" << std::flush;}
            // Ensures that spacing is consistent
            short val = short(getValue(row, col));
            if (size > 9 && val <= 9) {
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
    // short area = getGridArea();
    // for (short i = 0; i < area; i++) {
    //     if (!isValid(i)) { return false; }
    // }
    return true;
};
bool Sudoku::isValid(const char value, const char& row, const char& col) {
    // TODO: code up function
    // Check if a specific cell is valid
    // mRules->isValid((const char)row, (const char)row, (const char)col, (const char*)mBoard, (const char)mGridSize);
    char gridSize = mGridSize;
    short index = (row * gridSize) + col;
    return mRules->applyRules(value, index, mBoard, mGridSize);
};
bool Sudoku::isValid(const char value, const short& index) {
    // TODO: code up function
    // Check if a specific cell is valid
    bool valid = mRules->applyRules(value, index, mBoard, mGridSize);    
    return valid;
};

Sudoku::~Sudoku() {
    delete [] mBoard;
    std::cout << "Deleted mBoard\n";
    delete mRules;
    std::cout << "Deleted mRules";
}