224. Basic Calculator 
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
Note: Do not use the eval built-in library function.

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

/*
中缀表达式转为后缀表达式的要点：
开始扫描；

数字时，加入后缀表达式；

运算符：

a. 若为 '('，入栈；

b. 若为 ')'，则依次把栈中的的运算符加入后缀表达式中，直到出现'('，从栈中删除'(' ；

c. 若为 除括号外的其他运算符， 当其优先级高于除'('以外的栈顶运算符时，直接入栈。否则从栈顶开始，依次弹出比当前处理的运算符优先级高和优先级相等的运算符，直到一个比它优先级低的或者遇到了一个左括号为止。
·当扫描的中缀表达式结束时，栈中的的所有运算符出栈；

后缀表达式求值的过程简述：

建立一个栈S

从左到右读表达式，如果读到操作数就将它压入栈S中

如果读到n元运算符(即需要参数个数为n的运算符)则取出由栈顶向下的n项按操作符运算，再将运算的结果代替原栈顶的n项，压入栈S中

如果后缀表达式未读完，则重复上面过程，最后输出栈顶的数值则为结束。
*/

class Solution {
public:
	bool isoperator(char c) {
		return (c=='+' || c=='-');
	}

	bool isoperator(string s) {
		return (s.compare("+")==0 || s.compare("-")==0);
	}

	bool isparenthesis(char c) {
		return (c=='(' || c==')');
	}

	string getNext(string s, int index, int& newIndex) {
		string next="";
		int i=index;
		if (isdigit(s[index])) {
			while (i<s.size() && isdigit(s[i])) i++;
			next=s.substr(index,i-index);
		} else if (isoperator(s[index]) || isparenthesis(s[index])) {
			i++;
			next=s.substr(index, i-index);
		}

		while (i<s.size() && s[i]==' ') i++;
		newIndex=i;

		return next;
	}

	vector<string> convertToRPN(string s) {
		vector<string> res;
		stack<string> op;
		int index=0, newIndex=0;

		while (newIndex<s.size()) {
			string token = getNext(s, index, newIndex);

			if (isdigit(token[0])) {
				res.push_back(token);
			} else if (token.compare("(")==0) {
				op.push(token);
			} else if (token.compare(")")==0) {
				while (!op.empty() && op.top().compare("(")!=0) {
					res.push_back(op.top());
					op.pop();
				}
				op.pop();
			} else if (isoperator(token)) {
				op.push(token);
			}

			index=newIndex;
		}

		while (!op.empty()) {
			res.push_back(op.top());
			op.pop();
		}

		return res;
	}

	int calculate(int n1, int n2, string op) {
		if (op.compare("+")==0) return n1+n2;
		else if (op.compare("-")==0) return n1-n2;
		else return 0;
	}

	int evalRPN(vector<string> tokens) {
		stack<int> stk;
		for (int i=0; i<tokens.size(); i++) {
			if (isdigit(tokens[i][0])) {
				stk.push(atoi(tokens[i].c_str()));
			} else if (isoperator(tokens[i])) {
				int num1=stk.top();
				stk.pop();
				int num2=stk.top();
				stk.pop();
				int res=calculate(num1, num2, tokens[i]);
				stk.push(res);
			}
		}

		return stk.top();
	}

    int calculate(string s) {
    	vector<string> tokens = convertToRPN(s);
    	return evalRPN(tokens);
    }
};

2. Basically add or minus from left to right, when inside (), the sign is toggled depending on operator before
(). E.g., 1+(2-3), 1-(2-3)
class Solution {
public:
    int calculate(string s) {
        int res=0;
        // one for add first number, one for multiple operator sign
        vector<int> sign(2,1);
        
        for (int i=0; i<s.size();) {
            if (isdigit(s[i])) {
                int num=0;
                while (i<s.size() && isdigit(s[i])) {
                    num=num*10+s[i]-'0';  
                    i++;
                }
                res+=num*sign.back();
                sign.pop_back();
            } else if (s[i]==')') {
                sign.pop_back();
                i++;
            } else if (s[i]!=' ') {
                sign.push_back(sign.back()*(s[i]=='-'?-1:1));
                i++;
            } else {
                i++;
            }
        }
        return res;
    }
};

3. Use recursion on ()
class Solution {
public:
    int recur(string& s, int start, int end, int *newIdx) {
        int sum=0, num=0;
        int sign=1;
        int idx;
        for (int i=start; i<=end; i++) {
            if (s[i]==' ') continue;
            else if (s[i]=='(') {
                sum+=sign*recur(s, i+1, end, &idx);
                i=idx;
            } else if (s[i]==')') {
                if (newIdx) *newIdx=i;
                return sum;
            } else if (s[i]=='+'||s[i]=='-') {
                sign=(s[i]=='+'?1:-1);
            } else if (isdigit(s[i])) {
                num=0;
                while (i<s.size() && isdigit(s[i])) {
                    num=num*10+s[i]-'0';
                    i++;
                }
                i--;
                sum+=sign*num;
            }
        }
        
        return sum;
    }
    int calculate(string s) {
        s="(" + s + ")";
        return recur(s, 0, s.size()-1, nullptr);
    }
};

int main()
{
	return 0;
}

