378. Kth Smallest Element in a Sorted Matrix   QuestionEditorial Solution  My Submissions
Total Accepted: 15932 Total Submissions: 37770 Difficulty: Medium Contributors: Admin
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.

Note: 
You may assume k is always valid, 1 ≤ k ≤ n2.

Subscribe to see which companies asked this question

Hide Tags Binary Search Heap
Hide Similar Problems (M) Find K Pairs with Smallest Sums

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m=matrix.size();
        if (m==0) return 0;
        int n=matrix[0].size();
        if (n==0) return 0;
        
        auto comp=[&](pair<int,int>& a, pair<int,int>& b){ return matrix[a.first][a.second]>matrix[b.first][b.second]; };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq(comp);
        pq.push({0,0});
        
        while (!pq.empty()) {
            auto t=pq.top();
            pq.pop();
            k--;
            if (k==0) return matrix[t.first][t.second];

            // add right neighbor only on the first row to avoid duplicate            
            if (t.first==0 && t.second<n-1) pq.push({t.first, t.second+1});
            if (t.first<m-1) pq.push({t.first+1, t.second});
        }
        return 0;
    }
};

2. binary search
class Solution {
public:
    int countSmaller(vector<vector<int>>& matrix, int target, int m) {
        int i=0, j=m-1, count=0;
        while (i<m && j>=0) {
            if (target>=matrix[i][j]) {
                count+=j+1;
                i++;
            } else {
                j--;
            }
        }
        return count;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m=matrix.size();
        if (m==0) return 0;
        int l=matrix[0][0], r=matrix[m-1][m-1], mid;
        while (l<r) {
            mid=l+(r-l)/2;
            int cnt=countSmaller(matrix, mid, m);
            if (cnt<k) l=mid+1;
            else r=mid;
        }
        return l;
    }
};

