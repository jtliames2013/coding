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

class Solution {
public:
    int hIndex(vector<int>& citations) {
    	int n=citations.size();
    	if (n==0) return 0;

    	int l=0, r=n-1;
    	int m;
    	while (l<=r) {
    		m=l+(r-l)/2;
    		if (citations[m] < n-m) {
    			l=m+1;
    		} else {
    			r=m-1;
    		}
    	}

    	return n-l;
    }
};

int main()
{
	vector<int> v;
	v.push_back(0);
	Solution s;
	s.hIndex(v);
	return 0;
}

