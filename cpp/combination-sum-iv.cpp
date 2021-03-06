377. Combination Sum IV  QuestionEditorial Solution  My Submissions
Total Accepted: 9243 Total Submissions: 23242 Difficulty: Medium
Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.
Subscribe to see which companies asked this question

Hide Tags Dynamic Programming
Hide Similar Problems (M) Combination Sum

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (nums.size()==0 || target<0) return 0;
        if (target==0) return 1;
        if (count.find(target)!=count.end()) return count[target];
        int sum=0;
        
        for (auto n:nums) {
            sum+=combinationSum4(nums, target-n);
        }
        count[target]=sum;
        return sum;
    }
private:
    unordered_map<int,int> count;
};

2.
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {        
        if (target<=0) return 0;
        vector<unsigned int> dp(target+1);
        dp[0]=1;
        //sort(nums.begin(), nums.end());
        for (int i=1; i<=target; ++i) {
            for (auto n:nums) {
                if (i>=n) dp[i]+=dp[i-n];
                //else break;
            }
        }
        
        return dp[target];
    }
};
