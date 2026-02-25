#ifndef AVLTREE
#define AVLTREE

class AVL_tree {
public:
  AVL_tree();
  AVL_tree(const AVL_tree& other);
  AVL_tree& operator=(const AVL_tree& other);
  ~AVL_tree();
  void insert(int value);
  void remove(int value);
  bool find(int value);
  int getMax();
  int getMin();

private:
  struct Node {
    int value;
    int height;
    Node* left;
    Node* right;

    Node(int v);
  };

  Node* root_;

  Node* copyTree_(Node* node);

  void balance_(Node node);
  int getBalance_(Node node);

  void updateHeight_(Node node);
  int getHeight_(Node* node);

  void swap_(Node a, Node b);

  void rightRotate_(Node node);
  void leftRotate_(Node node);

  Node* getMax_(Node* node);
  Node* getMin_(Node* node);

  Node* insert_(Node* node, int value);
  Node* remove_(Node* node, int value);
  bool find_(Node* node, int value);
};

#endif
