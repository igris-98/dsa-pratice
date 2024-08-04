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
  void removeNode(Node *node);
  void insertBeforeHead(int value);
  void insertBeforeTail(int value);
  void insertBeforeKth(int value, int index);
  void insertBeforeNode(Node *node);
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
  if (this->isEmpty() || this->head->next == NULL) {
    this->head = NULL;
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
  if (this->isEmpty() || this->head->next == NULL) {
    this->removeHead();
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
// index = 1 to n
void DoublyLinkedlist::removeAtIndex(int index) {
  if (this->isEmpty() || index == 1) {
    this->removeHead();
  } else {
    Node *curr = this->head;
    int counter = 0;
    while (curr != nullptr) {
      counter++;
      if (counter == index) {
        break;
      }
      curr = curr->next;
    }
    Node *prev = curr->prev;
    Node *next = curr->next;

    if (prev == nullptr && next == nullptr) {
      this->removeHead(); // O(1) using Node directly
    } else if (prev == nullptr) {
      this->removeHead(); // O(1) using Node directly
    } else if (next == nullptr) {
      this->removeTail(); // O(1) using Node directly
    } else {
      prev->next = next;
      next->prev = prev;
      curr->next = nullptr;
      curr->prev = nullptr;
      delete curr;
    }
  }
}

// O(n)
void DoublyLinkedlist::removeElement(int value) {
  if (this->isEmpty() || this->head->data == value) {
    this->removeHead();
  } else {
    Node *curr = this->head;
    while (curr != nullptr) {
      if (curr->data == value) {
        break;
      }
      curr = curr->next;
    }
    Node *prev = curr->prev;
    Node *next = curr->next;

    if (prev == nullptr && next == nullptr) {
      this->removeHead(); 
    } else if (prev == nullptr) {
      this->removeHead(); 
    } else if (next == nullptr) {
      this->removeTail(); // O(1) using Node directly
    } else {
      prev->next = next;
      next->prev = prev;
      curr->next = nullptr;
      curr->prev = nullptr;
      delete curr;
    }
  }
}

void DoublyLinkedlist::removeNode(Node *node) {
  Node *prev = node->prev;
  Node *next = node->next;

  if (prev == nullptr) {
    this->removeHead();
  } else if (next == nullptr) {
    this->removeTail();
  } else {
    prev->next = next;
    next->prev = prev;
    node->next = nullptr;
    node->prev = nullptr;
    delete node;
  }
}

void DoublyLinkedlist::insertBeforeHead(int value) {
  Node *newNode = new Node(value);
  if (this->head != NULL) {
    newNode->next = this->head;
    this->head->prev = newNode;
  }
  this->head = newNode;
}

void DoublyLinkedlist::insertBeforeTail(int value) {
  if (this->head == NULL || this->head->next == NULL) {
    this->insertBeforeHead(value);
  } else {
    Node *newNode = new Node(value);
    Node *curr = this->head;
    while (curr->next != NULL) {
      curr = curr->next;
    }
    Node *prev = curr->prev;
    newNode->prev = prev;
    newNode->next = curr;
    prev->next = newNode;
    curr->prev = newNode;
  }
}

void DoublyLinkedlist::insertBeforeKth(int value, int index) {
  if (this->head == NULL || index == 1) {
    this->insertBeforeHead(value);
  } else {
    Node *newNode = new Node(value);
    int count = 0;
    Node *curr = this->head;
    while (curr->next != NULL) {
      count++;
      if(count == index){
        break;
      }
      curr = curr->next;
    }
    Node *prev = curr->prev;
    newNode->prev = prev;
    newNode->next = curr;
    prev->next = newNode;
    curr->prev = newNode;
  }
}

void DoublyLinkedlist::reverseDll() {
  Node *curr = this->head;
  Node *last = nullptr;
  while (curr != nullptr) {
    last = curr->prev;
    curr->prev = curr->next;
    curr->next = last;
    curr = curr->prev;
  }
  this->head = last->prev;
}

int main(int argc, char *argv[]) {
  vector<int> arr = {12, 2, 4, 5};
  // vector<int> arr = {12};
  // vector<int> arr;

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

  /* ll.reverseDll();
  ll.display();
  cout << endl;
  cout << "----------" << endl; */

  /* ll.removeAtIndex(4);
  ll.removeElement(12);
  ll.display();
  cout << endl;
  cout << "----------" << endl; */

  // ll.insertBeforeHead(10);

  // ll.insertBeforeTail(11);
  
  // ll.insertBeforeKth(12, 1);
  // ll.insertBeforeKth(13, 5);
  // ll.insertBeforeKth(13, 4);
  
  ll.display();
  cout << endl;
  cout << "----------" << endl;

  return 0;
}
