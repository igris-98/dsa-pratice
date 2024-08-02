#include <bits/stdc++.h>

using namespace std;

class Node {
public:
  int data;
  Node *next;

  Node(int data, Node *next) {
    this->data = data;
    this->next = next;
  }

  Node(int data) {
    this->data = data;
    this->next = nullptr;
  }
};

class Linkedlist {
public:
  Node *head;

  Linkedlist() { this->head = NULL; }

  void convertArr2LL(vector<int> &arr);
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
  void insertAtIndex(int index, int value);
  void reverseLL();
  Node* reverseLLRecursively(Node *head);
  Node* middleNode();
};

// O(1)
bool Linkedlist::isEmpty() {
  if (this->head == nullptr) {
    return true;
  }
  return false;
}

// O(n)
void Linkedlist::convertArr2LL(vector<int> &arr) {
  this->head = new Node(arr[0]);
  Node *mover = this->head;

  for (unsigned long int i = 1; i < arr.size(); i++) {
    Node *node = new Node(arr[i]);
    mover->next = node;
    mover = node;
  }
}

// O(n)
int Linkedlist::length() {
  int count = 0;
  Node *mover = this->head;
  while (mover != nullptr) {
    count++;
    mover = mover->next;
  }
  return count;
}

// traversal O(n)
int Linkedlist::display() {
  int count = 0;
  Node *mover = this->head;
  while (mover != nullptr) {
    cout << mover->data << " ";
    mover = mover->next;
  }
  return count;
}

// O(n)
bool Linkedlist::search(int data) {
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
void Linkedlist::removeHead() {
  if (this->isEmpty()) {
    cout << "List is Empty";
  } else {
    Node *temp = this->head;
    this->head = this->head->next;
    delete temp;
  }
}

// O(n) without Tail Pointer
void Linkedlist::removeTail() {
  if (this->isEmpty()) {
    cout << "List is Empty";
  } else {
    Node *temp = this->head;
    while (temp->next->next != nullptr) {
      temp = temp->next;
    }
    free(temp->next);
    temp->next = nullptr;
  }
}

// O(n)
void Linkedlist::removeAtIndex(int index) {
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
        // prev->next = prev->next->next;
        prev->next = curr->next;
        free(curr);
        break;
      }
      prev = curr;
      curr = curr->next;
    }
  }
}

// O(n)
void Linkedlist::removeElement(int value) {
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

// O(n)
void Linkedlist::insertHead(int value) {
  Node *newNode = new Node(value);
  if (this->head != NULL) {
    newNode->next = this->head;
  }
  this->head = newNode;
}

// O(n)
void Linkedlist::insertTail(int value) {
  Node *newNode = new Node(value);
  if (this->head == nullptr) {
    this->head = newNode;
  } else {
    Node *mover = this->head;
    while (mover->next != NULL) {
      mover = mover->next;
    }
    mover->next = newNode;
  }
}

// O(n)
// Edge case : empty, index = 1 and index >= 2;
void Linkedlist::insertAtIndex(int index, int value) {
  if (this->isEmpty() || index == 1) {
    insertHead(value);
  } else {
    int count = 0;
    Node *mover = this->head;
    while (mover != NULL) {
      count++;
      if (count == index - 1) {
        Node *newNode = new Node(value);
        newNode->next = mover->next;
        mover->next = newNode;
      }
      mover = mover->next;
    }
  }
}

/*
One more solution to reverse linked list using stack (brute force)
  1. create a stack
  2. Travesal through the linkedlist and push to the stack
  3. Travesal through linkedlist again change the data to stack.pop();
  T(n) = O(2n) S(n)=O(n)
*/
// O(n)
void Linkedlist::reverseLL() {
  Node *curr = this->head;
  Node *prev = nullptr;
  Node *next = nullptr;
  while (curr != nullptr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  this->head = prev;
}

// O(n)
Node *Linkedlist::reverseLLRecursively(Node* head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }
  Node *newHead = reverseLLRecursively(head->next);
  Node *front = head->next;
  front->next = head;
  head->next = nullptr;
  return newHead;
}

// O(n/2)
Node* Linkedlist::middleNode(){
  Node* slow = this->head;
  Node* fast = this->head;
  cout << this->head->data << "$";

  while(fast == nullptr && fast->next == nullptr){
    slow = slow->next;
    fast = fast->next->next;
  }
  
  return slow;
}

int main(int argc, char *argv[]) {
  vector<int> arr = {12, 2, 4, 1};

  Linkedlist ll;
  ll.convertArr2LL(arr);
  ll.display();
  cout << endl;
  cout << "----------" << endl;

  /* ll.removeHead();
  ll.removeHead();
  ll.display();
  cout << endl;
  cout << "----------"<< endl; */

  /* ll.removeTail();
  ll.display();
  cout << endl;
  cout << "----------"<< endl; */

  /* ll.reverseLL();
  ll.display();
  cout << endl;
  cout << "----------"<< endl; */

  /* ll.insertAtIndex(1, 10);
  ll.insertAtIndex(2, 11);
  ll.insertAtIndex(6, 15);
  ll.insertAtIndex(10, 15);
  ll.display();
  cout << endl;
  cout << "----------"<< endl; */

  /* ll.removeAtIndex(4);
  ll.display();
  cout << endl;
  cout << "----------"<< endl; */

  /* ll.removeElement(4);
  ll.display();
  cout << endl;
  cout << "----------" << endl; */

  // ll.insertHead(10);

  /* ll.insertTail(13);
  ll.display();
  cout << endl;
  cout << "----------" << endl; */

  ll.head = ll.reverseLLRecursively(ll.head);
  ll.display();
  cout << endl;
  cout << ll.middleNode()->data << endl;
  cout << "----------" << endl;

  return 0;
}
