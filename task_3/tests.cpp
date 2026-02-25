#include <iostream>
#include "tests.h"
#include "avl_tree.h"

int n = 0;

void assert(bool x) {
  if (x) return;
  std::cout << "!!!ASSERT IN TEST " << n << " FAILED!!!" << std::endl;
}

void test0() {
  n = 0;
  AVL_tree tree = AVL_tree();

  tree.insert(42);
  
  assert(tree.find(42));
}

void test1() {
  n = 1;
  AVL_tree tree = AVL_tree();

  tree.insert(20);
  tree.insert(13);
  tree.insert(15);
  tree.insert(30);

  assert(tree.find(20));
  assert(tree.find(13));
  assert(tree.find(15));
  assert(tree.find(30));
  assert(!tree.find(0));

  tree.remove(20);
}

void test2() {
  n = 2;
  AVL_tree tree = AVL_tree();

  tree.insert(20);
  tree.insert(13);
  tree.insert(15);
  tree.insert(30);

  assert(tree.getMin() == 13);
  assert(tree.getMax() == 30);
}


void test3() {
  n = 3;
  AVL_tree tree = AVL_tree();

  tree.insert(1);
  tree.insert(2);
  tree.insert(3);
  tree.insert(4);
  tree.insert(5);
  tree.insert(6);

  assert(tree.find(5));
  tree.remove(5);
  tree.remove(3);
  tree.remove(1);
  assert(!tree.find(5));
  assert(!tree.find(1));
  assert(!tree.find(100));
}

void test4() {
  n = 4;
  AVL_tree tree = AVL_tree();

  tree.insert(1);
  tree.insert(2);
  tree.insert(3);
  tree.insert(4);
  tree.insert(5);
  tree.insert(6);

  AVL_tree tree2 = tree;

  tree.remove(4);
  tree.remove(3);
  
  assert(!tree.find(4));
  assert(tree2.find(4));
}

void test5() {
  n = 5;
  AVL_tree tree = AVL_tree();

  tree.insert(1);
  tree.insert(2);
  tree.insert(3);
  tree.insert(4);
  tree.insert(5);
  tree.insert(6);

  AVL_tree tree2(tree);

  tree.remove(4);
  
  assert(!tree.find(4));
  assert(tree2.find(4));
}

