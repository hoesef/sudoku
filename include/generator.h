#ifndef GENERATOR_H_
#define GENERATOR_H_

#include "sudoku.h"
#include "ruleSet.h"

class Generator {

    private:
        Sudoku* mSudoku{nullptr};           // Pointer to a sudoku object

    public:
        Generator() {}
        Sudoku* generate(char subGridSize, RuleSet& ruleset, short numRandom = 5);
        ~Generator() { delete mSudoku; }

    private:
        void fillBoard(short numRandom);
        void recurse();
        void removeNumbers();
        void makeCages();
        bool isUnique();

};

#endif