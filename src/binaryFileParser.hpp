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
    int cur;
    ArrayList<LyxString*> _string_table;
public:
    BinaryFileParser(BufferedInputStraem* stream);

    CodeObject* parse();
    CodeObject* get_code_object();
    LyxString* get_byte_codes();
    LyxString* get_no_table();
    int get_int();
    LyxString* get_string();
    LyxString* get_name();

    LyxString* get_file_name();

    ArrayList<LyxObject*>* get_consts();
    ArrayList<LyxObject*>* get_names();
    ArrayList<LyxObject*>* get_var_names();
    ArrayList<LyxObject*>* get_free_vars();
    ArrayList<LyxObject*>* get_cell_vars();
    ArrayList<LyxObject*>* get_tuple();
};

#endif // BINARY_FILE_PARSER_HPP_