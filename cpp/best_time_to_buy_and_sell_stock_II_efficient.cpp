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
    int maxProfit(vector<int>& prices) {
    	int profit=0;

    	for (int i=1; i<prices.size(); i++) {
    		int diff = prices[i]-prices[i-1];
    		if (diff>0) profit+=diff;
    	}

    	return profit;
    }
};

2.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0;
        int n=prices.size();
        if (n==0) return 0;
        int bottom=prices[0], top=prices[0];
        int i=0;
        while (i<n-1) {
            while (i<n-1 && prices[i]>=prices[i+1]) i++;
            bottom=prices[i];
            while (i<n-1 && prices[i]<=prices[i+1]) i++;
            top=prices[i];
            maxprofit+=top-bottom;
        }
        
        return maxprofit;
    }
};

int main()
{
	return 0;
}


