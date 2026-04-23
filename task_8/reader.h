#ifndef READERCLASS
#define READERCLASS

#include <string>
#include "io.h"

class Reader : virtual public IO {
public:
  virtual int read_int() = 0;
  virtual double read_double() = 0;
  virtual char read_char() = 0;
  virtual std::string read_string() = 0;

  virtual ~Reader() {}
};

#endif
