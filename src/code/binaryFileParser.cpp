#include <assert.h>
#include <stdio.h>

#include "binaryFileParser.hpp"

BinaryFileParser::BinaryFileParser(BufferedInputStream *buf_file_stream) {
  file_stream = buf_file_stream;
}

CodeObject *BinaryFileParser::parse() {
  int magic_number = file_stream->read_init();
  printf("magic number is 0x%x\n", magic_number);
  int moddate = file_stream->read_init();
  printf("moddate is 0x%x\n", moddate);

  char object_type = file_stream->read();

  if (object_type == 'c') {
    CodeObject *result = get_code_object();
    printf("parse OK!\n");
    return result;
  }

  return NULL;
}

CodeObject *BinaryFileParser::get_code_object() {
  int argcount = file_stream->read_init();
  int nlocals = file_stream->read_init();
  int stacksize = file_stream->read_init();
  int flags = file_stream->read_init();
  printf("flags is 0x%x\n", flags);

  LyxString *byte_codes = get_byte_codes();
  ArrayList<LyxObject *> *consts = get_consts();
  ArrayList<LyxObject *> *names = get_names();
  ArrayList<LyxObject *> *var_names = get_var_names();
  ArrayList<LyxObject *> *free_vars = get_free_vars();
  ArrayList<LyxObject *> *cell_vars = get_cell_vars();

  LyxString *file_name = get_file_name();
  LyxString *module_name = get_name();
  int begin_line_no = file_stream->read_init();
  LyxString *lnotab = get_no_table();

  return new CodeObject(argcount, nlocals, stacksize, flags, byte_codes, consts,
                        names, var_names, free_vars, cell_vars, file_name,
                        module_name, begin_line_no, lnotab);
}

LyxString *BinaryFileParser::get_string() {
  int length = file_stream->read_init();
  char *str_value = new char[length];

  for (int i = 0; i < length; i++) {
    str_value[i] = file_stream->read();
  }

  LyxString *s = new LyxString(str_value, length);
  delete[] str_value;

  return s;
}

LyxString *BinaryFileParser::get_name() {
  char ch = file_stream->read();

  if (ch == 's') {
    return get_string();
  } else if (ch == 't') {
    LyxString *str = get_string();
    _string_table.add(str);
    return str;
  } else if (ch == 'R') {
    return _string_table.get(file_stream->read_init());
  }

  return NULL;
}

LyxString *BinaryFileParser::get_file_name() { return get_name(); }

LyxString *BinaryFileParser::get_byte_codes() {
  if (file_stream->read() != 's') {
        return NULL;
    }

  return get_string();
}

LyxString *BinaryFileParser::get_no_table() {
  char ch = file_stream->read();

  if (ch != 's' && ch != 't') {
    file_stream->unread();
    return NULL;
  }

  return get_string();
}

ArrayList<LyxObject *> *BinaryFileParser::get_consts() {
  if (file_stream->read() == '(') {
    return get_tuple();
  }

  file_stream->unread();
  return NULL;
}

ArrayList<LyxObject *> *BinaryFileParser::get_names() {
  if (file_stream->read() == '(') {
    return get_tuple();
  }

  file_stream->unread();
  return NULL;
}

ArrayList<LyxObject *> *BinaryFileParser::get_var_names() {
  if (file_stream->read() == '(') {
    return get_tuple();
  }

  file_stream->unread();
  return NULL;
}

ArrayList<LyxObject *> *BinaryFileParser::get_free_vars() {
  if (file_stream->read() == '(') {
    return get_tuple();
  }

  file_stream->unread();
  return NULL;
}

ArrayList<LyxObject *> *BinaryFileParser::get_cell_vars() {
  if (file_stream->read() == '(') {
    return get_tuple();
  }

  file_stream->unread();
  return NULL;
}

ArrayList<LyxObject *> *BinaryFileParser::get_tuple() {
  int length = file_stream->read_init();
  LyxString *str;

  ArrayList<LyxObject *> *list = new ArrayList<LyxObject *>(length);
  for (int i = 0; i < length; i++) {
    char obj_type = file_stream->read();

    switch (obj_type) {
    case 'c':
      printf("got a code object\n");
      list->add(get_code_object());
      break;
    case 'i':
      list->add(new LyxInteger(file_stream->read_init()));
      break;
    case 'N':
      list->add(NULL);
      break;
    case 't':
      str = get_string();
      list->add(str);
      _string_table.add(str);
      break;
    case 's':
      list->add(get_string());
      break;
    case 'R':
      list->add(_string_table.get(file_stream->read_init()));
      break;
    default:
      printf("parser, unrecognized type : %c\n", obj_type);
    }
  }

  return list;
}