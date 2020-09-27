#include "util/bufferedInputStream.hpp"
#include "code/binaryFileParser.hpp"
#include "runtime/interpreter.hpp"
#include "runtime/universe.hpp"

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        printf("LyxPythonVM need  a parameter: filename\n");
        return 0;
    }

    BufferedInputStraem stream(argv[1]);
    BinaryFileParser parser(&stream);
    CodeObject* main_code = parser.parse();

    Universe::genesis();
    Interpreter interpreter;
    interpreter.run(main_code);

    return 0;
}
