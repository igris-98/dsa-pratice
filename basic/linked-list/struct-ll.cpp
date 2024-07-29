#include <bits/stdc++.h>

using namespace std;
struct Node {
public:
  int data;
  Node *next;

public:
  Node(int data1, Node *next1) {
    data = data1;
    next = next1;
  }

  Node(int data1) {
    data = data1;
    next = nullptr;
  }
};

int main (int argc, char *argv[]) {
  Node x = Node(10, nullptr);
  Node* y = &x;

  cout << x.data << endl;
  cout << x.next << endl;

  cout << y->data << endl;
  cout << y->next << endl;

  Node* z = new Node(11);

  cout << z->data << endl;
  cout << z->next << endl;

  return 0;
}
