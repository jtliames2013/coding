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
	string getOne(int num) {
		switch (num) {
		case 1:
			return "One";
		case 2:
			return "Two";
		case 3:
			return "Three";
		case 4:
			return "Four";
		case 5:
			return "Five";
		case 6:
			return "Six";
		case 7:
			return "Seven";
		case 8:
			return "Eight";
		case 9:
			return "Nine";
		}
	}

	string getTen(int num) {
		switch (num) {
		case 2:
			return "Twenty";
		case 3:
			return "Thirty";
		case 4:
			return "Forty";
		case 5:
			return "Fifty";
		case 6:
			return "Sixty";
		case 7:
			return "Seventy";
		case 8:
			return "Eighty";
		case 9:
			return "Ninety";
		}
	}

	string getOneTen(int num) {
		switch (num) {
		case 10:
			return "Ten";
		case 11:
			return "Eleven";
		case 12:
			return "Twelve";
		case 13:
			return "Thirteen";
		case 14:
			return "Fourteen";
		case 15:
			return "Fifteen";
		case 16:
			return "Sixteen";
		case 17:
			return "Seventeen";
		case 18:
			return "Eighteen";
		case 19:
			return "Nineteen";
		}
	}

	string convertThreeDigit(int num) {
		string res;
		bool appendSpace=false;
		int digit=num/100;
		if (digit>0) {
			res.append(getOne(digit));
			res.append(" Hundred");
			appendSpace=true;
		}
		num=num%100;
		digit=num/10;
		if (digit==1) {
			if (appendSpace) res.append(" ");
			res.append(getOneTen(num));
		} else {
			if (digit>0) {
				if (appendSpace) res.append(" ");
				res.append(getTen(digit));
				appendSpace=true;
			}
			num=num%10;
			if (num>0) {
				if (appendSpace) res.append(" ");
				res.append(getOne(num));
			}
		}

		return res;
	}

    string numberToWords(int num) {
    	string res;
    	bool appendSpace=false;
    	int part=num/1000000000;
    	if (part>0) {
    		res.append(convertThreeDigit(part));
    		res.append(" Billion");
    		appendSpace=true;
    	}
    	num=num%1000000000;
    	part=num/1000000;
    	if (part>0) {
    		if (appendSpace) res.append(" ");
    		res.append(convertThreeDigit(part));
    		res.append(" Million");
    		appendSpace=true;
    	}
    	num=num%1000000;
    	part=num/1000;
    	if (part>0) {
    		if (appendSpace) res.append(" ");
    		res.append(convertThreeDigit(part));
    		res.append(" Thousand");
    		appendSpace=true;
    	}
    	num=num%1000;
    	if (num>0) {
    		if (appendSpace) res.append(" ");
    		res.append(convertThreeDigit(num));
    	} else {
    		if (appendSpace==false) res.append("Zero");
    	}

    	return res;
    }
};

int main()
{
	return 0;
}

