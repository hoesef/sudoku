#ifndef RULESET_H_
#define RULESET_H_

#include <iostream>
#include "sudokuRules.h"

class RuleSet {

    private:
        SudokuRules** mRuleSet{nullptr};    // Pointer to array of pointers to SudokuRules
        int mNumRules = 0;                  // Number of rules in ruleset
    
    public:
        RuleSet() {}
        RuleSet(const RuleSet& other);
        RuleSet(SudokuRules** rules, int numRules);
        RuleSet& operator=(const RuleSet& other);
        int getNum() {return mNumRules;}
        bool applyRules(const char value, const short index, char*& board, char gridSize);
        ~RuleSet();

};

#endif