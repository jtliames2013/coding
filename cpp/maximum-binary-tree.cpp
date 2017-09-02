654. Maximum Binary Tree
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

The root is the maximum number in the array.
The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
Construct the maximum tree by the given array and output the root node of this tree.

Example 1:
Input: [3,2,1,6,0,5]
Output: return the tree root node representing the following tree:

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1
Note:
The size of the given array will be in the range [1,1000].

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* dfs(vector<int>& nums, int start, int end) {
        if (start>end) return NULL;
        int maxVal=INT_MIN, idx=-1;
        for (int i=start; i<=end; i++) {
            if (nums[i]>maxVal) {
                maxVal=nums[i];
                idx=i;
            }
        }
        TreeNode* n=new TreeNode(maxVal);
        n->left=dfs(nums, start, idx-1);
        n->right=dfs(nums, idx+1, end);
        return n;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n=nums.size();
        if (n==0) return NULL;
        return dfs(nums, 0, n-1);
    }
};

