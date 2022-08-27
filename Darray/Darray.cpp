/*
//  Dyanamic array implementation
//  By: Vallabh Tiwari
//  twitter: @vallabh__tiwari
//  linkdin: vallabhtiwari
*/

//================================================================================
// custom Exception class for handling bizzare situations
#include <iostream>
#include <iterator>
using namespace std;
class MyException {
public:
  MyException() {
    cout << "\nException occured !! Program will terminate...\n";
    exit(0);
  }
  MyException(string message) {
    cout << "\nException occured : " << message
         << ".\nProgram will terminate...\n";
    exit(0);
  }
};

//================================================================================
// class for Dyanamic array
template <typename T> //
class Darray {
  T *arr;       // Dyanamic array
  int len, cap; // length and capacity
  /*
    len : number of elements currently Darray contains
    cap : number of elements Darray can hold without resizing
  */

public:
  string name;
  Darray();
  Darray(const int);
  Darray(const int, const T);
  Darray(const Darray<T> &);
  Darray(const T *, const int);

  int capacity() const;
  int length() const;
  void resize(int);
  bool empty() const;

  T &operator[](int) const;
  Darray operator=(Darray);

  T back() const;
  T elemAt(int) const;
  T front() const;
  T *data() const;

  void push(T);
  T pop();
  void assign(const Darray<T>);
  void assign(const T *, int);
  void insertAt(const T, const int);
  void erase();
  void clear();
  void swap(Darray &);
};

//================================================================================
// default constructor for 0 capacity
template <typename T> //
Darray<T>::Darray() {
  arr = new T[0]();
  len = 0;
  cap = 0;
}

//================================================================================
// parameterized constructor with given capacity
template <typename T> //
Darray<T>::Darray(const int n) {
  if (cap < 0)
    throw MyException("Capacity cannot be negative");

  cap = n;
  arr = new T[cap]();
  len = 0; // no elements initially
}
//================================================================================
// parameterized constructor with given capacity and value
template <typename T> //
Darray<T>::Darray(const int n, const T elem) {
  if (cap < 0)
    throw MyException("Capacity cannot be negative");

  cap = n;
  arr = new T[cap]();
  for (len = 0; len < cap; len++) {
    arr[len] = elem;
  }
}
//================================================================================
// copy constructor with given Darray
template <typename T> //
Darray<T>::Darray(const Darray<T> &temp) {
  cap = temp.capacity();
  len = 0;

  arr = new T[cap]();
  while (len < temp.length()) {
    arr[len] = temp[len];
    len++;
  }
}

//================================================================================
// constructor to initialize from a static array
template <typename T> //
Darray<T>::Darray(const T *p, const int n) {
  if (cap < 0)
    throw MyException("Capacity cannot be negative");

  cap = n;
  arr = new T[cap]();
  for (len = 0; len < cap; len++) {
    arr[len] = p[len];
  }
}

//================================================================================
// operator[] for getting or storing elements
template <typename T> //
T &Darray<T>::operator[](int index) const {
  if (empty())
    throw MyException("Darray is empty");
  if (index < 0 || index > len - 1)
    throw MyException("Invalid index. Index should be in range 0 to length-1");

  return arr[index];
}

//================================================================================
// operator = for assignment
template <typename T> //
Darray<T> Darray<T>::operator=(const Darray<T> temp) {
  cap = temp.capacity();
  arr = new T[cap]();

  for (len = 0; len < temp.length(); len++) {
    arr[len] = temp[len];
  }
  return *this;
}
//================================================================================
// to check if Darray is empty
template <typename T> //
bool Darray<T>::empty() const {
  return len < 1;
}

//================================================================================
// push elements at the end
template <typename T> //
void Darray<T>::push(T element) {
  if (len == cap)
    resize(cap + (cap / 2) + 1); // resizing the array
  // +1 to ensure arrays of size 0 or 1 are also resized ;-)

  arr[len] = element;
  len++;
}

//================================================================================
// remove and gives the last element of Darray
template <typename T> //
T Darray<T>::pop() {
  if (empty())
    throw MyException("Darray is empty");

  return arr[--len];
}

//================================================================================
// inset an element T at given index
template <typename T> //
void Darray<T>::insertAt(const T elem, const int index) {
  if (index < 0)
    throw MyException("Invalid index. Index cannot be negative.");
  if (index > cap - 1)
    throw MyException("Index out of bounds.\nPlease resize the array first or "
                      "use Darray::push()");

  arr[index] = elem;
  if (index > len - 1)
    len = index + 1;
}

