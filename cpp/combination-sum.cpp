39. Combination Sum  
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]
Hide Company Tags Snapchat Uber
Hide Tags Array Backtracking
Show Similar Problems

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> output;
        dfs(candidates, res, output, target, 0);
        
        return res;
    }

private:
    void dfs(vector<int>& candidates, vector<vector<int>>& res, vector<int>& output, int target, int start) {
        if (target==0) {
            res.push_back(output);
            return;
        }
        
        for (int i=start; i<candidates.size(); ++i) {
            if (target>=candidates[i]) {
                output.push_back(candidates[i]);
                dfs(candidates, res, output, target-candidates[i], i);
                output.pop_back();
            }
        }   
    }
};
