#include <iostream>
#include "avl_tree.h"

AVL_tree::Node::Node(int v) {
  value = v;
  height = 0;
  left = nullptr;
  right = nullptr;
};

AVL_tree::AVL_tree() {
  root_ = nullptr;
}

AVL_tree::~AVL_tree() {
  while (root_ == nullptr) {
    remove(root_->value);
  }
}

void AVL_tree::insert(int value) {
  root_ = insert_(root_, value);
}

void AVL_tree::remove(int value) {
  root_ = remove_(root_, value);
}

bool AVL_tree::find(int value) {
  return find_(root_, value);
}

int AVL_tree::getMax() {
  return getMax_(root_)->value;
}

int AVL_tree::getMin() {
  return getMin_(root_)->value;
}

void AVL_tree::balance_(Node node) {
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

int AVL_tree::getBalance_(Node node) {
  return getHeight_(node.right) - getHeight_(node.left);
}

void AVL_tree::updateHeight_(Node node) {
  node.height = std::max(getHeight_(node.left), getHeight_(node.right)) + 1;
}

int AVL_tree::getHeight_(Node* node) {
  return node == nullptr ? -1 : node->height;
}

void AVL_tree::swap_(Node a, Node b) {
  int c = a.value;
  a.value = b.value;
  b.value = c;
}

void AVL_tree::rightRotate_(Node node) {
  swap_(node, *node.left);
  Node* buf = node.right;
  node.right = node.left;
  node.left = node.right->left;
  node.right->left = node.right->right;
  node.right->right = buf;

  updateHeight_(*node.right);
  updateHeight_(node);
}

void AVL_tree::leftRotate_(Node node) {
  swap_(node, *node.right);
  Node* buf = node.left;
  node.left = node.right;
  node.right = node.left->right;
  node.left->right = node.left->left;
  node.left->left = buf;

  updateHeight_(*node.left);
  updateHeight_(node);
}

AVL_tree::Node* AVL_tree::getMax_(Node* node) {
  if (node == nullptr) return nullptr;
  if (node->right == nullptr) return node;
  return getMax_(node->right);
}

AVL_tree::Node* AVL_tree::getMin_(Node* node) {
  if (node == nullptr) return nullptr;
  if (node->left == nullptr) return node;
  return getMin_(node->left);
}

AVL_tree::Node* AVL_tree::insert_(Node* node, int value) {
  if (node == nullptr) return new Node(value);

  if (node->value > value)
    node->left = insert_(node->left, value);
  else if (node->value < value)
    node->right = insert_(node->right, value);

  updateHeight_(*node);
  balance_(*node);

  return node;
}

AVL_tree::Node* AVL_tree::remove_(Node* node, int value) {
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
      node->left = remove_(node->left, left_max->value);
    }
  }

  if (node != nullptr) {
    updateHeight_(*node);
    balance_(*node);
  }
  
  return node;
}

bool AVL_tree::find_(Node* node, int value) {
  if (node == nullptr) return false;
  if (node->value == value) return true;
  return (node->value > value) ? find_(node->left, value) : find_(node->right, value);
}
