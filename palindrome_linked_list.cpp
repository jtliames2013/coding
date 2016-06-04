#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <limits.h>
#include <math.h>
#include <iostream>
#include <sstream>

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

/**
 * Definition for an interval.
*/
 struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
 };

  // Definition for a point.
  struct Point {
       int x;
       int y;
       Point() : x(0), y(0) {}
       Point(int a, int b) : x(a), y(b) {}
  };

  class Solution {
  public:
      bool isPalindrome(ListNode* head) {
    	  ListNode *one=head, *two=head;
    	  ListNode *prev=NULL;
    	  while (two!=NULL && two->next!=NULL) {
    		  one=one->next;
    		  two=two->next->next;
    	  }

    	  // reverse from one
    	  while (one!=NULL) {
    		  ListNode *next=one->next;
    		  one->next=prev;
    		  prev=one;
    		  one=next;
    	  }

    	  ListNode *front=head, *back=prev;
    	  while (back!=NULL) {
    		  if (back->val!=front->val) return false;
    		  front=front->next;
    		  back=back->next;
    	  }
    	  return true;
      }
  };

int main()
{
	return 0;
}

