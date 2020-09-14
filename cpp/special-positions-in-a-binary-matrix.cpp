1582. Special Positions in a Binary Matrix
Easy

73

3

Add to List

Share
Given a rows x cols matrix mat, where mat[i][j] is either 0 or 1, return the number of special positions in mat.

A position (i,j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).

 

Example 1:

Input: mat = [[1,0,0],
              [0,0,1],
              [1,0,0]]
Output: 1
Explanation: (1,2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.
Example 2:

Input: mat = [[1,0,0],
              [0,1,0],
              [0,0,1]]
Output: 3
Explanation: (0,0), (1,1) and (2,2) are special positions. 
Example 3:

Input: mat = [[0,0,0,1],
              [1,0,0,0],
              [0,1,1,0],
              [0,0,0,0]]
Output: 2
Example 4:

Input: mat = [[0,0,0,0,0],
              [1,0,0,0,0],
              [0,1,0,0,0],
              [0,0,1,0,0],
              [0,0,0,1,1]]
Output: 3
 

Constraints:

rows == mat.length
cols == mat[i].length
1 <= rows, cols <= 100
mat[i][j] is 0 or 1.

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int res=0, m=mat.size(), n=mat[0].size();
        vector<int> rowCnt(m), colCnt(n);
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (mat[i][j]==1) {
                    rowCnt[i]++;
                    colCnt[j]++;
                }
            }
        }
        
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (mat[i][j]==1 && rowCnt[i]==1 && colCnt[j]==1) {
                    res++;
                }
            }
        }        
        
        return res;
    }
};

