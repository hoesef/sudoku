#include "..\include\ruleSet.h"

RuleSet::RuleSet(const RuleSet& other) {
    mNumRules = other.mNumRules;
    mRuleSet = new SudokuRules*[mNumRules];
    for (int i = 0; i < mNumRules; i++) {
        std::cout << "Address of rule being coppied: " << other.mRuleSet[i] << "\n";
        mRuleSet[i] = (other.mRuleSet[i])->clone();   
        std::cout << "Address of new rule: " << mRuleSet[i] << "\n";
    }
}
RuleSet::RuleSet(SudokuRules** rules, int numRules) {
    mNumRules = numRules;
    mRuleSet = new SudokuRules*[mNumRules];
    for (int i = 0; i < mNumRules; i++) {
        mRuleSet[i] = rules[i]->clone();
    }
}
RuleSet& RuleSet::operator=(const RuleSet& other) {
    // Delete any perviously alocated rules
    std::cout << "NumRules: " << mNumRules << "\n";
    for (int i = 0; i < mNumRules; i++) {
        delete mRuleSet[i];
        mRuleSet[i] = nullptr;
    }
    delete [] mRuleSet;
    mRuleSet = nullptr;

    std::cout << "Deleted old pointers\n";
    // Set new rules
    mNumRules = other.mNumRules;
    std::cout << "num rules coppied\n";
    mRuleSet = new SudokuRules*[mNumRules];
    std::cout << "Memory for mRuleSet allocated\n";

    for (int i = 0; i < mNumRules; i++) {
        *(mRuleSet[i]) = *(other.mRuleSet[i]);
        std::cout << "Address of copied rule: " << other.mRuleSet[i] << "\nAddress of new rule: " << mRuleSet[i] << "\n\n";
    }
    std::cout << "Rules coppied\n\n";
    return *this;
}
bool RuleSet::applyRules(const char value, const short index, char*& board, char gridSize) {
    bool valid = false;
    std::cout << "In apply rules\n";
    for (int i = 0; i < mNumRules; i++) {
        std::cout << "Checking rule: " << i << "\n";
        std::cout << mRuleSet[i]->getName();
        valid = (mRuleSet[i])->isValid(value, index, board, gridSize);
        std::cout << (valid?"True\n":"False\n");
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