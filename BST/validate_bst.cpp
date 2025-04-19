#include <climits>

class TreeNode {
public:
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class ValidateBST {
public:
  bool valid(TreeNode *node, long left, long right) {
    if (!node) {
      return true;
    }

    if (node->val <= left || node->val >= right) {
      return false;
    }

    return valid(node->left, left, node->val) &&
           valid(node->right, node->val, right);
  }

  bool isValidBST(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }

    return valid(root, LONG_MIN, LONG_MAX);
  }
};
