#include "..\include\ruleSet.h"

RuleSet::RuleSet(SudokuRules** rules, int numRules) {
    mNumRules = numRules;
    mRuleSet = new SudokuRules*[mNumRules];

    std::cout << "RULE SET CODE SHOULD BE UPDATED:\nPotential Memory Leak" << std::endl;

    // DOES NOT TAKE OWNERSHIP OF THE OBJECT
    // CAN CAUSE MEMORY LEAKS
    // SHOULD ADD A COPY CONSTRUCTOR IN SUDOKURULES
    for (int i = 0; i < mNumRules; i++) {
        mRuleSet[i] = rules[i];
    }
}
bool RuleSet::applyRules(const char value, const short index, char*& board, char gridSize) {
    bool valid = false;
    for (int i = 0; i < mNumRules; i++) {
        valid = (mRuleSet[i])->isValid(value, index, board, gridSize);
        if (!valid) { return false; }
    }
    return true;
}
RuleSet::~RuleSet() {
    for (int i = 0; i < mNumRules; i++) {
        delete mRuleSet[i];
        mRuleSet[i] = nullptr;
    }
    delete mRuleSet;
    mRuleSet = nullptr;
}