#include <string>

enum Color { NONE, RED, GREEN };

class Sudoku {
public:
  Sudoku(const std::string &path);
  ~Sudoku();

  void resolve();
  void printMatrix(unsigned coloredRow = 10, unsigned coloredCol = 10,
                   Color color = NONE);
  void printRow(unsigned row, unsigned coloredRow = 10,
                unsigned coloredCol = 10, Color color = NONE);

private:
  bool resolveR(unsigned row, unsigned col);

  bool isLegalMove(unsigned int **matrix, unsigned int num, unsigned row,
                   unsigned col);

  unsigned **matrix;
};