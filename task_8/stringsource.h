#include "readerwriter.h"
#include <stdexcept>

class StringSource : public ReaderWriter {
private:
  std::string _data;
  size_t _read_pos;
  size_t _write_pos;

  void _is_open_check() {
    if (!_is_open) throw "source is closed :(";
  }

  void _eof_check() {
    if (_is_eof_reached) throw "EOF reached :(";
  }

public:
  StringSource() : _read_pos(0), _write_pos(0), _data() {
    _data.push_back(' ');
  }

  std::string read_string() override {
    _is_open_check();
    _eof_check();
    
    size_t start = _read_pos;
    while (_read_pos < _data.size() && _data[_read_pos] != ' ') {
      _read_pos++;
    }

    std::string sub = _data.substr(start, _read_pos - start);
    
    while (_read_pos < _data.size() && _data[_read_pos] == ' ') {
      _read_pos++;
    }
    
    if (_read_pos >= _data.size()) _is_eof_reached = true;

    return sub;
  }

  int read_int() override {
    _is_open_check();
    _eof_check();
    
    size_t start = _read_pos;
    
    while (_read_pos < _data.size() && std::isdigit(_data[_read_pos])) { _read_pos++; }

    if (start == _read_pos) throw "integer not found :(";
    if (_read_pos >= _data.size()) _is_eof_reached = true;

    return std::stoi(_data.substr(start, _read_pos - start));
  }

  double read_double() override {
    _is_open_check();
    _eof_check();
    
    size_t start = _read_pos;
    bool dot = false;
    while (_read_pos < _data.size() && (std::isdigit(_data[_read_pos]) || _data[_read_pos] == '.')) {
      if (_data[_read_pos++] == '.') {
        if (dot) break;
        dot = true;
      }
    }

    if (start == _read_pos) throw "double not found :(";
    if (_read_pos >= _data.size()) _is_eof_reached = true;
    
    return std::stod(_data.substr(start, _read_pos - start));
  }

  char read_char() override {
    _is_open_check();
    _eof_check();

    if (_read_pos + 1 >= _data.size()) _is_eof_reached = true;

    return _data[_read_pos++];
  }

  void write_char(char c) override {
    _is_open_check();

    if (_write_pos >= _data.size()) {
      _data.resize(_data.size() * 2);
    }

    _data[_write_pos++] = c;
    _is_eof_reached = false;
  }

  void write_string(const std::string& str) override {
    _is_open_check();

    for (size_t i = 0; i < str.size(); i++) {
      write_char(str[i]);
    }
  }

  void write_int(int x) override {
    _is_open_check();
    
    std::string str = std::to_string(x);
    write_string(str);
  }

  void write_double(double x) override {
    _is_open_check();

    std::string str = std::to_string(x);
    write_string(str);
  }

  std::string get_data() const {
    return _data;
  }
};
