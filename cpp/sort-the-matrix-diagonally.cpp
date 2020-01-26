1329. Sort the Matrix Diagonally
Medium

25

15

Add to List

Share
Given a m * n matrix mat of integers, sort it diagonally in ascending order from the top-left to the bottom-right then return the sorted array.

 

Example 1:


Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 100
1 <= mat[i][j] <= 100

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                mp[i-j].push(mat[i][j]);
            }
        }
        
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                mat[i][j]=mp[i-j].top();
                mp[i-j].pop();
            }
        }        
        
        return mat;
    }
};

