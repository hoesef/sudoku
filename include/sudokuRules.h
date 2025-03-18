#ifndef SUDOKU_RULES_H_
#define SUDOKU_RULES_H_

class SudokuRules {

    public:
        SudokuRules() {};
        virtual bool isValid(const char value, const char index, const char*& board, char gridSize) = 0;
        virtual bool isValid(const char value, const char row, const char col, const char*& board, char gridSize) = 0;
        ~SudokuRules() {};

};

class ClassicSudoku : public SudokuRules {

    public:
        virtual bool isValid(const char value, const char index, const char*& board, char gridSize) override;
        virtual bool isValid(const char value, const char row, const char col, const char*& board, char gridSize) override;

};

class ForwardDiagonal : public SudokuRules {

    public:
        virtual bool isValid(const char value, const char index, const char*& board, char gridSize) override;
        virtual bool isValid(const char value, const char row, const char col, const char*& board, char gridSize) override;
};

class BackwardDiagonal : public SudokuRules {

    public:
        virtual bool isValid(const char value, const char index, const char*& board, char gridSize) override;
        virtual bool isValid(const char value, const char row, const char col, const char*& board, char gridSize) override;
};

class KillerSudoku : public SudokuRules {

    private:
        int** mCages{nullptr};
        int* mCageLengths{nullptr};
        int* mCageSums{nullptr};
        int mNumCages{0};

    public:
        KillerSudoku(int** cages, int* cageLengths, int*cageSums, int numCages);
        virtual bool isValid(const char value, const char index, const char*& board, char gridSize) override;
        virtual bool isValid(const char value, const char row, const char col, const char*& board, char gridSize) override;
        ~KillerSudoku();

    private:
        void findCageIndex(const char index, int& cage, int& length);

};

class ThermoSudoku : public SudokuRules {

    private:
        int** mThermometers{nullptr};
        int* mThermometerLengths{nullptr};
        int mNumThermometers{0};

    public:
        ThermoSudoku(int** thermometers, int* thermometerLengths, int numThermometers);
        virtual bool isValid(const char value, const char index, const char*& board, char gridSize) override;
        virtual bool isValid(const char value, const char row, const char col, const char *& board, char gridSize) override;
        ~ThermoSudoku();

    private:
        void findThermometerIndex(const char index, int& thermometer, int& length);
    
};

#endif