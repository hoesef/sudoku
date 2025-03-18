#ifndef CONVERSION_H_
#define CONVERSION_H_

short toIndex(char row, char col, char gridSize);
void toRowCol(char index, char gridSize, char& row, char& col);

#endif