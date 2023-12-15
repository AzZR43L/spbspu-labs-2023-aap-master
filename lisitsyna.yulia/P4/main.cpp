#include <iostream>
#include <fstream>
#include <string>
#include "input_ar.hpp"
#include "minS.hpp"

using namespace lisitsyna;
int main(int argc, char** argv)
{
  if (argc != 4)
  {
    std::cerr << "Incorrectly entered data" << "\n";
    return 1;
  }
  int num = 0;
  try
  {
    num = std::stoll(argv[1]);
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << "Please enter a valid value" << "\n";
    return 1;
  }
  if (num > 2 || num <= 0)
  {
    std::cerr << "Incorrect value" << "\n";
    return 2;
  }
  size_t rows = 0, cols = 0;
  std::ifstream input(argv[2]);
  if (!(input >> rows >> cols))
  {
    std::cerr << "Cannot read the file" << "\n";
    return 2;
  }
  if (input.eof())
  {
    std::cerr << "File is empty" << "\n";
    return 2;
  }
  if (rows < 3 || cols < 3)
  {
    std::ofstream outp(argv[3]);
    outp << 0;
    return 0;
  }
  int* values = 0;
  std::ofstream outputFile(argv[3]);
  if (!outputFile.is_open())
  {
    std::cerr << "Cannot open an ouput file" << "\n";
    return 2;
  }
  int* array;
  if (num == 1)
  {
    int static_array[10000];
    array = static_array;
  }
  else if (num == 2)
  {
    array = new int[cols * rows];
  }
  try
  {
    size_t count = input_ar(input, array, rows * cols);
    if (count != rows * cols)
    {
      std::cerr << "Not correct" << "\n";
      return 2;
      delete[] array;
    }
    outputFile << minS(rows, cols, array);
    return 0;
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what();
    if (num == 2)
    {
      delete[] array;
    }
    return 2;
  }
  try
  {
    size_t count = input_ar(input, array, rows * cols);
    if (count != rows * cols)
    {
      std::cerr << "Not correct" << "\n";
      return 2;
      delete[] array;
    }
    outputFile << minS(rows, cols, array);
    return 0;
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what();
    if (num == 2)
    {
      delete[] array;
    }
    return 2;
  }
  if (num == 2) {
    delete[] array;
  }
  return 0;
}
