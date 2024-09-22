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
    for (int mergeSize = 1; mergeSize < arr.size(); mergeSize *= 2) {
      // For each subarray
      for (int i = 0; i < arr.size(); i += 2 * mergeSize) {
        merge(arr, i, mergeSize);
      }
    }
  }

private:
  void merge(vector<int> &arr, int startIdx, int mergeSize) {
    int l_start = startIdx;
    int r_start = startIdx + mergeSize;

    int insertedIdx = startIdx;
    for (int i = 0; i < mergeSize * 2; ++i) {
      if (arr[l_start] <= arr[r_start]) {
        arr[insertedIdx] = arr[l_start];
        l_start += 1;
      }

      else {
        arr[insertedIdx] = arr[r_start];
        r_start += 1;
      }
    }
  }
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
