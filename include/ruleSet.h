#ifndef RULESET_H_
#define RULESET_H_

#include <iostream>
#include "sudokuRules.h"

class RuleSet {

    private:
        SudokuRules** mRuleSet{nullptr};
        int mNumRules{0};
    
    public:
        RuleSet() {}
        RuleSet(SudokuRules** rules, int numRules);
        bool applyRules(const char value, const short index, char*& board, char gridSize);
        ~RuleSet();

};

#endif