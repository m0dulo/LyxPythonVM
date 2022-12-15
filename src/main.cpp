#include "BufferedInputStream.hpp"

int main(int argc, char *argv[]) {
  if (argc <= 1) {
    printf("LyxPythonVM need  a parameter: filename\n");
    return 0;
  }

  BufferedInputStraem stream(argv[1]);
  printf("magic number is 0x%x\n", stream.read_init());

  return 0;
}