323. Number of Connected Components in an Undirected Graph 
 Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.

Example 1:

     0          3
     |          |
     1 --- 2    4

Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.

Example 2:

     0           4
     |           |
     1 --- 2 --- 3

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.

Note:
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges. 

NOTE: use BFS

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
	  void bfs(int start, map<int, set<int> >& graph, unordered_set<int>& visited)
	  {
		  queue<int> q;
		  q.push(start);
		  visited.insert(start);

		  while (!q.empty()) {
			  int i=q.front();
			  q.pop();

			  for (auto n:graph[i]) {
				  if (visited.find(n)==visited.end()) {
					  q.push(n);
					  visited.insert(n);
				  }
			  }
		  }
	  }

      int countComponents(int n, vector<pair<int, int>>& edges) {
    	  map<int, set<int> > graph;
    	  unordered_set<int> visited;
    	  int components=0;
    	  for (int i=0; i<edges.size(); i++) {
    		  graph[edges[i].first].insert(edges[i].second);
    		  graph[edges[i].second].insert(edges[i].first);
    	  }

    	  for (int i=0; i<n; i++) {
    		  if (visited.find(i)==visited.end()) {
    			  components++;
    			  bfs(i, graph, visited);
    		  }
    	  }

    	  return components;
      }
  };

2. use vector instead of map
class Solution {

public:

    int countComponents(int n, vector<pair<int, int>>& edges) {

        int count=0;

        vector<unordered_set<int>> graph(n);

        unordered_set<int> visited;

        for (auto e:edges) {

            graph[e.first].insert(e.second);

            graph[e.second].insert(e.first);

        }

        

        for (int i=0; i<n; i++) {

            if (visited.find(i)==visited.end()) {

                count++;

                

                queue<int> q;

                q.push(i);

                visited.insert(i);

                while (!q.empty()) {

                    int v=q.front();

                    q.pop();

                    

                    for (auto neighbor:graph[v]) {

                        if (visited.find(neighbor)==visited.end()) {

                            q.push(neighbor);

                            visited.insert(neighbor);

                        }

                    }

                }

            }    

        }

        

        return count;

    }

};

int main()
{
	return 0;
}

