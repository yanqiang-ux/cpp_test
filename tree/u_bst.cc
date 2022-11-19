#include <vector>
#include <iostream>

struct TreeNode {
  TreeNode* left;
  TreeNode* right;
  int val = -1;

  TreeNode (int v) {
    val = v;
  }
};

vector<TreeNode*> generate_trees(int start, int end) {
  std::vector<TreeNode*> subtrees;
  if (start > end) {
    subtrees.push_back(nullptr);
    return subtrees;
  }
  for (int k = start; k < end; k++) {
    std::vector<TreeNode*> lsubt = generate_trees(start, k-1);
    std::vector<TreeNode*> rsubt = generate_trees(k+1, end);
    for (auto i : lsubt) {
      for (auto j : rsubt) {
        TreeNode* t = new TreeNode(k);
        t->left = i;
        t->right = j;
        subtrees.push_back(t);
      }
    }
  }
  return subtrees;
}

std::vector<TreeNode*> generate_trees(int n) {

}

int main () {

}


