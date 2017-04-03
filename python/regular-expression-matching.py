class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        return self.isMatchHelper(s, p, 0, 0)
    def isMatchHelper(self, s, p, i, j):
        if j == len(p):
            return i == len(s)
        if j == len(p)-1 or p[j+1] != '*':
            return i < len(s) and (s[i] == p[j] or p[j] == '.') and self.isMatchHelper(s, p, i+1, j+1)
            
        while i < len(s) and (s[i] == p[j] or p[j] == '.'):
            if self.isMatchHelper(s, p, i, j+2):
                return True
            i += 1
        return self.isMatchHelper(s, p, i, j+2)

2. use memoize
class Solution(object):
    def memoize(func):
        memo={}
        def wrapper(*args):
            if args in memo: return memo[args]
            res=func(*args)
            memo[args]=res
            return res
    
        return wrapper
    
    @memoize
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        if not p:
            return not s
        if len(p) == 1 or p[1] != '*':
            return s != '' and (s[0] == p[0] or p[0] == '.') and self.isMatch(s[1:], p[1:])
        while s and (s[0] == p[0] or p[0] == '.'):
            if self.isMatch(s, p[2:]):
                return True
            s = s[1:]
        return self.isMatch(s, p[2:])
        
