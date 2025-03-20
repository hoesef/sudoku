#ifndef SUDOKU_RULES_H_
#define SUDOKU_RULES_H_

// Remove this include later
#include <iostream>

class SudokuRules {

    public:
        SudokuRules() {};
        SudokuRules(const SudokuRules& other) {};
        SudokuRules& operator=(const SudokuRules& other) {return *this; };
        virtual bool isValid(const char value, const short index, const char* board, char gridSize) = 0;
        virtual bool isValid(const char value, const char row, const char col, const char* board, char gridSize) = 0;
        virtual ~SudokuRules() { std::cout << "SudokuRules base class destructor called\n"; };

};

class ClassicSudoku : public SudokuRules {

    public:
        // ClassicSudoku(const ClassicSudoku& other) {};
        // ClassicSudoku& operator=(const ClassicSudoku& other) { return *this; }
        virtual bool isValid(const char value, const short index, const char* board, char gridSize) override;
        virtual bool isValid(const char value, const char row, const char col, const char* board, char gridSize) override;
        ~ClassicSudoku() { std::cout << "SudokuRules: ClassicSudoku destructor called\n"; }
};

class ForwardDiagonal : public SudokuRules {

    public:
        // ForwardDiagonal(const ForwardDiagonal& other) {};
        // ForwardDiagonal& operator=(const ForwardDiagonal& other) { return *this; }
        virtual bool isValid(const char value, const short index, const char* board, char gridSize) override;
        virtual bool isValid(const char value, const char row, const char col, const char* board, char gridSize) override;
        ~ForwardDiagonal() { std::cout << "SudokuRules: ForwardDiagonal destructor called\n"; }
};

class BackwardDiagonal : public SudokuRules {

    public:
        // BackwardDiagonal(const BackwardDiagonal& other) {};
        // BackwardDiagonal& operator=(const BackwardDiagonal& other) { return *this; }
        virtual bool isValid(const char value, const short index, const char* board, char gridSize) override;
        virtual bool isValid(const char value, const char row, const char col, const char* board, char gridSize) override;
        ~BackwardDiagonal() { std::cout << "SudokuRules: BackwardDiagonal destructor called\n"; }
};

class KillerSudoku : public SudokuRules {

    private:
        int** mCages{nullptr};
        int* mCageLengths{nullptr};
        int* mCageSums{nullptr};
        int mNumCages{0};

    public:
        KillerSudoku(const KillerSudoku& other);
        KillerSudoku(int** cages, int* cageLengths, int*cageSums, int numCages);
        KillerSudoku& operator=(const KillerSudoku& other);
        virtual bool isValid(const char value, const short index, const char* board, char gridSize) override;
        virtual bool isValid(const char value, const char row, const char col, const char* board, char gridSize) override;
        ~KillerSudoku();

    private:
        void findCageIndex(const short index, int& cage, int& length);

};

class ThermoSudoku : public SudokuRules {

    private:
        int** mThermometers{nullptr};
        int* mThermometerLengths{nullptr};
        int mNumThermometers{0};

    public:
        ThermoSudoku(const ThermoSudoku& other);
        ThermoSudoku(int** thermometers, int* thermometerLengths, int numThermometers);
        ThermoSudoku& operator=(const ThermoSudoku& other);
        virtual bool isValid(const char value, const short index, const char* board, char gridSize) override;
        virtual bool isValid(const char value, const char row, const char col, const char * board, char gridSize) override;
        ~ThermoSudoku();

    private:
        void findThermometerIndex(const short index, int& thermometer, int& length);
    
};

#endif