#include <iostream>
#include "tests.h"

int n = 0;

void assert(bool x) {
  if (x) return;
  std::cout << "!!!ASSERT IN TEST " << n << " FAILED!!!" << std::endl;
}

void test0() {
  
}
