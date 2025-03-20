#include "../../include/utils/conversion.h"

short toIndex(char row, char col, char gridSize) {
    return ((short)row * gridSize) + col;
}

void toRowCol(short index, char gridSize, char& row, char& col) {
    row = index / gridSize;
    col = index % gridSize;
}