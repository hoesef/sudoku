/*
 * Credit to Mark Fredrik Graves Jr for the Generation algorithm
 * Details about how the algorithm works can be found in his video:
 * https://www.youtube.com/watch?v=LHCHH5siBCg
*/

#include <random>
#include "generator.h"

Sudoku* Generator::generate(char subGridSize, RuleSet& ruleSet, short numRandom) { //char* difficulty
    if (mSudoku) { delete mSudoku; }                // Delete any pervious sudoku
    mSudoku = new Sudoku(subGridSize, ruleSet);     // Allocate new memory
    fillBoard(numRandom);                           // Fill board with numbers
    for (int i = 0; i < ruleSet.getNum(); i++) {    // Check if we need cages
        // Check if we need cages
    }
    removeNumbers();                                // Remove numbers from board
    return mSudoku;    
}

void Generator::fillBoard(short numRandom) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> value_distr(1, mSudoku->getGridSize());
    std::uniform_int_distribution<> index_distr(0, mSudoku->getGridArea() - 1);

    char value = 0;
    short index = 0;
    while (numRandom) {
        value = value_distr(gen);
        index = index_distr(gen);
        if (mSudoku->getValue(index) == 0 && mSudoku->isValid(value, index)) {
            mSudoku->setValue(index, value);
            numRandom--;
            mSudoku->displayBoard();
        }
    }
}

void Generator::recurse() {

}

void Generator::removeNumbers() {}

void Generator::makeCages() {}

bool Generator::isUnique() {
    return true;
}