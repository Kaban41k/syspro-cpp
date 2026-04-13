#ifndef AVLTREE
#define AVLTREE

template <typename T>
class AVL_tree {
public:
  AVL_tree() : root_(nullptr) {};

  AVL_tree(const AVL_tree& other) : root_(copyTree_(other.root_)) {};

  AVL_tree& operator=(const AVL_tree& other) {
    if (this == &other) {
        return *this;
    }

    removeTree_();
    root_ = copyTree_(other.root_);
    return *this;
  };

  ~AVL_tree() {
    removeTree_();
  };

  AVL_tree(AVL_tree&& other) : root_(other.root_) {
    other.root_ = nullptr;
  };
  
  AVL_tree& operator=(AVL_tree&& other) {
    if (this == &other) {
        return *this;
    }

    removeTree_();
    root_ = other.root_;
    other.root_ = nullptr;
    return *this;
  };

  void insert(T value) {
    root_ = insert_(root_, value);
  };

  void remove(T value) {
    root_ = remove_(root_, value);
  };

  bool find(T value) {
    return find_(root_, value);
  }

  T getMax() {
    return getMax_(root_)->value;
  };

  T getMin() {
    return getMin_(root_)->value;
  };

private:
  struct Node {
    T value;
    T height;
    Node* left;
    Node* right;

    Node(T v) : value(v), height(0), left(nullptr), right(nullptr) {};
  };

  Node* root_;

  Node* copyTree_(Node* node) {
    if (node == nullptr) return nullptr;

    Node* new_node = new Node(node->value);

    new_node->left = copyTree_(node->left);
    new_node->right = copyTree_(node->right);

    return new_node;
  };

  void removeTree_() {
    while (root_ != nullptr) {
      remove(root_->value);
    }
  }

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
    node.height = std::max(getHeight_(node.left), getHeight_(node.right)) + 1;
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
    swap_(node, *node.left);
    Node* buf = node.right;
    node.right = node.left;
    node.left = node.right->left;
    node.right->left = node.right->right;
    node.right->right = buf;

    updateHeight_(*node.right);
    updateHeight_(node);
  }

  void leftRotate_(Node node) {
    swap_(node, *node.right);
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
  };

  Node* insert_(Node* node, T value) {
    if (node == nullptr) return new Node(value);

    if (node->value > value)
      node->left = insert_(node->left, value);
    else if (node->value < value)
      node->right = insert_(node->right, value);

    updateHeight_(*node);
    balance_(*node);

    return node;
  };

  Node* remove_(Node* node, T value) {
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
  };

  bool find_(Node* node, T value) {
    if (node == nullptr) return false;
    if (node->value == value) return true;
    return (node->value > value) ? find_(node->left, value) : find_(node->right, value);
  };
};

#endif
