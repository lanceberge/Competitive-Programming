#include <iostream>
#include <vector>

using namespace std;

/*
  top-down dynamic programming to find the length of the longest increasing
  subsequence
*/
class LongestIncreasingSubsequence {
public:
  int length(const vector<int> &arr) {
    // begin with 1 as each element has at least 1 increasing subsequence len
    vector<int> dp = vector(arr.size(), 1);
    int maxLength = 1;

    // for each element:
    // The current subsequence length += the previous subsequence length if it's
    // increasing
    for (int i = 0; i < dp.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
          dp[i] = dp[j] + 1;
          maxLength = max(maxLength, dp[i]);
        }
      }
    }

    return maxLength;
  }
};

int main() {
  LongestIncreasingSubsequence longestIncreasingSubsequence;
  vector<int> sequence{5, 2, 8, 6, 3, 6, 9, 5};
  int result = longestIncreasingSubsequence.length(sequence);

  cout << result << "\n";

  return 0;
}
