109. Convert Sorted List to Binary Search Tree  QuestionEditorial Solution  My Submissions
Total Accepted: 76583 Total Submissions: 244580 Difficulty: Medium
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

Hide Company Tags Zenefits
Hide Tags Depth-first Search Linked List
Hide Similar Problems (M) Convert Sorted Array to Binary Search Tree

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>

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
    TreeNode *sortedListToBST(ListNode *head) {
    	if (head == NULL) return NULL;

    	ListNode *first=head, *second=head->next, *prev=NULL;
    	while (second!=NULL)
    	{
    		prev = first;
    		first = first->next;
    		second = second->next;
    		if(second!=NULL) second=second->next;
    	}

    	TreeNode *res = new TreeNode(first->val);
    	ListNode *before;
    	ListNode *after = first->next;

    	first->next=NULL;
    	if (prev!=NULL) { prev->next=NULL; before = head; }
    	else { before = NULL; }
    	res->left = sortedListToBST(before);
    	res->right = sortedListToBST(after);

    	return res;
    }
};

2.
class Solution {

public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head==NULL) return NULL;
        ListNode *l1=head, *l2=head, *prev=NULL;
        while (l2!=NULL&&l2->next!=NULL) {
            prev=l1;
            l1=l1->next;
            l2=l2->next->next;
        }
        
        TreeNode *res=new TreeNode(l1->val);
        if (l1==head) head=NULL;
        else prev->next=NULL;
        ListNode *next=l1->next;
        l1->next=NULL;
        TreeNode *l=sortedListToBST(head);
        TreeNode *r=sortedListToBST(next);
        res->left=l;
        res->right=r;

        return res;       
    }
};


int main()
{
	return 0;
}

