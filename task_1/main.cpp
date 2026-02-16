#include <iostream>

using namespace std;

class AVL_tree {
private:
  class Node {
  public:
    int value;
    int height;
    Node* left;
    Node* right;

    Node(int v) {
        value = v;
        height = 0;
        left = nullptr;
        right = nullptr;
    }
  };

  Node* root_;

  void balance_(Node node) {
    int balance = getBalance_(node);
    
    if (balance == -2) {
      if (getBalance_(*node.left) == 1)
        leftRotate_(node);
      rightRotate_(node);
    } else if (balance == 2) {
      if (getBalance_(*node.right) == -1)
        rightRotate_(node);
      leftRotate_(node);
    }
  }

  int getBalance_(Node node) {
    return getHeight_(node.right) - getHeight_(node.left);
  }

  void updateHeight_(Node node) {
    node.height = max(getHeight_(node.left), getHeight_(node.right)) + 1;
  }

  int getHeight_(Node* node) {
    return node == nullptr ? -1 : node->height;
  }

  void swap_(Node a, Node b) {
    int c = a.value;
    a.value = b.value;
    b.value = c;
  }

  void rightRotate_(Node node) {
    swap(node, *node.left);
    Node* buf = node.right;
    node.right = node.left;
    node.left = node.right->left;
    node.right->left = node.right->right;
    node.right->right = buf;

    updateHeight_(*node.right);
    updateHeight_(node);
  }

  void leftRotate_(Node node) {
    swap(node, *node.right);
    Node* buf = node.left;
    node.left = node.right;
    node.right = node.left->right;
    node.left->right = node.left->left;
    node.left->left = buf;

    updateHeight_(*node.left);
    updateHeight_(node);
  }

  Node* getMax_(Node* node) {
    if (node == nullptr) return nullptr;
    if (node->right == nullptr) return node;
    return getMax_(node->right);
  }

  Node* getMin_(Node* node) {
    if (node == nullptr) return nullptr;
    if (node->left == nullptr) return node;
    return getMin_(node->left);
  }

Node* insert_(Node* node, int value) {
    if (node == nullptr) return new Node(value);

    if (node->value > value)
      node->left = insert_(node->left, value);
    else if (node->value < value)
      node->right = insert_(node->right, value);

    updateHeight_(*node);
    balance_(*node);
  
    return node;
  }

  Node* remove_(Node* node, int value) {
    if (node == nullptr) return nullptr;

    if (node->value > value) {
      node->left = remove_(node->left, value);
    } else if (node->value < value) {
      node->right = remove_(node->right, value);
    } else {
      if (node->left == nullptr || node->right == nullptr) {
        Node* buf = (node->left == nullptr ? node->right : node->left);
        delete node;
        node = buf;
      } else {
        Node* left_max = getMax_(node->left);
        node->value = left_max->value;
        node->right = remove_(node->right, left_max->value);
      }
    }

    if (node != nullptr) {
      updateHeight_(*node);
      balance_(*node);
    }
    
    return node;
  }

  bool find_(Node* node, int value) {
    if (node == nullptr) return false;
    if (node->value == value) return true;
    return (node->value > value) ? find_(node->left, value) : find_(node->right, value);
  }

public:
  AVL_tree() {
    root_ = nullptr;
  }

  void insert(int value) {
    root_ = insert_(root_, value);
  }

  void remove(int value) {
    root_ = remove_(root_, value);
  }

  bool find(int value) {
    return find_(root_, value);
  }

  int getMax() {
    return getMax_(root_)->value;
  }
  
  int getMin() {
    return getMin_(root_)->value;
  }
};

int n = 0;

void assert(bool x) {
  if (x) return;
  cout << "!!!ASSERT IN TEST " << n << " FAILED!!!" << endl;
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
  n = 2;
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

int main() {
  test0();
  test1();
  test2();
  test3();

  return 0;
}
