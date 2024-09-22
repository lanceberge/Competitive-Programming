#include <iostream>
#include <vector>

using namespace std;

/*
  Iterative, bottom-up merge sort
*/
class Merge {

public:
  void mergeSort(vector<int> &arr) {
    // For each merge size
    for (int mergeSize = 2; mergeSize < arr.size(); mergeSize *= 2) {
      // For each subarray
      for (int i = 0; i < arr.size(); i += mergeSize) {
        merge(arr, i, mergeSize);
      }
    }
  }

private:
  void merge(vector<int> &arr, int i, int mergeSize) {}
};

int main() {
  vector<int> arr{12, 7, 1, 5, 9, 4};
  Merge merge;
  merge.mergeSort(arr);

  for (auto x : arr) {
    cout << x << " ";
  }
  cout << "\n";

  return 0;
}
