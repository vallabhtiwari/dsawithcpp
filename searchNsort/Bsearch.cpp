#include <iostream>
using namespace std;

int Search(int *p, int l, int r, int elem) {
  int mid;
  if (r >= l) {
    mid = (l + (r)) / 2;

    if (p[mid] == elem)
      return mid;

    else if (elem > p[mid])
      return Search(p, mid + 1, r, elem);

    else
      return Search(p, l, mid - 1, elem);
  }
  return -1;
}

int main() {
  int elem, *p, n;
  cout << "Enter the total no of elements: ";
  cin >> n;
  p = new int[n];
  cout << "\n\nEnter the elements in ascending order: ";
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  cout << "\n\nEnter the element to be searched: ";
  cin >> elem;
  int index = Search(p, 0, n - 1, elem);
  if (index == -1)
    cout << "\n\nElement not found!!!!";
  else
    cout << "\n\nElement found at index " << index + 1;
  cout << endl;
  return 0;
}
