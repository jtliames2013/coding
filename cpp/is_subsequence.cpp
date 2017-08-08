392. Is Subsequence   QuestionEditorial Solution  My Submissions
Total Accepted: 12683 Total Submissions: 28931 Difficulty: Medium Contributors: Admin
Given a string s and a string t, check if s is subsequence of t.

You may assume that there is only lower case English letters in both s and t. t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
s = "abc", t = "ahbgdc"

Return true.

Example 2:
s = "axc", t = "ahbgdc"

Return false.

Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Hide Tags Binary Search Dynamic Programming Greedy

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m=s.size(), n=t.size(), i=0, j=0;
        while (i<m && j<n) {
            if (s[i]==t[j]) i++;
            j++;
        }
        return i==m;
    }
};

2. binary search (MLE)
class Solution {
public:
    bool isSubsequence(string s, string t) {
        unordered_map<char,set<int>> mp;
        for (int i=0; i<t.size(); i++) mp[t[i]].insert(i);
        
        int lower=0;
        for (int i=0; i<s.size(); i++) {
            if (mp.find(s[i])==mp.end()) return false;
            auto iter=mp[s[i]].lower_bound(lower);
            if (iter==mp[s[i]].end()) return false;
            lower=(*iter)+1;
        }
        return true;
    }
};

