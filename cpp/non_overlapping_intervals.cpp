435. Non-overlapping Intervals   QuestionEditorial Solution  My Submissions
Total Accepted: 1744 Total Submissions: 4524 Difficulty: Medium Contributors: love_FDU_llp
Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Note:
You may assume the interval's end point is always bigger than its start point.
Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.

Example 1:
Input: [ [1,2], [2,3], [3,4], [1,3] ]

Output: 1

Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
Example 2:
Input: [ [1,2], [1,2], [1,2] ]

Output: 2

Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.

Example 3:
Input: [ [1,2], [2,3] ]

Output: 0

Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
Subscribe to see which companies asked this question

Hide Tags Greedy

Actually, the problem is the same as "Given a collection of intervals, find the maximum number of intervals that are non-overlapping." (the classic Greedy problem: Interval Scheduling).
https://en.wikipedia.org/wiki/Interval_scheduling#Interval_Scheduling_Maximization

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        int n=intervals.size();
        if (n==0) return 0;
        sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b) { return a.end<b.end; } );
        
        int end=intervals[0].end, count=0;
        for (int i=1; i<n; i++) {
            if (intervals[i].start<end) count++;
            else end=intervals[i].end;
        }
        return count;
    }
};

