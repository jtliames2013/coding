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

 class LRUCache{
 public:
	 struct CacheEntry {
		 int key;
		 int value;
		 CacheEntry(int k, int v) : key(k), value(v) {}
	 };

	 map<int, list<CacheEntry>::iterator> m_hashtable;
	 list<CacheEntry> m_list;
	 int m_size;

     LRUCache(int capacity) {
    	 m_size=capacity;
     }

     int get(int key) {
    	 auto iter=m_hashtable.find(key);
    	 if (iter!=m_hashtable.end()) {
    		 if (iter->second!=m_list.begin()) {
    			 m_list.erase(iter->second);
    			 m_list.push_front(*iter->second);
    			 m_hashtable[key]=m_list.begin();
    		 }
    		 return m_hashtable[key]->value;
    	 } else {
    		 return -1;
    	 }
     }

     void set(int key, int value) {
    	 auto iter=m_hashtable.find(key);
		 if (iter!=m_hashtable.end()) {
			 if (iter->second!=m_list.begin()) {
				 m_list.erase(iter->second);
				 m_list.push_front(*iter->second);
				 m_hashtable[key]=m_list.begin();
			 }
			 m_list.begin()->value=value;
		 } else {
			 if (m_list.size()==m_size) {
				 CacheEntry entry=m_list.back();
				 m_hashtable.erase(entry.key);
				 m_list.pop_back();
			 }
			 CacheEntry newentry(key, value);
			 m_list.push_front(newentry);
			 m_hashtable[key]=m_list.begin();
		 }
     }
 };

int main()
{
	return 0;
}

