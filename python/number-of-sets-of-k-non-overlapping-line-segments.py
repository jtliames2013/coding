The same as choosing 2*k points (k segments) out of n+k-1 points
to make non-adjacent k segments

class Solution:
    def numberOfSets(self, n: int, k: int) -> int:
        return comb(n+k-1, 2*k)%(10**9+7)

