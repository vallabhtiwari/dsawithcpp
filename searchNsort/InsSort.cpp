#include <iostream>
using namespace std;
class InsSort {
  int *arr, *arrt, n;

public:
  InsSort() {
    arr = arrt = 0;
    n = 0;
  }
  InsSort(int *a, int s) {
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

  void InsSortA() {
    int key = 0, i, j;
    arrt = new int[n];
    for (i = 0; i < n; i++)
      arrt[i] = arr[i];
    for (i = 1; i < n; i++) {
      key = arrt[i];
      j = i - 1;
      while (j >= 0 && arrt[j] > key) {
        arrt[j + 1] = arrt[j];
        j--;
      }
      arrt[j + 1] = key;
      cout << "After pass " << i << ":\n";
      print();
    }
  }
  void InsSortD() {
    int key = 0, i, j;
    arrt = new int[n];
    for (i = 0; i < n; i++)
      arrt[i] = arr[i];
    for (i = 1; i < n; i++) {
      key = arrt[i];
      j = i - 1;
      while (j >= 0 && arrt[j] < key) {
        arrt[j + 1] = arrt[j];
        j--;
      }
      arrt[j + 1] = key;
      cout << "After pass " << i << ":\n";
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
  InsSort s;
  int c = 0;
  s.input();
  do {
    cout << "1.Ascending order\n2.Descending order\n3.Print the orignal "
            "array\nEnter your choice: ";
    cin >> c;
    switch (c) {
    case 1:
      s.InsSortA();
      cout << "The array after sorting in ascending order:\n";
      s.print();
      break;
    case 2:
      s.InsSortD();
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
