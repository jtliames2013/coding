74. Search a 2D Matrix 
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.

Hide Tags Array Binary Search
Hide Similar Problems (M) Search a 2D Matrix II

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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    	int row=matrix.size();
    	if (row==0) return false;
    	int col=matrix[0].size();
    	if (col==0) return false;

    	int i, j;
    	for (i=0; i<row; i++) {
    		if (matrix[i][0]==target) {
    			return true;
    		} else if(matrix[i][0]>target) {
    			break;
    		}
    	}

    	if (i==0) return false;
    	for (j=0; j<col; j++) {
    		if (matrix[i-1][j]==target) return true;
    	}

    	return false;
    }
};

2.
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        if (m==0) return false;
        int n=matrix[0].size();
        if (n==0) return false;
        
        int i=0, j=n-1;
        while (i<m && j>=0) {
            if (matrix[i][j]==target) return true;
            else if (matrix[i][j]<target) i++;
            else j--;
        }
        return false;
    }
};

int main()
{
	return 0;
}

