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

NOTE: [1 1 1 2 2 3]. need to check elements before "end" to see if there is duplicate

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	if (nums.size()==0 || nums.size()==1) return nums.size();
    	int end=2;

    	for (int i=2; i<nums.size(); i++) {
    		if ((nums[i] != nums[i-1]) ||
    			(nums[i] != nums[i-2]) ||
    			(nums[end-1] != nums[end-2])) {
    			nums[end] = nums[i];
    			end++;
    		}
    	}

    	return end;
    }
};

int main()
{
	return 0;
}


