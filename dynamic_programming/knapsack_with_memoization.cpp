#include <iostream>
#include <vector>

using namespace std;

/*
  Given the weights and profits of N items, we put them into a knapsack with
  capacity C.
  Select the subset of elements < capacity C with maximum profit
*/
class Knapsack {

public:
  int knapsack(const vector<int> &weights, const vector<int> &profits, int C) {
    vector<vector<int>> dp(profits.size(), vector<int>(C, -1));
    return knapsackRecursive(dp, weights, profits, C, 0);
  }

private:
  /*
    At every index, do a recursive call both excluding and including the
    current index. Thus we get the profit of every subset. We save
    Time Complexity: N * C
  */
  int knapsackRecursive(vector<vector<int>> &dp, const vector<int> &weights,
                        const vector<int> &profits, int C, int idx) {
    if (C <= 0 || idx >= weights.size()) {
      return 0;
    }

    int inclusiveProfit =
        weights[idx] <= C
            ? profits[idx] + knapsackRecursive(dp, profits, weights,
                                               C - weights[idx], idx + 1)
            : 0;

    int exclusiveProfit = knapsackRecursive(dp, profits, weights, C, idx + 1);

    int currentMax = max(inclusiveProfit, exclusiveProfit);
    dp[idx][C] = currentMax;
    return currentMax;
  }
};

int main() {
  vector<int> profits = {1, 6, 10, 16};
  vector<int> weights = {1, 2, 3, 5};

  Knapsack ks;
  cout << ks.knapsack(profits, weights, 7) << "\n";
  cout << ks.knapsack(profits, weights, 6) << "\n";

  return 0;
}
