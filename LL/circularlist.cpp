#include <exception>
#include <iostream>
using namespace std;

class Node {
  int data;
  Node *next;
  Node() {
    data = 0;
    next = NULL;
  }
  Node(int d) {
    data = d;
    next = NULL;
  }
  friend class CircularLL;
};

class CircularLL {

private:
  Node *cursor;

public:
  CircularLL();
  void addBeg(int);
  void addX(int, int);
  void addBack(int);
  void remBeg();
  void remX(int);
  void remBack();
  void search(int);
  CircularLL operator+(CircularLL);
  void input();
  void print();
};

CircularLL::CircularLL() { cursor = NULL; }

void CircularLL::addBeg(int d) {

  Node *temp = new Node(d);
  if (cursor == NULL) {
    cursor = temp;
    cursor->next = cursor;
  } else {
    temp->next = cursor->next;
    cursor->next = temp;
  }
}

void CircularLL::addX(int d, int y) {

  if (cursor == NULL)
    cout << "\nFirst Create a List";

  else {
    Node *s = cursor;
    while (s->next != cursor || s->data == y) {
      if (s->data == y) {
        Node *temp = new Node(d);
        temp->next = s->next;
        s->next = temp;
        return;
      } else
        s = s->next;
    }
  }

  cout << "\nThe element you entered is not is the list";
}

void CircularLL::addBack(int d) {

  Node *temp = new Node(d);

  if (cursor == NULL) {
    cursor = temp;
    cursor->next = cursor;
  }

  else {
    temp->next = cursor->next;
    cursor->next = temp;
    cursor = cursor->next;
  }
}

void CircularLL::remBeg() {

  if (cursor == NULL) {
    cout << "\nFirst Create a List";
    return;
  }

  if (cursor->next == cursor) {
    cursor = NULL;
    return;
  }

  else {
    Node *s = cursor->next;
    cursor->next = s->next;
    delete s;
    cout << "Removed at front" << endl;
  }
}

void CircularLL::remX(int d) {

  if (cursor == NULL) {
    cout << "\nFirst Create a List";
    return;
  }

  if (cursor->next == cursor) {
    cursor = NULL;
    return;
  }

  else {

    Node *s = cursor;
    while (s->next != cursor || s->next->data == d) {
      if (s->next->data == d) {
        s->next = s->next->next;
        s = s->next;
        delete s;
        return;
      } else
        s = s->next;
    }
  }

  cout << "\nThe element you entered is not in the list";
}

void CircularLL::remBack() {

  if (cursor == NULL) {
    cout << "\nFirst Create a List";
    return;
  }

  if (cursor->next == cursor) {
    cursor = NULL;
    return;
  }

  else {
    Node *s = cursor->next;
    while (s->next != cursor)
      s = s->next;

    s->next = cursor->next;
    delete cursor;
    cursor = s;
    cout << "The last element is removed" << endl;
  }
}

void CircularLL::search(int d) {

  if (cursor == NULL) {
    cout << "\nFirst create a list";
    return;
  }

  if (cursor->next == cursor) {
    if (cursor->data == d)
      cout << "\nFound at position 1";
    else {
      cout << "\nNot found";
      return;
    }
  }

  Node *s = cursor->next;
  int count = 1;
  do {
    if (s->data == d) {
      cout << "\nFound at position " << count;
      return;
    }
    count++;
    s = s->next;
  } while (s != cursor->next);
  cout << "\nNot found";
}

CircularLL CircularLL::operator+(CircularLL b) {

  CircularLL c;

  if (cursor == NULL) {
    return b;
  }

  if (b.cursor == NULL) {
    return *this;
  }

  Node *s = cursor->next;
  cursor->next = b.cursor->next;
  c.cursor = b.cursor;
  c.cursor->next = s;
  return c;
}

void CircularLL::input() {

  Node *s = cursor;

  cout << "\nEnter the size of list: ";
  int n;
  cin >> n;

  if (n <= 0)
    return;

  cout << "\nEnter " << n << " element: ";

  for (int i = 1; i <= n; i++) {
    int value;
    cin >> value;
    Node *temp = new Node(value);

    if (cursor == NULL) {
      cursor = temp;
      s = cursor;
      cursor->next = s;
    }

    else {
      cursor->next = temp;
      cursor = cursor->next;
      cursor->next = s;
    }
  }
}

void CircularLL::print() {

  cout << "\nThe Circular list is : ";

  if (cursor == NULL) {
    cout << "List empty";
  }

  else {
    Node *s = cursor->next;
    do {
      cout << s->data << "  ";
      s = s->next;
    } while (s != cursor->next);
  }
}

int main() {

  CircularLL a, b, r;
  int choice, d, y;
  cin.exceptions(std::ios::failbit);
  try {
    cout << "\nCircular linked list\n";
    a.input();
    a.print();
    do {
      cout << "\n\n1.Insert at front\n2.Insert at Back\n3.Insert after "
              "Y\n4.Remove at front\n5.Remove at Back\n6.Remove any "
              "element\n7.Search\n8.Concatenate\n\nEnter your choice : ";
      cin >> choice;
      switch (choice) {

      case 1:

        cout << "\nEnter the element to insert : ";
        cin >> d;
        a.addBeg(d);
        cout << "Inserted at beginning" << endl;
        a.print();
        break;

      case 2:

        cout << "\nEnter the element to insert at end : ";
        cin >> d;
        a.addBack(d);
        cout << "Inserted at end" << endl;
        a.print();
        break;

      case 3:

        cout << "\nEnter the element to insert after Y : ";
        cin >> d;
        cout << "\nEnter Y :  ";
        cin >> y;
        a.addX(d, y);
        a.print();
        break;

      case 4:

        a.remBeg();
        a.print();
        break;

      case 5:

        a.remBack();
        a.print();
        break;

      case 6:

        cout << "\nWhich element to remove : ";
        cin >> d;
        a.remX(d);
        a.print();
        break;

      case 7:

        cout << "\nEnter element to search : ";
        cin >> d;
        a.search(d);
        a.print();
        break;

      case 8:

        cout << "\nCreate another list for concatenation" << endl;
        b.input();
        cout << "\nThe first list is :-";
        a.print();
        cout << "\n\nThe second list is :-";
        b.print();
        r = a + b;
        cout << "\n\nThe concatenated list is :-";
        r.print();
        break;

      default:

        cout << "\nWrong input!!!";
        break;
      }
      cout << "\n\nEnter 1 for another choice : ";
      cin >> choice;
    } while (choice == 1);
  }

  catch (...) {
    cout << "\nillegel parameter entered...program will exit";
  }
}

