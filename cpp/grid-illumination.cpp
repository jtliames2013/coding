1001. Grid Illumination
Hard

122

49

Favorite

Share
On a N x N grid of cells, each cell (x, y) with 0 <= x < N and 0 <= y < N has a lamp.

Initially, some number of lamps are on.  lamps[i] tells us the location of the i-th lamp that is on.  Each lamp that is on illuminates every square on its x-axis, y-axis, and both diagonals (similar to a Queen in chess).

For the i-th query queries[i] = (x, y), the answer to the query is 1 if the cell (x, y) is illuminated, else 0.

After each query (x, y) [in the order given by queries], we turn off any lamps that are at cell (x, y) or are adjacent 8-directionally (ie., share a corner or edge with cell (x, y).)

Return an array of answers.  Each value answer[i] should be equal to the answer of the i-th query queries[i].

 

Example 1:

Input: N = 5, lamps = [[0,0],[4,4]], queries = [[1,1],[1,0]]
Output: [1,0]
Explanation: 
Before performing the first query we have both lamps [0,0] and [4,4] on.
The grid representing which cells are lit looks like this, where [0,0] is the top left corner, and [4,4] is the bottom right corner:
1 1 1 1 1
1 1 0 0 1
1 0 1 0 1
1 0 0 1 1
1 1 1 1 1
Then the query at [1, 1] returns 1 because the cell is lit.  After this query, the lamp at [0, 0] turns off, and the grid now looks like this:
1 0 0 0 1
0 1 0 0 1
0 0 1 0 1
0 0 0 1 1
1 1 1 1 1
Before performing the second query we have only the lamp [4,4] on.  Now the query at [1,0] returns 0, because the cell is no longer lit.
 

Note:

1 <= N <= 10^9
0 <= lamps.length <= 20000
0 <= queries.length <= 20000
lamps[i].length == queries[i].length == 2

class Solution {
public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        int n=queries.size(), i=0;
        vector<int> res(n);
        unordered_map<int, int> row, col, diag, antidiag;
        set<pair<int,int>> st;
        for (auto& l:lamps) {
            int r=l[0], c=l[1];
            if (st.find({r, c})==st.end()) {                
                st.insert({r, c});
                row[r]++;
                col[c]++;
                diag[r+c]++;
                antidiag[r-c]++;
            }    
        }
        
        for (auto& q:queries) {
            int r=q[0], c=q[1];
            if (row[r]>0 || col[c]>0 || diag[r+c]>0 || antidiag[r-c]>0) {
                res[i]=1;
                for (int j=r-1; j<=r+1; ++j) {
                    for (int k=c-1; k<=c+1; ++k) {
                        if (j>=0 && j<N && k>=0 && k<N && st.find({j, k})!=st.end()) {
                            st.erase({j, k});
                            row[j]--;
                            col[k]--;
                            diag[j+k]--;
                            antidiag[j-k]--;
                        }
                    }
                }
            }
            i++;
        }
        return res;
    }
};

