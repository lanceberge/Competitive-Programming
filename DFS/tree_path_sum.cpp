#include <iostream>

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
  Return if there is a tree path with a sum equal to SUM
*/
bool DFS(TreeNode *root, int sum) {
  if (root == nullptr) {
    return false;
  }

  if (root->val == sum && root->left == nullptr && root->right == nullptr) {
    return true;
  }

  return DFS(root->left, sum - root->val) || DFS(root->right, sum - root->val);
}

int main() {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);

  cout << DFS(root, 23) << endl;
  cout << DFS(root, 16) << endl;

  return 0;
}
