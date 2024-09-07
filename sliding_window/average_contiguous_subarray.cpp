#include <iostream>
#include <stdexcept>
#include <vector>

/*
Find the average of all contiguous subarrays in arr
*/

using namespace std;

vector<double> findAverages(int K, const vector<int> &arr) {
  double sum = 0;
  vector<double> result(arr.size() - K + 1);
  int l = 0;
  int r = 0;

  if (K > arr.size()) {
    throw invalid_argument("K cannot be larger than arr.size");
  }

  for (r = 0; r < K; ++r) {
    sum += arr[r];
  }

  result[0] = sum / K;

  for (int i = 1; i < result.size(); ++i) {
    sum -= arr[l];
    sum += arr[r];

    l += 1;
    r += 1;

    result[i] = sum / K;
  }

  return result;
}

int main() {
  vector<double> result =
      findAverages(5, vector<int>{1, 3, 2, 6, -1, 4, 1, 8, 2});

  for (auto &num : result) {
    cout << num << " ";
  }

  cout << endl;
  return 0;
}
