#ifndef SUDOKU_H_
#define SUDOKU_H_

#include <iostream>

class Sudoku {

    private:
        char mSubGridSize{0};
        char mGridSize{0};
        unsigned short mGridArea{0};
        char* mBoard{nullptr};
        bool mIsSolved{false};
        unsigned short mEmptyCells{0};

    public:
        Sudoku() {};
        Sudoku(short subGridSize);
        short getSubGridSize() const { return mSubGridSize; }
        short getGridSize() const { return mGridSize; }
        int getGridArea() const { return mGridArea; }
        bool setValue(const short& row, const short& col, const char& value);
        bool setValue(const int& index, const char& value);
        char getValue(const short& row, const short& col) const;
        char getValue(const int& index) const;
        void displayBoard() const;
        bool isValid();
        bool isValid(const short& row, const short& col);
        bool isValid(const int& index);
        ~Sudoku() { delete [] mBoard; std::cout << "Deleted mBoard";}
};

#endif