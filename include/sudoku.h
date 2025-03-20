#ifndef SUDOKU_H_
#define SUDOKU_H_

#include <iostream>
#include "ruleSet.h"

class Sudoku {

    private:
        char mSubGridSize{0};
        char mGridSize{0};
        unsigned short mGridArea{0};
        char* mBoard{nullptr};
        bool mIsSolved{false};
        unsigned short mEmptyCells{0};
        RuleSet* mRules{nullptr};

    public:
        // Sudoku() {};
        Sudoku(short subGridSize, RuleSet* puzzleRules);
        const char getSubGridSize() const { return mSubGridSize; }
        const char getGridSize() const { return mGridSize; }
        const short getGridArea() const { return mGridArea; }
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