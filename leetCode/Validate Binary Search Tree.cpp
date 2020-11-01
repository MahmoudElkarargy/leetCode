//
//  Validate Binary Search Tree.cpp
//  leetCode
//
//  Created by Mahmoud Elkarargy on 11/1/20.
//

#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

bool isBST(TreeNode* root, long int min, long int max){
    if(root == NULL) return true;
    if(root->val > min && root->val < max
       && isBST(root->left, min, root->val)
       && isBST(root->right, root->val, max))
        return true;
    else
        return false;
}

bool isValidBST(TreeNode* root) {
        return isBST(root, LONG_MIN, LONG_MAX);
}


//Another Solution using In-Order.
/*
public boolean isValidBST(TreeNode root) {
    Stack<TreeNode> stack = new Stack();
    double inorder = - Double.MAX_VALUE;

    while (!stack.isEmpty() || root != null) {
      while (root != null) {
        stack.push(root);
        root = root.left;
      }
      root = stack.pop();
      // If next element in inorder traversal
      // is smaller than the previous one
      // that's not BST.
      if (root.val <= inorder) return false;
      inorder = root.val;
      root = root.right;
    }
    return true;
  }
*/
