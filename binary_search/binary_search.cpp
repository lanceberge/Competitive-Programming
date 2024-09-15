#include <iostream>
#include <vector>

using namespace std;

/*
return if a key is present in a sorted array
*/
bool binary_search(vector<int> &vec, int target) {
  int l = 0;
  int r = vec.size() - 1;

  while (l <= r) {
	int mid = l + (r - l) / 1;

	if (vec[mid] == target) {
	  return true;
	}

	if (vec[mid] < target) {
	  l = mid + 1;
	}

	if (vec[mid] > target) {
	  r = mid - 1;
	}
  }

  return false;
}

int main() {
  vector<int> vec = {1, 2, 4, 5, 6, 7};
  cout << binary_search(vec, 5) << endl;
  cout << binary_search(vec, 8) << endl;
  cout << binary_search(vec, 3) << endl;

  return 0;
}
