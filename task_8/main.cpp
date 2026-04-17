#include <iostream>
#include "tests.h"
#include "stringsource.h"
#include "filesource.h"

int main() {
  StringSource string_source;

  std::string str("Hello^-^");

  string_source.write_string(str + ' ');
  string_source.write_int(30123);
  string_source.write_char('d');
  

  std::cout << string_source.get_data() << std::endl; 

  assert(string_source.read_string() == str);
  assert(string_source.read_int() == 30123);
  assert(string_source.read_char() == 'd');

  FileSource file_source("test.txt", "w");

  file_source.write_string("Hello");

  file_source.close();

  FileSource file_source_reader("test.txt", "r");

  std::cout << file_source_reader.read_string() << std::endl;

  return 0;
}
