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
#include <unordered_map>
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
      vector<int> twoSum(vector<int>& nums, int target) {
          vector<int> res;
          int size=nums.size();
          if (size==0) return res;
          vector<pair<int, int>> v;
          for (int i=0; i<size; i++) {
              v.push_back(make_pair(nums[i], i));
          }

          sort(v.begin(), v.end(), [](pair<int,int> a, pair<int,int> b) { return a.first<b.first; } );
          int l=0, r=size-1;
          while (l<r) {
              if (v[l].first+v[r].first==target) {
                  res.push_back(v[l].second);
                  res.push_back(v[r].second);
                  return res;
              } else if (v[l].first+v[r].first>target) {
                  r--;
              } else {
                  l++;
              }
          }

          return res;
      }
  };

int main()
{
	return 0;
}
