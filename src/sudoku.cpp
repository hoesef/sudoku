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
};
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
};
char Sudoku::getValue(const int& index) const {
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
                std::cout <<  " 0" << val << std::flush;
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
    int area = getGridArea();
    for (int i = 0; i < area; i++) {
        if (!isValid(i)) { return false; }
    }
    return true;
};
bool Sudoku::isValid(const short& row, const short& col) {
    // TODO: code up function
    // Check if a specific cell is valid
    return false;
};
bool Sudoku::isValid(const int& index) {
    // TODO: code up function
    // Check if a specific cell is valid
    return false;
};