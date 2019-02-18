from collections import deque

class RecentCounter:

    def __init__(self):
        self.q=deque()
        

    def ping(self, t):
        """
        :type t: int
        :rtype: int
        """
        while len(self.q)>0 and t-self.q[0]>3000: self.q.popleft()
        self.q.append(t)
        return len(self.q)


# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)
