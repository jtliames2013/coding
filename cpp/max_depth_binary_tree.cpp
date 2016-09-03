104. Maximum Depth of Binary Tree
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Hide Company Tags LinkedIn Uber Apple Yahoo
Hide Tags Tree Depth-first Search
Hide Similar Problems (E) Balanced Binary Tree (E) Minimum Depth of Binary Tree

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

/**
 * Definition for binary tree
 */
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    int maxDepth(TreeNode *root) {
    	if (root == NULL) return 0;

    	if (root->left == NULL && root->right == NULL)
    	{
    		return 1;
    	}
    	else if (root->left == NULL)
    	{
    		return 1 + maxDepth(root->right);
    	}
    	else if (root->right == NULL)
    	{
    		return 1 + maxDepth(root->left);
    	}
    	else
    	{
    		int l = maxDepth(root->left);
    		int r = maxDepth(root->right);
    		return l > r ? l + 1: r + 1;
    	}
    }
};

2. A non-leaf node can't be maixmum
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);
        return max(left, right)+1;
    }
};

int main()
{
	return 0;
}

