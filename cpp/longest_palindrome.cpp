409. Longest Palindrome   QuestionEditorial Solution  My Submissions
Total Accepted: 8924 Total Submissions: 20149 Difficulty: Easy Contributors: Admin
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
Subscribe to see which companies asked this question

Hide Tags Hash Table
Hide Similar Problems (E) Palindrome Permutation

class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> count;
        for (auto c:s) count[c]++;
        bool odd=0;
        int res=0;
        for (auto cnt:count) {
            if (cnt.second%2==0) {
                res+=cnt.second;
            } else {
                odd=true;
                res+=cnt.second-1;
            }
        }
        return odd?res+1:res;
    }
};
