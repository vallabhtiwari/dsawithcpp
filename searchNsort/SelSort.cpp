#include <iostream>
using namespace std;
class SelSort {
  int *arr, *arrt, n;

public:
  SelSort() {
    arr = arrt = 0;
    n = 0;
  }
  SelSort(int *a, int s) {
    arr = a;
    n = s;
  }

  void input() {
    cout << "Enter the number of elements: ";
    cin >> n;
    arr = new int[n];
    cout << "Enter " << n << " array elements:\n";
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
  }

  void selsortA() {
    int p = 0, t = 0, i, j;
    arrt = new int[n];
    for (i = 0; i < n; i++)
      arrt[i] = arr[i];
    for (i = 0; i < n - 1; i++) {
      p = i;
      for (j = i + 1; j < n; j++)
        if (arrt[j] < arrt[p])
          p = j;
      if (p != i) {
        t = arrt[i];
        arrt[i] = arrt[p];
        arrt[p] = t;
      }
      cout << "After pass " << i + 1 << ":\n";
      print();
    }
  }
  void selsortD() {
    int p = 0, t = 0, i, j;
    arrt = new int[n];
    for (i = 0; i < n; i++)
      arrt[i] = arr[i];
    for (i = 0; i < n - 1; i++) {
      p = i;
      for (j = i + 1; j < n; j++)
        if (arrt[j] > arrt[p])
          p = j;
      if (p != i) {
        t = arrt[i];
        arrt[i] = arrt[p];
        arrt[p] = t;
      }
      cout << "After pass " << i + 1 << ":\n";
      print();
    }
  }
  void print() {

    for (int i = 0; i < n; i++)
      cout << arrt[i] << " ";
    cout << "\n";
  }
  void printO() {
    for (int i = 0; i < n; i++)
      cout << arr[i] << " ";
    cout << "\n";
  }
};

int main() {
  SelSort s;
  int c = 0;
  s.input();
  do {
    cout << "1.Ascending order\n2.Descending order\n3.Print the orignal "
            "array\nEnter your choice: ";
    cin >> c;
    switch (c) {
    case 1:
      s.selsortA();
      cout << "The array after sorting in ascending order:\n";
      s.print();
      break;
    case 2:
      s.selsortD();
      cout << "The array after sorting in descending order:\n";
      s.print();
      break;
    case 3:
      cout << "The orignal array is:\n";
      s.printO();
      break;
    default:
      cout << "\nWrong choice!! ";
      break;
    }
    cout << "\nEnter 1 for another choice: ";
    cin >> c;
  } while (c == 1);

  return 0;
}
