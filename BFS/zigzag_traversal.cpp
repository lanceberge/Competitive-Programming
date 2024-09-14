#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class TreeNode {
public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};

/*
traverse a binary tree in zig-zag order
*/
vector<vector<int>> traverse(TreeNode *root) {
  queue<TreeNode *> queue;
  vector<vector<int>> result;
  queue.push(root);

  bool leftToRight = true;
  while (!queue.empty()) {
    int levelSize = queue.size();
    vector<int> currentLevel(levelSize);

    for (int i = 0; i < levelSize; ++i) {
      TreeNode *cur = queue.front();
      queue.pop();

      int levelIndex = leftToRight ? i : levelSize - i - 1;
      currentLevel[levelIndex] = cur->val;

      if (cur->left != nullptr) {
        queue.push(cur->left);
      }

      if (cur->right != nullptr) {
        queue.push(cur->right);
      }

      leftToRight = !leftToRight;
    }
    result.push_back(currentLevel);
  }

  return result;
}

int main() {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  root->right->left->left = new TreeNode(20);
  root->right->left->right = new TreeNode(17);
  vector<vector<int>> res = traverse(root);

  for (auto vec : res) {
    for (auto num : vec) {
      cout << num << " ";
    }

    cout << endl;
  }

  return 0;
}
