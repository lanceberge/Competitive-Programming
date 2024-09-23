#include <iostream>
#include <vector>

using namespace std;

class Merge {

public:
  void mergeSort(vector<int> &arr) {
	mergeSortRecursive(arr, 0, arr.size() - 1);
  }

private:
  void mergeSortRecursive(vector<int> &arr, int l, int r) {
	if (l >= r) {
	  return;
	}

	int mid = l + (r - l) / 2;
	mergeSortRecursive(arr, l, mid);
	mergeSortRecursive(arr, mid + 1, r);
	merge(arr, l, r, mid);
  }

  void merge(vector<int> &arr, int l, int r, int mid) {
	int n1 = mid - l + 1;
	int n2 = r - mid;

	// Create temp vectors
	vector<int> L(n1), R(n2);
	for (int i = 0; i < n1; i++) {
	  L[i] = arr[l + i];
	}

	for (int j = 0; j < n2; j++) {
	  R[j] = arr[mid + 1 + j];
	}

	int i = 0, j = 0;
	int k = l;

	// merge temp vectors
	while (i < n1 && j < n2) {
	  if (L[i] <= R[j]) {
		arr[k] = L[i];
		i++;
	  } else {
		arr[k] = R[j];
		j++;
	  }
	  k++;
	}

	// Copy the remaining elements
	while (i < n1) {
	  arr[k] = L[i];
	  i++;
	  k++;
	}

	while (j < n2) {
	  arr[k] = R[j];
	  j++;
	  k++;
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
