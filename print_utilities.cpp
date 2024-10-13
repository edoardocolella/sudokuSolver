
#include "sudoku.hpp"

#include <iostream>

namespace {
void printSeparator() { std::cout << "---------------------\n"; }

void printRed(unsigned num) {
  std::cout << "\033[1;31m" << num << "\033[0m" << " ";
}

void printGreen(unsigned num) {
  std::cout << "\033[1;32m" << num << "\033[0m" << " ";
}
void printCell(unsigned num) { std::cout << num << " "; }
void printCell(unsigned num, Color color) {
  switch (color) {
  case RED:
    printRed(num);
    break;
  case GREEN:
    printGreen(num);
    break;
  default:
    printCell(num);
    break;
  }
}

} // namespace

void Sudoku::printMatrix(unsigned coloredRow, unsigned coloredCol,
                         Color color) {

  for (unsigned int row = 0; row < 9; ++row) {
    if (row != 0 && row % 3 == 0) {
      printSeparator();
    }
    printRow(row, coloredRow, coloredCol, color);
  }
}

void Sudoku::printRow(unsigned row, unsigned coloredRow, unsigned coloredCol,
                      Color color) {
  for (unsigned idx = 0; idx < 9; ++idx) {
    if (idx != 0 && idx % 3 == 0) {
      std::cout << "| ";
    }
    if (row == coloredRow && idx == coloredCol && color != NONE) {
      printCell(matrix[row][idx], color);
    }
    printCell(matrix[row][idx]);
  }
  std::cout << "\n";
}