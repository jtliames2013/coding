1167. Minimum Cost to Connect Sticks
Medium

118

33

Favorite

Share
You have some sticks with positive integer lengths.

You can connect any two sticks of lengths X and Y into one stick by paying a cost of X + Y.  You perform this action until there is one stick remaining.

Return the minimum cost of connecting all the given sticks into one stick in this way.

 

Example 1:

Input: sticks = [2,4,3]
Output: 14
Example 2:

Input: sticks = [1,8,3,5]
Output: 30
 

Constraints:

1 <= sticks.length <= 10^4
1 <= sticks[i] <= 10^4

Amazon
|
14

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        int res=0;
        priority_queue<int, vector<int>, greater<int>> pq(sticks.begin(), sticks.end());
        while (pq.size()>1) {
            auto t=pq.top();
            pq.pop();
            auto sum=pq.top()+t;
            pq.pop();
            res+=sum;
            pq.push(sum);
        }
        return res;
    }
};

