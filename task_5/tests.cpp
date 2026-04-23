#include <iostream>
#include "tests.h"
#include "scoped_pointer_dc.h"
#include "scoped_pointer_nc.h"
#include "avl_tree.h"

int n = 0;

void assert(bool x) {
  if (x) return;
  std::cout << "!!!ASSERT IN TEST " << n << " FAILED!!!" << std::endl;
}

void test0() {
  n = 0;
  
  ScopedPointerDC a_p{new int(10)};

  assert(a_p.get() == 10);  
}

void test1() {
  n = 1;

  ScopedPointerDC a_p{new AVL_tree()};

  a_p.get().insert(1);
  a_p.get().insert(3);
  a_p.get().insert(2);

  assert(a_p.get().find(1));
  
  ScopedPointerDC b_p = a_p;

  a_p.get().remove(1);

  assert(b_p.get().find(1));
}

void test2() {
  n = 2;

  ScopedPointerNC a_p{new int(10)};

  assert(a_p.get() == 10);  
}

void test3() {
  n = 3;

  ScopedPointerNC a_p{new AVL_tree()};

  a_p.get().insert(1);
  a_p.get().insert(3);
  a_p.get().insert(2);

  assert(a_p.get().find(1));
}
