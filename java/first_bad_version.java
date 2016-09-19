/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        if (n<=0) return 0;
        int l=1, r=n;
        while (l<r) {
            int mid=l+(r-l)/2;
            if (isBadVersion(mid)) {
                r=mid;
            } else {
                l=mid+1;
            }
        }
        
        return r;
    }
}
