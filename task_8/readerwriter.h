#ifndef READERWRITERCLASS
#define READERWRITERCLASS

#include "reader.h"
#include "writer.h"

class ReaderWriter : public Reader, public Writer {
public:
  virtual ~ReaderWriter() {}
};

#endif
