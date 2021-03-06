22. Generate Parentheses  QuestionEditorial Solution  My Submissions
Total Accepted: 103330 Total Submissions: 262760 Difficulty: Medium
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
Subscribe to see which companies asked this question

Hide Tags Backtracking String
Hide Similar Problems (M) Letter Combinations of a Phone Number (E) Valid Parentheses

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string output;
        dfs(res, output, n, n);
        return res;
    }
private:
    void dfs(vector<string>& res, string& output, int left, int right) {
        if (right==0) {
            res.push_back(output);
            return;
        }

        if (left>0) {
            output.push_back('(');
            dfs(res, output, left-1, right);
            output.pop_back();
        }
        if (right>left) {
            output.push_back(')');
            dfs(res, output, left, right-1);
            output.pop_back();
        }
    }
};
