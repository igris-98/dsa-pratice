#include <bits/stdc++.h>

using namespace std;

class Node {
public:
  int data;
  Node* left;
  Node* right;

public:
  Node(int data){
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
  }
};

class BinaryTree {
public:
  Node* root;
  BinaryTree(Node* root){
    this->root = root;
  }
  void preOrder(Node* root);
  void inOrder(Node* root);
  void postOrder(Node* root);
  void levelOrder(Node* root);
};

void BinaryTree::preOrder(Node* root){
  if(root != NULL){
    cout<< root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
  }
}

void BinaryTree::inOrder(Node* root){
  if(root != NULL){
    preOrder(root->left);
    cout<< root->data << " ";
    preOrder(root->right);
  }
}

void BinaryTree::postOrder(Node* root){
  if(root != NULL){
    preOrder(root->left);
    preOrder(root->right);
    cout<< root->data << " ";
  }
}

void BinaryTree::levelOrder(Node* root){
  if(root != NULL){
    preOrder(root->left);
    preOrder(root->right);
    cout<< root->data << " ";
  }
}

int main (int argc, char *argv[]) {
  BinaryTree* bt = new BinaryTree(new Node(1));
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
  return 0;
}
