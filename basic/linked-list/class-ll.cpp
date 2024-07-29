#include <bits/stdc++.h>
#include <vector>

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
  Node* head;

  Linkedlist(){
    this->head = NULL;
  }

  void convertArr2LL(vector<int> &arr);
  int length();
  int display();
  bool isEmpty();
  bool search(int data);
  void removeHead();
  void removeTail();
  void removeAtIndex(int index);
  void removeElement(int value);
};

//O(1)
bool Linkedlist::isEmpty(){
  if(this->head == nullptr){
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
    if(mover -> data == data){
      return true;
    }
    mover = mover->next;
  }
  return false;
}

// O(1)
void Linkedlist::removeHead(){
  if(this->isEmpty()){
    cout << "List is Empty";
  } else {
    Node* temp = this->head; this->head = this->head->next;
    delete temp;
  }
}

// O(n) without Tail Pointer
void Linkedlist::removeTail(){
  if(this->isEmpty()){
    cout << "List is Empty";
  } else {
    Node* temp = this->head;
    while(temp->next->next != nullptr){
      temp = temp->next;
    }
    free(temp->next);
    temp->next = nullptr;
  }
}

// O(n)
void Linkedlist::removeAtIndex(int index){
  if(this->isEmpty()){
    cout << "List is Empty";
  } else {
    Node* curr = this->head;
    Node* prev = NULL;
    int counter = 0;

    if(index == 1){
      this->removeHead();
    }

    while(curr != nullptr){
      counter++;
      if(counter == index){
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
void Linkedlist::removeElement(int value){
  if(this->isEmpty()){
    cout << "List is Empty";
  } else {
    Node* curr = this->head;
    Node* prev = NULL;

    if(curr->data == value){
      this->removeHead();
    }

    while(curr != nullptr){
      if(curr->data == value){
        prev->next = prev->next->next;
        free(curr);
        break;
      }
      prev = curr;
      curr = curr->next;
    }
  }
}

int main(int argc, char *argv[]) {
  vector<int> arr = {12, 2, 4, 1};

  Linkedlist ll;
  ll.convertArr2LL(arr);
  ll.display();
  cout << endl;
  cout << "----------"<< endl;
  /* ll.removeHead();
  ll.removeHead();
  ll.display();
  cout << endl;
  cout << "----------"<< endl; */
  /* ll.removeTail();
  ll.display();
  cout << endl;
  cout << "----------"<< endl; */
  // ll.removeAtIndex(7);
  ll.removeElement(4);
  ll.display();
  cout << endl;
  cout << "----------"<< endl;

  return 0;
}
