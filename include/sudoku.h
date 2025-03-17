#ifndef SUDOKU_H_
#define SUDOKU_H_

#include <iostream>

class Sudoku {

    private:
        char* mBoard{nullptr};
        short mSubGridSize = 0;
        short mGridSize = 0;
        int mGridArea = 0;

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
        virtual bool loadFromFile(const char* fileName) = 0;
        virtual void displayBoard() const = 0;
        virtual bool isValid() = 0;
        virtual bool isValid(const short& row, const short& col) = 0;
        virtual bool isValid(const int& index) = 0;
        virtual bool generate() = 0;
        virtual ~Sudoku() { delete [] mBoard; std::cout << "Deleted mBoard";}
};

class ClassicSudoku : public Sudoku {

    public:
        ClassicSudoku(short subGridSizes);
        virtual bool loadFromFile(const char* fileName) override;
        virtual void displayBoard() const override;
        virtual bool isValid() override;
        virtual bool isValid(const short& row, const short& col) override;
        virtual bool isValid(const int& index) override;
        virtual bool generate() override;
};

#endif