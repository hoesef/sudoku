#include <math.h>

#include "../include/sudokuRules.h"
#include "../include/utils/conversion.h"

bool ClassicSudoku::isValid(const char value, const short index, const char* board, char gridSize) {
    char row, col;
    toRowCol(index, gridSize, row, col);
    return isValid(value, row, col, board, gridSize);
}
bool ClassicSudoku::isValid(const char value, const char row, const char col, const char* board, char gridSize) {
    // Check rows for uniquness
    short startIndex = row*gridSize;
    for (int i = 0; i < gridSize; i++) {
        if (board[startIndex+i] == value) { return false; }
    }
    // Check colums for uniquness
    startIndex = col;
    for (int i = 0; i < gridSize; i++) {
        if (board[startIndex + (i*gridSize)] == value) { return false; }
    }
    // Check subGrids for uniquness
    short subGridSize = sqrt(gridSize);
    char rowStart = (row % subGridSize) * gridSize;
    char colStart = (col % subGridSize) * gridSize;
    for (int i = 0; i < subGridSize; i++) {
        for (int j = 0; j < subGridSize; j++) {
            if (board[((rowStart+i) * gridSize) + (colStart+j)] == value) { return false; }
        }
    }
    return true;
}

bool ForwardDiagonal::isValid(const char value, const short index, const char* board, char gridSize) {
    char row, col;
    toRowCol(index, gridSize, row, col);
    return isValid(value, row, col, board, gridSize);
}
bool ForwardDiagonal::isValid(const char value, const char row, const char col, const char* board, char gridSize) {
    // Check if on forward diagonal
    if (row + col != (gridSize-1)) { return true; }
    // Check forward diagonal [(0,8), (1,7), ..., (7,1), (8,0)] for uniquness
    for (int i = 0; i < gridSize; i++) {
        if (board[(i * gridSize) + (gridSize-i-1)] == value) { return false; }
    }
    return true;
}

bool BackwardDiagonal::isValid(const char value, const short index, const char* board, char gridSize) {
    char row, col;
    toRowCol(index, gridSize, row, col);
    return isValid(value, row, col, board, gridSize);
}
bool BackwardDiagonal::isValid(const char value, const char row, const char col, const char* board, char gridSize) {
    // Check if on backward diagonal
    if (row != col) { return true; }
    // Check forward diagonal [(0,0), (1,1), ..., (7,7), (8,8)] for uniquness
    for (int i = 0; i < gridSize; i++) {
        if (board[(i * gridSize) + i] == value) { return false; }
    }
    return true;
}

KillerSudoku::KillerSudoku(const KillerSudoku& other) {
    mNumCages = other.mNumCages;
    mCageLengths = new int[mNumCages]{0};
    mCageSums = new int[mNumCages]{0};
    mCages = new int*[mNumCages]{nullptr};

    int currentLen = 0;
    for (int i = 0; i < mNumCages; i++) {
        // Get current length of cage
        currentLen = other.mCageLengths[i];
        // Set cage length and sum
        mCageLengths[i] = currentLen;
        mCageSums[i] = other.mCageSums[i];
        // Make new cage array
        mCages[i] = new int[currentLen]{0};
        // Copy cage data
        for (int j = 0; j < currentLen; j++) {
            mCages[i][j] = other.mCages[i][j];
        }
    }
}
KillerSudoku::KillerSudoku(int** cages, int* cageLengths, int*cageSums, int numCages) {
    mNumCages = numCages;
    mCageLengths = new int[mNumCages]{0};
    mCageSums = new int[mNumCages]{0};
    mCages = new int*[mNumCages]{nullptr};

    int currentLen = 0;
    for (int i = 0; i < mNumCages; i++) {
        // Get current length of cage
        currentLen = cageLengths[i];
        // Set cage length and sum
        mCageLengths[i] = currentLen;
        mCageSums[i] = cageSums[i];
        // Make new cage array
        mCages[i] = new int[currentLen]{0};
        // Copy cage data
        for (int j = 0; j < currentLen; j++) {
            mCages[i][j] = cages[i][j];
        }
    }
}
KillerSudoku& KillerSudoku::operator=(const KillerSudoku& other) {

    // ---Free any data already set---//
    // Free cages
    for (int i = 0; i < mNumCages; i++) {
        delete [] mCages[i];
        mCages[i] = nullptr;
    }
    delete [] mCages;

    // Free cage lengths
    delete [] mCageLengths;

    // Free cage sums
    delete [] mCageSums;
    // ------------------------------ //

    mNumCages = other.mNumCages;
    mCageLengths = new int[mNumCages]{0};
    mCageSums = new int[mNumCages]{0};
    mCages = new int*[mNumCages]{nullptr};

    int currentLen = 0;
    for (int i = 0; i < mNumCages; i++) {
        // Get current length of cage
        currentLen = other.mCageLengths[i];
        // Set cage length and sum
        mCageLengths[i] = currentLen;
        mCageSums[i] = other.mCageSums[i];
        // Make new cage array
        mCages[i] = new int[currentLen]{0};
        // Copy cage data
        for (int j = 0; j < currentLen; j++) {
            mCages[i][j] = other.mCages[i][j];
        }
    }
    return *this;
}
void KillerSudoku::findCageIndex(const short index, int& cage, int& length) {
    // Look through every cage
    for (cage = 0; cage < mNumCages; cage++) {
        length = mCageLengths[cage];
        // Look through every index the cage spans
        for (int i = 0; i < length; i++) {
            if (mCages[cage][i] == index) { return; }
        }
    }
    // If index not found, set error flag
    length = -1;
    cage = -1;
}
bool KillerSudoku::isValid(const char value, const short index, const char* board, const char gridSize) {
    int length = -1;
    int cage = -1;
    // Find which cage contains target index
    findCageIndex(index, cage, length);
    if (length <= 0 || cage < 0) { return false; }
    short sum = 0;
    short total = mCageSums[cage];
    int cageIndex = 0;
    int val = 0;
    for (int i = 0; i < length; i++) {
        cageIndex = mCages[cage][i];
        val = board[cageIndex];
        // Check cage is unique
        if (val == value) { return false; }
        // Check sum of cage is valid
        sum += val;
        if ((sum + value) > total) {return false; }
    }
    return true;
}
bool KillerSudoku::isValid(const char value, const char row, const char col, const char* board, const char gridSize) {
    short index = toIndex(row, col, gridSize);
    return isValid(value, index, board, gridSize);
}
KillerSudoku::~KillerSudoku() {
    // Free cages
    for (int i = 0; i < mNumCages; i++) {
        delete [] mCages[i];
        mCages[i] = nullptr;
    }
    delete [] mCages;

    // Free cage lengths
    delete [] mCageLengths;

    // Free cage sums
    delete [] mCageSums;
    std::cout << "SudokuRules: KillerSudoku destructor called\n"; 
}

