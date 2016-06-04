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

  class TicTacToe {
  public:
      /** Initialize your data structure here. */
      TicTacToe(int n) {
    	  size=n;
    	  rows.resize(n);
    	  cols.resize(n);
    	  diag=0;
    	  antidiag=0;
      }

      /** Player {player} makes a move at ({row}, {col}).
          @param row The row of the board.
          @param col The column of the board.
          @param player The player, can be either 1 or 2.
          @return The current winning condition, can be either:
                  0: No one wins.
                  1: Player 1 wins.
                  2: Player 2 wins. */
      int move(int row, int col, int player) {
    	  int delta = player==1?1:-1;
    	  int threshold = player==1?size:-size;
    	  rows[row]+=delta;
    	  cols[col]+=delta;
    	  if (row==col) diag+=delta;
    	  if (row+col==size-1) antidiag+=delta;

    	  if (rows[row]==threshold || cols[col]==threshold ||
    		  diag==threshold || antidiag==threshold) {
    		  return player;
    	  }

    	  return 0;
      }
  private:
      vector<int> rows;
      vector<int> cols;
      int diag;
      int antidiag;
      int size;
  };

  /**
   * Your TicTacToe object will be instantiated and called as such:
   * TicTacToe obj = new TicTacToe(n);
   * int param_1 = obj.move(row,col,player);
   */

int main()
{
	return 0;
}
