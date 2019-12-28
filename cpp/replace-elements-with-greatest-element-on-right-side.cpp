1299. Replace Elements with Greatest Element on Right Side
Easy

3

0

Add to List

Share
Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.

After doing so, return the array.

 

Example 1:

Input: arr = [17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]
 

Constraints:

1 <= arr.length <= 10^4
1 <= arr[i] <= 10^5

Amazon
|
LeetCode

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size(), mx=-1, num;
        for (int i=n-1; i>=0; --i) {
            num=arr[i];
            arr[i]=mx;
            mx=max(mx, num);
        }
        return arr;
    }
};

