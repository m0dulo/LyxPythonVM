#ifndef BINARY_FILE_PARSER_HPP
#define BINARY_FILE_PARSER_HPP

#include "arrayList.hpp"
#include "bufferedInputStream.hpp"
#include "codeObject.hpp"
#include "lyxInteger.hpp"
#include "lyxObject.hpp"
#include "lyxString.hpp"

class BinaryFileParser {
private:
  BufferedInputStream *file_stream;
  int cur;
  ArrayList<LyxString *> _string_table;

public:
  BinaryFileParser(BufferedInputStream *stream);

public:
  CodeObject *parse();
  CodeObject *get_code_object();
  LyxString *get_byte_codes();
  LyxString *get_no_table();
  int get_int();
  LyxString *get_string();
  LyxString *get_name();

  LyxString *get_file_name();

  ArrayList<LyxObject *> *get_consts();
  ArrayList<LyxObject *> *get_names();
  ArrayList<LyxObject *> *get_var_names();
  ArrayList<LyxObject *> *get_free_vars();
  ArrayList<LyxObject *> *get_cell_vars();
  ArrayList<LyxObject *> *get_tuple();
};

#endif