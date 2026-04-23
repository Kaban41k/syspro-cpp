#include <iostream>
#include "tests.h"
#include "square_matrice.h"

int n = 0;

void assert(bool x) {
  if (x) return;
  std::cout << "!!!ASSERT IN TEST " << n << " FAILED!!!" << std::endl;
}

void test0() {
  n = 0;
  
  SMatrice m(10);

  for (size_t i = 0; i < m.size(); i++) {
    for (size_t j = 0; j < m.size(); j++) {
      assert(m[i][j] == 0);
    }
  }
}

void test1() {
  n = 1;

  std::vector<double> vec(0);
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);

  SMatrice m(vec);

  assert(m.size() == vec.size());

  for (size_t i = 0; i < vec.size(); i++) {
    assert(m[i][i] == vec[i]);
  }
}

void test2() {
  n = 2;

  SMatrice m(2);

  m[0][0] = 1;
  m[0][1] = -1;
  m[1][1] = 1.2;

  assert(static_cast<double>(m) == 1.2);
}

void test3() {
  n = 3;

  SMatrice m1(3);
  SMatrice m2(3);

  m1[0][0] = 19;
  m2[0][0] = 1;
  m2[1][2] = 3;

  SMatrice m3 = m1 + m2;

  for (size_t i = 0; i < m3.size(); i++) {
    for (size_t j = 0; j < m3.size(); j++) {
      assert(m3[i][j] == (m1[i][j] + m2[i][j]));
    }
  }
}

void test4() {
  n = 4;

  SMatrice m1(3);
  SMatrice m2(3);

  m1[0][0] = 19;
  m2[0][0] = 1;
  m2[1][2] = 3;

  SMatrice m3 = m1 * m2;

  for (size_t i = 0; i < m3.size(); i++) {
    for (size_t j = 0; j < m3.size(); j++) {
      assert(m3[i][j] == (m1[i][j] * m2[i][j]));
    }
  }
}

void test5() {
  n = 5;

  SMatrice m1(3);

  m1[0][0] = 19;
  m1[2][2] = 1;

  SMatrice m = m1 + 2;

  for (size_t i = 0; i < m.size(); i++) {
    for (size_t j = 0; j < m.size(); j++) {
      assert(m[i][j] == (m1[i][j] + 2));
    }
  }
}

void test6() {
  n = 6;

  SMatrice m1(3);

  m1[0][0] = 19;
  m1[2][2] = 1;

  SMatrice m = m1 * 2;

  for (size_t i = 0; i < m.size(); i++) {
    for (size_t j = 0; j < m.size(); j++) {
      assert(m[i][j] == (m1[i][j] * 2));
    }
  }
}

void test7() {
  n = 7;

  SMatrice m1(2);
  SMatrice m2(2);

  m1[0][0] = 19;
  m1[1][1] = 3;
  m2[1][1] = 1;

  SMatrice m = m1;

  m += m2;

  for (size_t i = 0; i < m.size(); i++) {
    for (size_t j = 0; j < m.size(); j++) {
      assert(m[i][j] == (m1[i][j] + m2[i][j]));
    }
  }
}


void test8() {
  n = 8;

  SMatrice m1(2);
  SMatrice m2(2);

  m1[0][0] = 19;
  m1[1][1] = 3;
  m2[1][1] = 1;

  SMatrice m = m1;

  m *= m2;

  for (size_t i = 0; i < m.size(); i++) {
    for (size_t j = 0; j < m.size(); j++) {
      assert(m[i][j] == (m1[i][j] * m2[i][j]));
    }
  }
}