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
    ListNode* swapPairs(ListNode* head) {
    	if (head==NULL) return NULL;
    	if (head->next==NULL) return head;

    	ListNode* node=head;
    	ListNode* prev=NULL;
    	ListNode* next=NULL;
    	while(node != NULL)
    	{
    		if (node->next==NULL) {
    			break;
    		} else {
    			next = node->next->next;
    			if(prev==NULL){
    				head=node->next;
    			} else {
    				prev->next=node->next;
    			}

				node->next->next=node;
				node->next=next;

				prev=node;
    			node = next;
    		}
    	}

    	return head;
    }
};

int main()
{
	return 0;
}

