#include "sudoku.hpp"

#include <fstream>
#include <iostream>

namespace {
std::pair<unsigned, unsigned> findNextCell(unsigned int **matrix) {
  for (unsigned rowIdx = 0; rowIdx < 9; ++rowIdx) {
    for (unsigned colIdx = 0; colIdx < 9; ++colIdx) {
      if (matrix[rowIdx][colIdx] == 0) {
        return {rowIdx, colIdx};
      }
    }
  }
  return {9, 9};
}
} // namespace

Sudoku::Sudoku(const std::string &path) {

  std::ifstream inputFile(path);

  if (!inputFile.is_open()) {
    throw std::runtime_error(" Error: impossible to open the file");
  }

  matrix = new unsigned int *[9];

  for (int i = 0; i < 9; ++i) {
    matrix[i] = new unsigned int[9];

    for (int j = 0; j < 9; ++j) {
      inputFile >> matrix[i][j];
    }
  }
  inputFile.close();
}

Sudoku::~Sudoku() {
  for (int i = 0; i < 9; ++i) {
    delete[] matrix[i];
  }
  delete[] matrix;
}

bool Sudoku::resolveR(unsigned row, unsigned col) {
  unsigned nextRow, nextCol;
  std::tie(nextRow, nextCol) = findNextCell(matrix);
  if (nextRow == 9 && nextCol == 9)
    return true;

  for (unsigned num = 1; num <= 9; ++num) {
    if (isLegalMove(matrix, num, nextRow, nextCol)) {
      matrix[nextRow][nextCol] = num;
      std::cout << "\r";
      //printRow(nextRow, nextRow, nextCol, GREEN);
      if (resolveR(nextRow, nextCol)) {
        return true;
      }
    }
  }
  matrix[nextRow][nextCol] = 0;
  
  //printRow(nextRow, nextRow, nextCol, RED);
  return false;
}

void Sudoku::resolve() { resolveR(0, 0); }
