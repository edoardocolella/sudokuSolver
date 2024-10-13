#include <iostream>
#include <ostream>
#include <string>
#include <unistd.h> // per sleep()

#include "sudoku.hpp"


int main(int argc, char **argv) {

  if (argc < 2) {
    std::cout << "no input file\n";
    return 0;
  }
  std::string path(argv[1]);

  Sudoku sudoku(path);
  sudoku.printMatrix();
  std::cout << "\n";
  sudoku.resolve();
  sudoku.printMatrix();

}