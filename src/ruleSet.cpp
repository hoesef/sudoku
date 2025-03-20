#include "..\include\ruleSet.h"

// RuleSet copy constructor 
RuleSet::RuleSet(const RuleSet& other) {
    mNumRules = other.mNumRules; // copy numRules
    mRuleSet = new SudokuRules*[mNumRules]; // allocate new array
    for (int i = 0; i < mNumRules; i++) {
        mRuleSet[i] = (other.mRuleSet[i])->clone(); // Deep copy each rule
    }
}
// RuleSet Constructor
RuleSet::RuleSet(SudokuRules** rules, int numRules) {
    mNumRules = numRules; // copy numRules
    mRuleSet = new SudokuRules*[mNumRules]; // allocate new array
    for (int i = 0; i < mNumRules; i++) {
        mRuleSet[i] = rules[i]->clone(); // Deep copy each rule
    }
}
// Assignment operator
RuleSet& RuleSet::operator=(const RuleSet& other) {
    // Delete any perviously alocated rules
    for (int i = 0; i < mNumRules; i++) {
        delete mRuleSet[i];
        mRuleSet[i] = nullptr;
    }
    delete [] mRuleSet;
    mRuleSet = nullptr;

    // Set new rules
    mNumRules = other.mNumRules; // Copy numRules
    mRuleSet = new SudokuRules*[mNumRules]; // allocate new array
    for (int i = 0; i < mNumRules; i++) {
        mRuleSet[i] = other.mRuleSet[i]->clone();
    }
    return *this;
}
// Apply rules
bool RuleSet::applyRules(const char value, const short index, char*& board, char gridSize) {
    for (int i = 0; i < mNumRules; i++) {
        if (!(mRuleSet[i])->isValid(value, index, board, gridSize)) { return false; } // Check for borken rule
    }
    return true;
}
// RuleSet destructor
RuleSet::~RuleSet() {
    // Free each rule
    for (int i = 0; i < mNumRules; i++) {
        delete mRuleSet[i];
        mRuleSet[i] = nullptr;
    }
    // Free ruleset array
    delete mRuleSet;
    mRuleSet = nullptr;
}