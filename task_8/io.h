#ifndef IOCLASS
#define IOCLASS


class IO {
protected:
  bool _is_open;
  bool _is_eof_reached;

public:
  IO() : _is_open(true), _is_eof_reached(false) {};
  virtual ~IO() {}

  void close() { _is_open = false; };
};

#endif
