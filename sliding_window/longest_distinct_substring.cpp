#include <iostream>
#include <iterator>
#include <string>
#include <unordered_map>

using namespace std;

/*
Get the length of the longest substring with K distinct characters
*/
int find_longest_distinct_substring_length(const string &str, int K) {
  int max_substring_length = 0;

  // Keep track of the count of the distinct elements in the current subarray
  unordered_map<char, int> charToCount;

  int l = 0;
  int maxLength = 0;
  for (int r = 0; r < str.length(); ++r) {
    charToCount[str[r]]++;

    // advance the left pointer until we're within K distinct chars
    while (charToCount.size() > K) {
      char c = str[l];
      charToCount[c]--;

      if (charToCount[c] == 0) {
        charToCount.erase(c);
      }

      ++l;
    }

    maxLength = max(maxLength, r - l + 1);
  }

  return maxLength;
}

int main() {
  int result = find_longest_distinct_substring_length("araaci", 1);

  cout << result << endl;

  return 0;
}
