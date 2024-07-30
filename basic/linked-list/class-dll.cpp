#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node *prev;

  Node(int data, Node *next, Node *prev) {
    this->data = data;
    this->next = next;
    this->prev = prev;
  }

  Node(int data) {
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
  }
};

class DoublyLinkedlist {
public:
  Node *head;

  DoublyLinkedlist() { this->head = NULL; }

  void convertArr2DLL(vector<int> &arr);
  int length();
  int display();
  bool isEmpty();
  bool search(int data);
  void removeHead();
  void removeTail();
  void removeAtIndex(int index);
  void removeElement(int value);
  void insertHead(int value);
  void insertTail(int value);
  void reverseDll();
};

// O(1)
bool DoublyLinkedlist::isEmpty() {
  if (this->head == nullptr) {
    return true;
  }
  return false;
}

// O(n)
void DoublyLinkedlist::convertArr2DLL(vector<int> &arr) {
  this->head = new Node(arr[0]);
  Node *mover = this->head;

  for (unsigned long int i = 1; i < arr.size(); i++) {
    Node *node = new Node(arr[i]);
    mover->next = node;
    node->prev = mover;
    mover = node;
  }
}

// O(n)
int DoublyLinkedlist::length() {
  int count = 0;
  Node *mover = this->head;
  while (mover != nullptr) {
    count++;
    mover = mover->next;
  }
  return count;
}

// traversal O(n)
int DoublyLinkedlist::display() {
  int count = 0;
  Node *mover = this->head;
  while (mover != nullptr) {
    cout << mover->data << " ";
    mover = mover->next;
  }
  return count;
}

// O(n)
bool DoublyLinkedlist::search(int data) {
  Node *mover = this->head;
  while (mover != nullptr) {
    if (mover->data == data) {
      return true;
    }
    mover = mover->next;
  }
  return false;
}

// O(1)
void DoublyLinkedlist::removeHead() {
  if (this->isEmpty()) {
    cout << "List is Empty";
  } else {
    Node *curr = this->head;
    this->head = this->head->next;
    this->head->prev = NULL;
    curr->next = NULL;
    delete curr;
  }
}

// O(n) without Tail Pointer
void DoublyLinkedlist::removeTail() {
  if (this->isEmpty()) {
    cout << "List is Empty";
  } else {
    Node *curr = this->head;
    while (curr->next != nullptr) {
      curr = curr->next;
    }
    Node *prev = curr->prev;
    prev->next = nullptr;
    curr->prev = nullptr;
    free(curr);
  }
}

// O(n)
void DoublyLinkedlist::removeAtIndex(int index) {
  if (this->isEmpty()) {
    cout << "List is Empty";
  } else {
    Node *curr = this->head;
    Node *prev = NULL;
    int counter = 0;

    if (index == 1) {
      this->removeHead();
    }

    while (curr != nullptr) {
      counter++;
      if (counter == index) {
        prev->next = prev->next->next;
        free(curr);
        break;
      }
      prev = curr;
      curr = curr->next;
    }
  }
}

// O(n)
void DoublyLinkedlist::removeElement(int value) {
  if (this->isEmpty()) {
    cout << "List is Empty";
  } else {
    Node *curr = this->head;
    Node *prev = NULL;

    if (curr->data == value) {
      this->removeHead();
    }

    while (curr != nullptr) {
      if (curr->data == value) {
        prev->next = prev->next->next;
        free(curr);
        break;
      }
      prev = curr;
      curr = curr->next;
    }
  }
}

void DoublyLinkedlist::insertHead(int value) {
  Node *newNode = new Node(value);
  if (this->head != NULL) {
    newNode->next = this->head;
  }
  this->head = newNode;
}

void DoublyLinkedlist::insertTail(int value) {
  Node *newNode = new Node(value);
  Node *mover = this->head;
  while (mover->next != NULL) {
    mover = mover->next;
  }
  mover->next = newNode;
}

void DoublyLinkedlist::reverseDll() {
  Node* curr = this->head;
  Node* last = nullptr;
  while (curr != nullptr) {
    last = curr->prev;
    curr->prev = curr->next;
    curr->next = last;
    curr = curr->prev;
  }
  this->head = last->prev;

}

int main(int argc, char *argv[]) {
  vector<int> arr = {12, 2, 4, 1};

  DoublyLinkedlist ll;
  ll.convertArr2DLL(arr);
  ll.display();
  cout << endl;
  cout << "----------" << endl;

  /* ll.removeHead();
  ll.display();
  cout << endl;
  cout << "----------" << endl; */

  /* ll.removeTail();
  ll.display();
  cout << endl;
  cout << "----------" << endl; */

  ll.reverseDll();
  ll.display();
  cout << endl;
  cout << "----------" << endl;

  // ll.removeAtIndex(7);

  /* ll.removeElement(4);
  ll.display();
  cout << endl;
  cout << "----------" << endl; */

  /* ll.insertHead(10);
  ll.insertTail(13);
  ll.display();
  cout << endl;
  cout << "----------" << endl; */

  return 0;
}
