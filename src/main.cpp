#include "util/bufferedInputStream.hpp"
#include "code/binaryFileParser.hpp"

int main(int argc, char **argv) {
  if (argc <= 1) {
    printf("LyxPythonVM need a parameter : filename\n");
    return 0;
  }

  BufferedInputStream stream(argv[1]);
  // printf("magic number is 0x%x\n", stream.read_init());
  BinaryFileParser parser(&stream);
  CodeObject *main_code = parser.parse();

  return 0;
}
