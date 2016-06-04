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
	struct Node {
		unordered_set<int> neighbors;
	};

    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    	// [0, 1] 0 ---> 1
    	vector<Node> graphIncoming(numCourses);
    	vector<Node> graphOutgoing(numCourses);

    	for (auto p:prerequisites) {
    		graphOutgoing[p.first].neighbors.insert(p.second);
    		graphIncoming[p.second].neighbors.insert(p.first);
    	}

    	vector<int> sorted;
    	unordered_set<int> s;
    	for (int i=0; i<graphIncoming.size(); i++) {
    		if (graphIncoming[i].neighbors.size()==0) {
    			s.insert(i);
    		}
    	}

    	while (!s.empty()) {
    		int n=*s.begin();
    		sorted.push_back(n);
    		s.erase(s.begin());

    		for (auto it=graphOutgoing[n].neighbors.begin(); it!=graphOutgoing[n].neighbors.end(); it++) {
    			graphIncoming[*it].neighbors.erase(n);
    			if (graphIncoming[*it].neighbors.size()==0) {
    				s.insert(*it);
    			}
    		}
    		graphOutgoing[n].neighbors.clear();
    	}

    	for (int i=0; i<graphIncoming.size(); i++) {
    		if (graphIncoming[i].neighbors.size()>0) return false;
    	}

    	return true;
    }
};

int main()
{
	return 0;
}


