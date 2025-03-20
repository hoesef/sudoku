#ifndef GENERATOR_H_
#define GENERATOR_H_

#include "sudoku.h"
#include "ruleSet.h"

class Generator {

    public:
        Generator() {}
        void generate(Sudoku& sudoku, char subGridSize, RuleSet& ruleset);
        ~Generator() {}

    private:
        void fillBoard();
        void removeNumbers();
        void makeCages();
        bool isUnique();

};

#endif