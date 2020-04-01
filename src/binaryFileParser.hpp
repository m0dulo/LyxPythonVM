#ifndef BINARY_FILE_PARSER_HPP_
#define BINARY_FILE_PARSER_HPP_

#include "bufferedInputStream.hpp"
#include "arrayList.hpp"
#include "lyxObject.hpp"
#include "lyxInteger.hpp"
#include "lyxString.hpp"
#include "codeObject.hpp"

class BinaryFileParser {
private:
    BufferedInputStraem* file_stream;
public:
    BinaryFileParser(BufferedInputStraem* stream);

    CodeObject* parse();
}
#endif // BINARY_FILE_PARSER_HPP_