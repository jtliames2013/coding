274. H-Index 
Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, his h-index is 3.

Note: If there are several possible values for h, the maximum one is taken as the h-index.

Hint:

An easy approach is to sort the array first.
What are the possible values of h-index?
A faster approach is to use extra space.
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

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

使用长度为N + 1的数组cnts记录引用次数在0 ~ N（N篇以上的记为N）的文章个数

然后遍历cnts数组，计算h值的最大值

class Solution {
public:
    int hIndex(vector<int>& citations) {
    	int n=citations.size();
    	if (n==0) return 0;

    	vector<int> count(n+1);
    	for (int i=0; i<n; i++) {
    		if (citations[i]>n) {
    			count[n]++;
    		} else {
    			count[citations[i]]++;
    		}
    	}

    	int index;
    	int sum=0;
    	for (index=n; index>=0; index--) {
    		sum += count[index];
    		if (index <= sum) break;
    	}

    	return index;
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

