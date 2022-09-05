#include <iostream>
using namespace std;
class BubSort {
  int *arr, *arrt, n;

public:
  BubSort() {
    arr = arrt = 0;
    n = 0;
  }
  BubSort(int *a, int s) {
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
    cout << endl;
  }

  void BubSortA() {
    arrt = new int[n];
    int t = 0, i, j;
    for (i = 0; i < n; i++)
      arrt[i] = arr[i];
    bool b;
    for (i = 0; i < n - 1; i++) {
      b = true;
      for (j = 0; j < n - i - 1; j++)
        if (arrt[j] > arrt[j + 1]) {
          b = false;
          t = arrt[j];
          arrt[j] = arrt[j + 1];
          arrt[j + 1] = t;
        }
      cout << "After pass " << i + 1 << ":\n";
      print();
      if (b)
        break;
    }
  }
  void BubSortD() {
    arrt = new int[n];
    int t = 0, i, j;
    for (i = 0; i < n; i++)
      arrt[i] = arr[i];
    bool b;
    for (i = 0; i < n - 1; i++) {
      b = true;
      for (j = 0; j < n - i - 1; j++)
        if (arrt[j] < arrt[j + 1]) {
          b = false;
          t = arrt[j];
          arrt[j] = arrt[j + 1];
          arrt[j + 1] = t;
        }
      cout << "After pass " << i + 1 << ":\n";
      print();
      if (b)
        break;
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
  BubSort s;
  int c = 0;
  s.input();
  do {
    cout << "1.Ascending order\n2.Descending order\n3.Print the orignal "
            "array\nEnter your choice: ";
    cin >> c;
    cout << endl;
    switch (c) {
    case 1:
      s.BubSortA();
      cout << "The array after sorting in ascending order:\n";
      s.print();
      break;
    case 2:
      s.BubSortD();
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
