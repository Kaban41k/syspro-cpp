#include "readerwriter.h"

class FileSource : public ReaderWriter {
private:
  FILE* _file;

  void _is_open_check() {
    if (!_is_open) throw "source is closed :(";
  }

public:
  FileSource(const char* name, const char* mode) {
    _file = fopen(name, mode);

    if (!_file) {
      throw "failed to open file ToT";
    }
  }

  ~FileSource() override {
    if (_is_open && _file) {
      fclose(_file);
    }
  }

  void close() {
    if (_is_open && _file) {
      fclose(_file);
      _is_open = false;
    }
  }

  void write_string(const std::string& str) override {
    _is_open_check();

    for (size_t i = 0; i < str.size(); i++) {
      fputc(str[i], _file);
    }
  }

  std::string read_string() override {
    _is_open_check();

    std::string result;
    int c;
    
    while ((c = fgetc(_file)) != EOF) {
        if (c == ' ') {
            break;
        }
        result += static_cast<char>(c);
    }
    
    return result;
  }
  
  int read_int() override {return 0;};
  double read_double() override {return 0;};
  char read_char() override {return '0';};

  void write_int(int x) override {};
  void write_double(double x) override {};
  void write_char(char c) override {};
};

