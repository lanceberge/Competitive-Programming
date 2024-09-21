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
    return knapsackRecursive(weights, profits, C, 0);
  }

private:
  /*
    Brute Force Solution:
    At every index, do a recursive call both excluding and including the
    current index. Thus we get the profit of every subset
  */
  int knapsackRecursive(const vector<int> &weights, const vector<int> &profits,
                        int C, int idx) {
    if (C <= 0 || idx >= weights.size()) {
      return 0;
    }

    int inclusiveProfit =
        weights[idx] <= C
            ? profits[idx] +
                  knapsackRecursive(profits, weights, C - weights[idx], idx + 1)
            : 0;

    int exclusiveProfit = knapsackRecursive(profits, weights, C, idx + 1);

    return max(inclusiveProfit, exclusiveProfit);
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
