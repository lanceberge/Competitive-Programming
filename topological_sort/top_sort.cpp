#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/*
  DFS to traverse the tree, saving a visited list. Push to a stack on the
  recursive callback
*/
class TopSort {
public:
  stack<int> topSort(const vector<vector<int>> &adj) {
    vector<bool> visited(adj.size(), false);
    stack<int> stack;

    for (int i = 0; i < adj.size(); ++i) {
      if (!visited[i]) {
        dfs(adj, visited, stack, i);
      }
    }

    return stack;
  }

private:
  void dfs(const vector<vector<int>> &adj, vector<bool> &visited,
           stack<int> &stack, int idx) {
    visited[idx] = true;

    for (int i : adj[idx]) {
      if (!visited[i]) {
        dfs(adj, visited, stack, i);
      }
    }

    stack.push(idx);
  }
};

int main() {
  TopSort topSort;
  vector<vector<int>> edges = {{0, 1}, {1, 2}, {3, 1}, {3, 2}};

  // Adjacency list
  vector<vector<int>> adj(edges.size());
  for (auto i : edges) {
    adj[i[0]].push_back(i[1]);
  }

  stack<int> result = topSort.topSort(adj);
  while (!result.empty()) {
    cout << result.top() << "\n";
    result.pop();
  }

  return 0;
}
