#ifndef WRITERCLASS
#define WRITERCLASS

#include <string>
#include "io.h"

class Writer : virtual public IO {
public:
  virtual void write_int(int x) = 0;
  virtual void write_double(double x) = 0;
  virtual void write_char(char c) = 0;
  virtual void write_string(const std::string& str) = 0;

  virtual ~Writer() {}
};

#endif
