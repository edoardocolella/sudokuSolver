
#include "sudoku.hpp"

namespace {
bool isLegalMoveSquare(unsigned int **matrix, unsigned int num, unsigned row,
                       unsigned col) {

  unsigned verticalSquareIndex = row / 3;
  unsigned horizontalSquareIndex = col / 3;

  unsigned horizontalOffset = horizontalSquareIndex * 3;
  unsigned verticalOffset = verticalSquareIndex * 3;

  for (unsigned i = 0; i < 3; ++i) {
    unsigned rowIdx = verticalOffset + i;
    for (unsigned j = 0; j < 3; ++j) {

      unsigned colIdx = horizontalOffset + j;
      if (rowIdx != row && colIdx != col && matrix[rowIdx][colIdx] == num) {
        return false;
      }
    }
  }

  return true;
}

bool isLegalMoveRow(unsigned int **matrix, unsigned int num, unsigned row,
                    unsigned col) {

  for (int i = 0; i < 9; ++i) {
    if (i != col && matrix[row][i] == num) {
      return false;
    }
  }

  return true;
}

bool isLegalMoveCol(unsigned int **matrix, unsigned int num, unsigned row,
                    unsigned col) {
  for (int i = 0; i < 9; ++i) {
    if (i != row && matrix[i][col] == num) {
      return false;
    }
  }

  return true;
}
}
bool Sudoku::isLegalMove(unsigned int **matrix, unsigned int num, unsigned row,
                 unsigned col) {
  return isLegalMoveSquare(matrix, num, row, col) &&
         isLegalMoveRow(matrix, num, row, col) &&
         isLegalMoveCol(matrix, num, row, col);
}
