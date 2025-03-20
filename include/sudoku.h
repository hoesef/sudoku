#ifndef SUDOKU_H_
#define SUDOKU_H_

#include "ruleSet.h"

class Sudoku {

    private:
        char mSubGridSize{0};               // Size of sub-grid (3x3) for a standard (9x9) sudoku
        char mGridSize{0};                  // Size of the sudoku grid
        unsigned short mGridArea{0};        // Total area of the grid (also the max index + 1)
        char* mBoard{nullptr};              // Char array representing the sudoku grid
        bool mIsSolved{false};              // Flag signifying completed puzzle
        unsigned short mEmptyCells{0};      // Number of cells left to fill
        RuleSet* mRules{nullptr};           // Rules for the current puzzle

    public:
        Sudoku(const Sudoku& other);
        Sudoku(short subGridSize, RuleSet& puzzleRules);
        Sudoku& operator=(const Sudoku& other);
        const char getSubGridSize() const { return mSubGridSize; }
        const char getGridSize() const { return mGridSize; }
        const short getGridArea() const { return mGridArea; }
        const short getEmpty() const { return mEmptyCells; }
        const char* getBoard() const { return mBoard; }
        bool setValue(const char& row, const char& col, const char& value);
        bool setValue(const short& index, const char& value);
        char getValue(const char& row, const char& col) const;
        char getValue(const short& index) const;
        void displayBoard() const;
        bool isValid();
        bool isValid(const char value, const char& row, const char& col);
        bool isValid(const char value, const short& index);
        ~Sudoku();
};

#endif