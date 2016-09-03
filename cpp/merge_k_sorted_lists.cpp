23. Merge k Sorted Lists 
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

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
	class Compare {
	public:
		bool operator()(ListNode *n1, ListNode *n2) {
			return n1->val>n2->val;
		}
	};

    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	priority_queue<ListNode*, vector<ListNode*>,  Compare> pq;
    	ListNode *head=NULL,*tail=NULL;
    	for (int i=0; i<lists.size(); i++) {
    		if (lists[i]!=NULL) pq.push(lists[i]);
    	}

    	while (!pq.empty()) {
    		ListNode* t=pq.top();
    		if (head==NULL) {
    			head=tail=t;
    		} else {
    			tail->next=t;
    			tail=t;
    		}

    		if (t->next!=NULL) {
    			pq.push(t->next);
    		}
    		pq.pop();
    	}

    	return head;
    }
};

int main()
{
	return 0;
}

