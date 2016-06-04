#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
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

/**
 * Definition for an interval.
*/
 struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
 };

 class MedianFinder {
 public:
	 priority_queue<int> small;
	 priority_queue<int, vector<int>, greater<int>> large;

     // Adds a number into the data structure.
     void addNum(int num) {
    	 if (!large.empty() && num > large.top()) {
    		 large.push(num);
    	 } else {
    		 small.push(num);
    	 }

    	 if (small.size() > large.size()+1) {
    		 large.push(small.top());
    		 small.pop();
    	 } else if (large.size() > small.size()+1) {
    		 small.push(large.top());
    		 large.pop();
    	 }
     }

     // Returns the median of current data stream
     double findMedian() {
    	 if (small.size()==large.size()) return (small.top()+large.top())/2.0;
    	 else if (small.size()>large.size()) return small.top();
    	 else return large.top();
     }
 };

 // Your MedianFinder object will be instantiated and called as such:
 // MedianFinder mf;
 // mf.addNum(1);
 // mf.findMedian();

int main()
{
	return 0;
}

