98. Validate Binary Search Tree 
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3

Binary tree [1,2,3], return false.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>
#include <limits.h>

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

/**
 * Definition for singly-linked list.
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

/**
 * Definition for undirected graph.
 * */
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

/**
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

1. pass min and max from top down

class Solution {
public:
	bool isValid(TreeNode *root, long long lower, long long upper)
	{
		if (root==NULL) return true;

		if (lower >= root->val || upper <= root->val) return false;

		return isValid(root->left, lower, root->val) && isValid(root->right, root->val, upper);
	}

    bool isValidBST(TreeNode *root) {
    	return isValid(root, LLONG_MIN, LLONG_MAX);
    }
};


2. return min and max from bottom up

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

    struct Element {

        bool res;

        int minVal;

        int maxVal;

    };



    Element isValid(TreeNode *root) {

        Element elem;

        elem.minVal=root->val;

        elem.maxVal=root->val;

        if (root->left) {

            Element e=isValid(root->left);

            if (e.res==false || root->val<=e.maxVal) {

                elem.res=false;

                return elem;

            }

            elem.minVal=e.minVal;

        }

        if (root->right) {

            Element e=isValid(root->right);

            if (e.res==false || root->val>=e.minVal) {

                elem.res=false;

                 return elem;

            }

            elem.maxVal=e.maxVal;

        }

        

        elem.res=true;

        return elem;

    }



    bool isValidBST(TreeNode* root) {

        if (root==NULL) return true;

        Element e=isValid(root);

        return e.res;

    }

};

int main()
{
	return 0;
}