ThermoSudoku::ThermoSudoku(const ThermoSudoku& other) {
    mNumThermometers = other.mNumThermometers;
    mThermometerLengths = new int[mNumThermometers]{0};
    mThermometers = new int*[mNumThermometers]{nullptr};

    int currentLen = 0;
    for (int i = 0; i < mNumThermometers; i++) {
        // Get current length of thermometer
        currentLen = other.mThermometerLengths[i];
        mThermometerLengths[i] = currentLen;
        // Make new thermometer array
        mThermometers[i] = new int[currentLen]{0};
        for (int j = 0; j < currentLen; j++) {
            // Copy thermometer data
            mThermometers[i][j] = other.mThermometers[i][j];
        }
    }
}
ThermoSudoku::ThermoSudoku(int** thermometers, int* thermometerLengths, int numThermometers) {
    mNumThermometers = numThermometers;
    mThermometerLengths = new int[mNumThermometers]{0};
    mThermometers = new int*[mNumThermometers]{nullptr};

    int currentLen = 0;
    for (int i = 0; i < mNumThermometers; i++) {
        // Get current length of thermometer
        currentLen = thermometerLengths[i];
        mThermometerLengths[i] = currentLen;
        // Make new thermometer array
        mThermometers[i] = new int[currentLen]{0};
        for (int j = 0; j < currentLen; j++) {
            // Copy thermometer data
            mThermometers[i][j] = thermometers[i][j];
        }
    }
}
ThermoSudoku& ThermoSudoku::operator=(const ThermoSudoku& other) {
    // Free thermometers
    for (int i = 0; i < mNumThermometers; i++) {
        delete [] mThermometers[i];
        mThermometers[i] = nullptr;
    }
    delete [] mThermometers;

    // Free thermometer length array
    delete [] mThermometerLengths;

    mNumThermometers = other.mNumThermometers;
    mThermometerLengths = new int[mNumThermometers]{0};
    mThermometers = new int*[mNumThermometers]{nullptr};

    int currentLen = 0;
    for (int i = 0; i < mNumThermometers; i++) {
        // Get current length of thermometer
        currentLen = other.mThermometerLengths[i];
        mThermometerLengths[i] = currentLen;
        // Make new thermometer array
        mThermometers[i] = new int[currentLen]{0};
        for (int j = 0; j < currentLen; j++) {
            // Copy thermometer data
            mThermometers[i][j] = other.mThermometers[i][j];
        }
    }
    return *this;
}
void ThermoSudoku::findThermometerIndex(const short index, int& thermometer, int& length) {
    for (thermometer = 0; thermometer < mNumThermometers; thermometer++) {
        length = mThermometerLengths[thermometer];
        for (int i = 0; i < length; i++) {
            int thermometerIndex = mThermometers[thermometer][i];
            if (thermometerIndex == index) { return; }
        }
    }
    thermometer = -1;
    length = -1;
}
bool ThermoSudoku::isValid(const char value, const short index, const char* board, char gridSize) {
    int length = -1;
    int thermometer = -1;
    // Find which thermometer (if any) spans index
    findThermometerIndex(index, thermometer, length);
    if (length <= 0 || thermometer < 0) { return true; }
    int thermometerIndex = 0;
    int val = 0;
    bool seen = false;
    // Look through thermometer indexes
    for (int i = 0; i < length; i++) {
        thermometerIndex = mThermometers[thermometer][i];
        if (thermometerIndex == index) { seen = true; } // mark we have seen the index
        val = board[thermometerIndex];
        if (val == 0) { continue; } // skip unset cells
        if (val == value) { return false; } // unique numbers in thermometer
        if (!seen && val > value) { return false; } // thermometer value greater than input value before input index
        if (seen && val < value) { return false; } // thermometer value less than input value after input index
    }
    return true;
}
bool ThermoSudoku::isValid(const char value, const char row, const char col, const char* board, char gridSize) {
    int index = toIndex(row, col, gridSize);
    return isValid(value, index, board, gridSize);
}
ThermoSudoku::~ThermoSudoku() {
    // Free thermometers
    for (int i = 0; i < mNumThermometers; i++) {
        delete [] mThermometers[i];
        mThermometers[i] = nullptr;
    }
    delete [] mThermometers;

    // Free thermometer length array
    delete [] mThermometerLengths;
    std::cout << "SudokuRules: ThermoSudoku destructor called\n"; 
}