82. Remove Duplicates from Sorted List II  QuestionEditorial Solution  My Submissions
Total Accepted: 80840 Total Submissions: 291915 Difficulty: Medium
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

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
    ListNode* deleteDuplicates(ListNode* head) {
    	ListNode* curr=head;
    	ListNode* prev=NULL;
    	ListNode* next;
    	ListNode* newhead=NULL;
    	ListNode* temp;
    	bool isDup;

    	while(curr!=NULL) {
    		temp=NULL;
    		next=curr->next;
    		isDup=false;
    		while (next!=NULL && next->val==curr->val) {
				isDup=true;
				temp=curr;

				if (prev!=NULL) {
					prev->next=next;
				}

    			curr=curr->next;
    			next=curr->next;
    			delete temp;
    		}

    		if (isDup) {
    			if (prev!=NULL) {
    				prev->next=next;
    			}
    			temp=curr;
    		} else {
    			if (newhead==NULL) {
    				newhead=curr;
    			}

    			prev=curr;
    		}

    		curr=curr->next;
    		if (temp) delete temp;
    	}

    	return newhead;
    }
};

2.
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *newhead=NULL, *tail=NULL, *curr=head;
        while (curr!=NULL) {
            ListNode *n=curr->next;
            bool isDup=false;
            while (n!=NULL && n->val==curr->val) {
                isDup=true;
                n=n->next;
            }
            if (!isDup) {
                if (newhead==NULL) {
                    newhead=tail=curr;
                } else {
                    tail->next=curr;
                    tail=curr;
                }
            } else {
                for (ListNode *tmp=curr; tmp!=n; tmp=tmp->next) {
                    delete tmp;
                }
            }
            curr=n;
        }
        
        if (tail) tail->next=NULL;
        return newhead;
    }
};

int main()
{
	return 0;
}


