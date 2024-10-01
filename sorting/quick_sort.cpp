#include <iostream>
#include <vector>

using namespace std;

class QuickSort {
public:
  /*
    Choose pivots from end to start
    Increment r until it's less than our pivot
    Then swap with l and increment

    Then increment l, this is the pivot position

    Then, quick sort the half below and above the pivot
  */
  void quickSort(vector<int> &arr) { quickSort(arr, 0, arr.size() - 1); }

private:
  void quickSort(vector<int> &arr, int start, int end) {
    if (end <= start) {
      return;
    }

    int pivot = partition(arr, start, end);
    quickSort(arr, start, pivot - 1);
    quickSort(arr, pivot + 1, end);
  }

  int partition(vector<int> &arr, int start, int end) {
    int pivot = arr[end];

    int l = start - 1;
    for (int r = start; r < end; ++r) {
      if (arr[r] < pivot) {
        ++l;
        swap(arr, l, r);
      }
    }

    ++l;
    swap(arr, l, end);
    return l;
  }

  void swap(vector<int> &arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
};

int main() {
  QuickSort quickSort;
  vector<int> arr{12, 7, 1, 5, 9, 4};
  quickSort.quickSort(arr);

  for (auto x : arr) {
    cout << x << " ";
  }
  cout << "\n";

  return 0;
}
