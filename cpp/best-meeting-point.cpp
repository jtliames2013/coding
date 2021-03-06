296. Best Meeting Point
A group of two or more people wants to meet and minimize the total travel distance. You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.
For example, given three people living at (0,0), (0,4), and (2,2):
1 - 0 - 0 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
The point (0,2) is an ideal meeting point, as the total travel distance of 2+2+2=6 is minimal. So return 6.
Hint:
1. Try to solve it in one dimension first. How can this solution apply to the two dimension case?

Snapchat
|
4

Google
|
2

Facebook
|
2

Twitter
|
LeetCode

//Finding the best meeting point in a 2D grid seems difficult. Let us take a step back and solve the 1D case which is much simpler. Notice that the Manhattan distance is the sum of two independent variables. Therefore, once we solve the 1D case, we can solve the 2D case as two independent 1D problems.
//
//Let us look at some 1D examples below:
//
//Case #1: 1-0-0-0-1
//
//Case #2: 0-1-0-1-0
//We know the best meeting point must locate somewhere between the left-most and right-most point. For the above two cases, we would select the center point at x = 2x=2 as the best meeting point. How about choosing the mean of all points as the meeting point?
//
//Consider this case:
//
//Case #3: 1-0-0-0-0-0-0-1-1
//Using the mean gives us \bar{x} = \frac{0 + 7 + 8}{3} = 5
//​x
//​¯
//​​ =
//​3
//​
//​0+7+8
//​​ =5 as the meeting point. The total distance is 1010.
//
//But the best meeting point should be at x = 7x=7 and the total distance is 88.
//
//You may argue that the mean is close to the optimal point. But imagine a larger case with many 1's congregating on the right side and just a single 1 on the left-most side. Using the mean as the meeting point would be far from optimal.
//
//Besides mean, what is a better way to represent the distribution of points? Would median be a better representation? Indeed. In fact, the median must be the optimal meeting point.
//
//Case #4: 1-1-0-0-1
//To see why this is so, let us look at case #4 above and choose the median x = 1x=1 as our initial meeting point. Assume that the total distance traveled is d. Note that we have equal number of points distributed to its left and to its right. Now let us move one step to its right where x = 2x=2 and notice how the distance changes accordingly.
//
//Since there are two points to the left of x = 2x=2, we add 2 * (+1)2∗(+1) to d. And d is offset by –1 since there is one point to the right. This means the distance had overall increased by 1.
//
//Therefore, it is clear that:
//
//As long as there is equal number of points to the left and right of the meeting point, the total distance is minimized.
//Case #5: 1-1-0-0-1-1
//One may think that the optimal meeting point must fall on one of the 1's. This is true for cases with odd number of 1's, but not necessarily true when there are even number of 1's, just like case #5 does. You can choose any of the x = 1x=1 to x = 4x=4 points and the total distance is minimized. Why?
//
//The implementation is direct. First we collect both the row and column coordinates, sort them and select their middle elements. Then we calculate the total distance as the sum of two independent 1D problems.

class Solution {
public:
    int minTotalDistance1D(vector<int> points, int mid) {
        int dist=0;
        for (auto p:points) dist+=abs(p-mid);
            
        return dist;
    }
    
    int minTotalDistance(vector<vector<int>>& grid) {
        int m=grid.size();
        if (m==0) return 0;
        int n=grid[0].size();
        if (n==0) return 0;
        
        vector<int> rows, cols;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j]==1) {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        
        // rows is already sorted
        sort(cols.begin(), cols.end());
        int rowDist=minTotalDistance1D(rows, rows[rows.size()/2]);
        int colDist=minTotalDistance1D(cols, cols[cols.size()/2]);
        return rowDist+colDist;
    }
};

