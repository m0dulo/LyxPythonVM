#include <stdio.h>
#include <assert.h>

#include "binaryFileParser.hpp"

BinaryFileParser::BinaryFileParser(BufferedInputStraem* buf_file_stream) {
    file_stream = buf_file_stream;
}

CodeObject* BinaryFileParser::parse() {
    
}