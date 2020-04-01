#include <stdio.h>
#include <assert.h>

#include "binaryFileParser.hpp"

BinaryFileParser::BinaryFileParser(BufferedInputStraem* buf_file_stream) {
    file_stream = buf_file_stream;
}

CodeObject* BinaryFileParser::parse() {
    int magic_number = file_stream->read_init();
    printf("magic number is 0x%x\n", magic_number);
    int moddate = file_stream->read_init();
    printf("moddate is 0x%x\n", moddate);

    char object_type = file_stream->read();

    if (object_type == 'c') {
        CodeObject* result = get_code_object();
        printf("parse OK!\n");
        return result;
    }
    return nullptr;
}

CodeObject* BinaryFileParser::get_code_object() {

}