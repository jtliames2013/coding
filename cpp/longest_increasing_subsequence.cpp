300. Longest Increasing Subsequence 
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?


动态规划（Dynamic Programming）

状态转移方程：

dp[x] = max(dp[x], dp[y] + 1) 其中 y < x 并且 nums[x] > nums[y]

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
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if (n==0) return 0;
        vector<int> dp(n,1);
        int res=0;
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<i; j++) {
                if (nums[i]>nums[j] && dp[j]+1>dp[i]) {
                    dp[i]=dp[j]+1;
                }
            }
            
            res=max(res, dp[i]);
        }
        
        return res;
    }
};

2. Initialize to 0 and use n+1 arrary
class Solution {

public:

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if (n==0) return 0;
        vector<int> dp(n+1, 0);

        for (int i=1; i<=n; i++) {
            for (int j=0; j<i; j++) {
                if (j==0 || nums[j-1]<nums[i-1]) {
                    dp[i]=max(dp[i], dp[j]+1);
                }
            }
        }

        int res=0;
        for (int i=1; i<=n; i++) {
            if (res<dp[i]) res=dp[i];
        }

        return res;
    }
};


int main()
{
	return 0;
}


