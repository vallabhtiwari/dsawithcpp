#include <iostream>
using namespace std;
class Lsearch {
  int *p, n;

public:
  Lsearch() {
    p = 0;
    n = 0;
  }
  Lsearch(int n) { p = new int[n]; }

  void input() {
    cout << "Enter the total no of elements: ";
    cin >> n;
    p = new int[n];
    cout << "\n\nEnter the elements: ";
    for (int i = 0; i < n; i++) {
      cin >> p[i];
    }
  }

  int sElem() {
    int elem, flag = 0, i;
    cout << "\n\nEnter the element to be searched: ";
    cin >> elem;
    for (i = 0; i < n; i++) {
      if (p[i] == elem) {
        flag = 1;
        break;
      }
    }
    if (flag == 1)
      return i + 1;
    else
      return -1;
  }
} s;

int main() {
  s.input();
  int index = s.sElem();
  if (index == -1)
    cout << "\n\nElement not found!!!!";
  else
    cout << "\n\nElement found at index " << index;
  cout << endl;
  return 0;
}
