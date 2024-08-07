#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;

public:
  Node(int data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
  }
};

class BinaryTree {
public:
  Node *root;
  BinaryTree(Node *root) { this->root = root; }
  void preOrder(Node *root);
  void inOrder(Node *root);
  void postOrder(Node *root);
  vector<vector<int>> levelOrder(Node *root);
};

// All Traversal take T(n) = O(n) S(n) = O(n)
void BinaryTree::preOrder(Node *root) {
  if (root != NULL) {
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
  }
}

void BinaryTree::inOrder(Node *root) {
  if (root != NULL) {
    preOrder(root->left);
    cout << root->data << " ";
    preOrder(root->right);
  }
}

void BinaryTree::postOrder(Node *root) {
  if (root != NULL) {
    preOrder(root->left);
    preOrder(root->right);
    cout << root->data << " ";
  }
}

vector<vector<int>> BinaryTree::levelOrder(Node *root) {
  // Create a 2D vector to store levels
  vector<vector<int>> ans;
  if (root == nullptr) {
    // If the tree is empty,
    // return an empty vector
    return ans;
  }

  // Create a queue to store nodes
  // for level-order traversal
  queue<Node *> q;
  // Push the root node to the queue
  q.push(root);

  while (!q.empty()) {
    // Get the size of the current level
    int size = q.size();
    // Create a vector to store
    // nodes at the current level
    vector<int> level;

    for (int i = 0; i < size; i++) {
      // Get the front node in the queue
      Node *node = q.front();
      // Remove the front node from the queue
      q.pop();
      // Store the node value
      // in the current level vector
      level.push_back(node->data);

      // Enqueue the child nodes if they exist
      if (node->left != nullptr) {
        q.push(node->left);
      }
      if (node->right != nullptr) {
        q.push(node->right);
      }
    }
    // Store the current level
    // in the answer vector
    ans.push_back(level);
  }
  // Return the level-order
  // traversal of the tree
  return ans;
}
void printVector(const vector<int> &vec) {
  // Iterate through the
  // vector and print each element
  for (int num : vec) {
    cout << num << " ";
  }
}

int main(int argc, char *argv[]) {
  BinaryTree *bt = new BinaryTree(new Node(1));
  bt->root->left = new Node(2);
  bt->root->right = new Node(3);
  bt->root->left->left = new Node(4);
  bt->root->left->right = new Node(5);
  bt->root->right->left = new Node(6);
  bt->root->right->right = new Node(7);

  bt->preOrder(bt->root);
  cout << endl;

  bt->inOrder(bt->root);
  cout << endl;

  bt->postOrder(bt->root);
  cout << endl;

  vector<vector<int>> ans = bt->levelOrder(bt->root);
  for (auto level : ans) {
    printVector(level);
  }
  cout << endl;
  return 0;
}
