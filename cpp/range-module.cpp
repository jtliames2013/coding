715. Range Module
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
A Range Module is a module that tracks ranges of numbers. Your task is to design and implement the following interfaces in an efficient manner.

addRange(int left, int right) Adds the half-open interval [left, right), tracking every real number in that interval. Adding an interval that partially overlaps with currently tracked numbers should add any numbers in the interval [left, right) that are not already tracked.
queryRange(int left, int right) Returns true if and only if every real number in the interval [left, right) is currently being tracked.
removeRange(int left, int right) Stops tracking every real number currently being tracked in the interval [left, right).
Example 1:
addRange(10, 20): null
removeRange(14, 16): null
queryRange(10, 14): true (Every number in [10, 14) is being tracked)
queryRange(13, 15): false (Numbers like 14, 14.03, 14.17 in [13, 15) are not being tracked)
queryRange(16, 17): true (The number 16 in [16, 17) is still being tracked, despite the remove operation)
Note:

A half open interval [left, right) denotes all real numbers left <= x < right.
0 < left < right < 10^9 in all calls to addRange, queryRange, removeRange.
The total number of calls to addRange in a single test case is at most 1000.
The total number of calls to queryRange in a single test case is at most 5000.
The total number of calls to removeRange in a single test case is at most 1000.

1. vector
class RangeModule {
public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {                
        vector<pair<int,int>> res;
        int i=0, n=intervals.size();
        for (; i<n; i++) {
            if (intervals[i].second<left) {
                res.push_back(intervals[i]);                
            } else if (intervals[i].first>right) {
                break;
            } else {
                left=min(intervals[i].first, left);
                right=max(intervals[i].second, right);
            }
        }
        res.push_back({left,right});
        for (; i<n; i++) res.push_back(intervals[i]);
        swap(intervals, res);
    }
    
    bool queryRange(int left, int right) {        
        if (intervals.empty()) return false;
        int l=0, r=intervals.size()-1, mid;        
        while (l<=r) {
            mid=l+(r-l)/2;
            if (intervals[mid].second<left) l=mid+1;
            else if (intervals[mid].first>right) r=mid-1;
            else {
                return intervals[mid].first<=left && intervals[mid].second>=right;                
            }
        }
        return false;
    }
    
    void removeRange(int left, int right) {        
        vector<pair<int,int>> res;
        int i=0, n=intervals.size();
        for (; i<n; i++) {
            if (intervals[i].second<left) {
                res.push_back(intervals[i]);
            } else if (intervals[i].first>right) {         
                break;
            } else {                
                if (intervals[i].first<left) res.push_back({intervals[i].first,left});
                if (intervals[i].second>right) res.push_back({right,intervals[i].second});        
            }
        }
        for (; i<n; i++) res.push_back(intervals[i]);
        swap(intervals, res);
    }
private:
    vector<pair<int,int>> intervals;
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * bool param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */

2. map
class RangeModule {
public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        auto l=intervals.lower_bound(left), r=intervals.upper_bound(right);
        if (l!=intervals.begin()) {
            l--;
            if (l->second<left) l++;
        }
        if (l!=r) {
            left=min(left, l->first);            
            right=max(right, (--r)->second);
            intervals.erase(l, ++r);
        }
        intervals[left]=right;
    }
    
    bool queryRange(int left, int right) {
        auto iter=intervals.upper_bound(left);
        if (iter==intervals.begin() || (--iter)->second<right) return false;
        return true;
    }
    
    void removeRange(int left, int right) { 
        auto l=intervals.lower_bound(left), r=intervals.upper_bound(right);
        if (l!=intervals.begin()) {
            l--;
            if (l->second<left) l++;
        }
        if (l==r) return;
        int l1=min(l->first, left), r1=max((--r)->second, right);
        intervals.erase(l, ++r);
        if (l1<left) intervals[l1]=left;
        if (r1>right) intervals[right]=r1;
    }
private:
    map<int,int> intervals;
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * bool param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */