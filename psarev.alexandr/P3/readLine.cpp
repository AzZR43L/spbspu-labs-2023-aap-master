#include "readLine.hpp"

void psarev::readLine(char*& line)
{
  char elem = 0;
  size_t elemNum = 0;
  std::cin >> std::noskipws;
  while (std::cin >> elem) {
    line[elemNum++] = elem;
    if (elem == '\n') {
      line[elemNum - 1] = 0;
      break;
    }
    if (elemNum % 10 == 0) {
      char* extLine = new char[elemNum + 10] {};
      for (size_t i = 0; i < elemNum; i++) {
        extLine[i] = line[i];
      }
      delete[] line;
      line = extLine;
    }
  }
  std::cin >> std::skipws;
}