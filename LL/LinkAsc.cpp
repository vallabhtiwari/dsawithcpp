#include <exception>
#include <iostream>
using namespace std;
//=====================================================================================================
class LinkedList;
class Node {
  int el;
  Node *next;

public:
  Node();
  Node(int);
  friend class LinkedList;
  friend void compare(LinkedList, LinkedList);
  friend void separate(LinkedList);
};
//=====================================================================================================
Node ::Node() { next = NULL; }

Node::Node(int e) {
  el = e;
  next = NULL;
}
//=====================================================================================================
class LinkedList {
  Node *top;

public:
  LinkedList();

  void insertAsc(int);
  friend void compare(LinkedList, LinkedList);
  void print();
  friend void separate(LinkedList);
};
LinkedList ::LinkedList() { top = NULL; }

void LinkedList ::print() {

  if (top == NULL) {
    cout << "List is empty!!\n";
    return;
  }
  Node *t = new Node(); // t is used for traversing the list
  t = top;
  while (t != NULL) {

    cout << t->el << endl;

    t = t->next;
  }
}
void LinkedList::insertAsc(int e) {

  Node *newN = new Node(e);
  if (top == NULL || (top->el) > e) {
    newN->next = top;
    top = newN;
    return;
  }
  Node *t = new Node();
  Node *p = new Node();

  t = top;
  p = t;

  while (t != NULL && (t->el) <= e) {

    p = t;
    t = t->next;
  }

  newN->next = t;
  p->next = newN;
}

void compare(LinkedList a, LinkedList b) {
  Node *p = new Node();
  Node *q = new Node();
  p = a.top;
  q = b.top;
  while (p != NULL && q != NULL) {
    p = p->next;
    q = q->next;
  }
  if (p == NULL && q == NULL)
    cout << "Lists are equal\n";
  else if (q == NULL)
    cout << "First list is longer\n";
  else
    cout << "Second list is longer\n";
}

LinkedList po, ne;

void separate(LinkedList s) {
  Node *t = new Node();
  t = s.top;
  Node *a = new Node();
  a = po.top;
  Node *b = new Node();
  b = ne.top;
  Node *newN = new Node();
  while (t != NULL) {
    newN = new Node(t->el);
    if (newN->el >= 0) {
      newN->next = po.top;
      po.top = newN;
    } else {
      newN->next = ne.top;
      ne.top = newN;
    }
    t = t->next;
  }
}
int main() {
  LinkedList a;
  a.insertAsc(5);
  a.insertAsc(-5);
  a.insertAsc(-3);
  a.insertAsc(3);
  a.insertAsc(-5);
  a.insertAsc(5);
  a.print();
  // separate(a);
  // cout<<"++\n";
  // a.print();
  // cout<<"--\n";
  // ne.print();
  // compare(po,ne);
  return 0;
}