//================================================================================
// gives the last element of Darray
template <typename T> //
T Darray<T>::back() const {
  if (empty())
    throw MyException("Darray is empty");

  return arr[len - 1];
}

//================================================================================
// gives the first element of Darray
template <typename T> //
T Darray<T>::front() const {
  if (empty())
    throw MyException("Darray is empty");

  return arr[0];
}

//================================================================================
// gives element at pos
template <typename T> //
T Darray<T>::elemAt(int index) const {
  if (empty())
    throw MyException("Darray is empty");
  if (index < 0 || index > len - 1)
    throw MyException("Invalid index. Index should be in range 0 to length-1");

  return arr[index];
}

//================================================================================
// length gives number of elements currently present in the array
template <typename T> //
int Darray<T>::length() const {
  return len;
}

//================================================================================
// capacity gives total capacity of the array
template <typename T> //
int Darray<T>::capacity() const {
  return cap;
}

//================================================================================
// returns a pointer to first element of Darray
template <typename T> //
T *Darray<T>::data() const {
  if (empty())
    return NULL;

  return arr;
}

//================================================================================
// resize the array to given size
template <typename T> //
void Darray<T>::resize(int newSize) {

  if (newSize < 0)
    throw MyException("Size cannot be negative");

  if (newSize == cap) // no need to resize
    return;

  T *temp; // temp array to hold the elements temporarily
  int t;   // t holds the number of elements to be copied in the resized Darray

  if (newSize < len) {
    t = newSize;
    temp = new T[newSize]();

    // copying to temp,new size is less, some elements will be lost
    for (int i = 0; i < t; i++) {
      temp[i] = arr[i];
    }
  } else {
    t = len;
    temp = new T[len]();

    // copying all the elements from original array to temp
    for (int i = 0; i < t; i++) {
      temp[i] = arr[i];
    }
  }

  arr = new T[newSize](); // resizing the Darray

  // copying elements from temp to original Darray
  for (int i = 0; i < t; i++) {
    arr[i] = temp[i];
  }
  cap = newSize;
  len = t;
}

//================================================================================
// assign a new Darray to current Darray
template <typename T> //
void Darray<T>::assign(const Darray<T> temp) {
  // calling the = operator to assign current Darray with temp
  *this = temp;
}

//================================================================================
// assign a new array to current Darray
template <typename T> //
void Darray<T>::assign(const T *temp, int n) {

  for (int i = 0; i < n; i++) {
    insertAt(temp[i], i);
  }
}

//================================================================================
// erase the data in Darray
template <typename T> //
void Darray<T>::erase() {
  arr = new T[cap]();
  len = 0;
}

//================================================================================
// erasr the data and set deallocate the memory
template <typename T> //
void Darray<T>::clear() {
  arr = new T[]();
  len = cap = 0;
}

//================================================================================
// swap contents of current Darray with another Darray
template <typename T> //
void Darray<T>::swap(Darray<T> &another) {
  Darray<T> temp;
  temp = *this;
  *this = another;
  another = temp;
}

//=====================================================================
int main(int argc, char *argv[]) {

  // write main function as per your need to test the Darray methods

  Darray<char> a(6);
  a.push('A');
  a.push('B');
  a.push('C');
  a.push('D');
  for (int i = 0; i < a.length(); i++) {
    cout << a[i] << " ";
  }
  cout << a.length() << " " << a.capacity() << endl;

  a.push('E');
  a.push('F');
  a.push('G');
  a.push('H');
  for (int i = 0; i < a.length(); i++) {
    cout << a[i] << " ";
  }
  cout << a.length() << " " << a.capacity() << endl;

  Darray<char> b(10);
  char c[10] = {'P', 'Q', 'R', 'S', 'T', 'U'};
  b.assign(c, 3);
  for (int i = 0; i < b.length(); i++) {
    cout << b[i] << " ";
  }
  cout << b.length() << " " << b.capacity() << endl;

  a[0] = '*';
  a.swap(b);
  // b = a;
  a.insertAt('&', 2);
  for (int i = 0; i < a.length(); i++) {
    cout << a[i] << " ";
  }
  cout << a.length() << " " << a.capacity() << endl;

  for (int i = 0; i < b.length(); i++) {
    cout << b[i] << " ";
  }
  cout << b.length() << " " << b.capacity() << endl;

  a.push('F');
  a.push('G');
  a.push('H');
  for (int i = 0; i < b.length(); i++) {
    cout << b[i] << " ";
  }
  cout << b.length() << " " << b.capacity() << endl;

  return 0;
}
