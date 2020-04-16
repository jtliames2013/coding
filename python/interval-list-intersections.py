class Solution:
    def intervalIntersection(self, A: List[List[int]], B: List[List[int]]) -> List[List[int]]:
        res, i, j=[], 0, 0
        while i<len(A) and j<len(B):
            if A[i][1]<B[j][0]: i+=1
            elif B[j][1]<A[i][0]: j+=1
            else:
                res.append([max(A[i][0], B[j][0]), min(A[i][1], B[j][1])])
                if A[i][1]<B[j][1]: i+=1
                elif A[i][1]>B[j][1]: j+=1
                else:
                    i+=1
                    j+=1
        return res

