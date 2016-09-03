#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <limits.h>
#include <math.h>

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

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
    	vector<int> res;
    	stack<TreeNode*> stk;
    	TreeNode* lastVisited=NULL;
    	TreeNode* n=root;

    	while (!stk.empty() || n!=NULL) {
    		if (n!=NULL) {
    			stk.push(n);
    			n=n->left;
    		} else {
    			TreeNode* peek = stk.top();
    			if (peek->right!=NULL && peek->right!=lastVisited) {
    				n=peek->right;
    			} else {
    				res.push_back(peek->val);
    				lastVisited=peek;
    				stk.pop();
    			}
    		}
    	}

    	return res;
    }
};

int main()
{
	return 0;
}


