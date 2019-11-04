class Solution:
    def fourSumCount(self, A: List[int], B: List[int],
                     C: List[int], D: List[int]) -> int:
        s = 0
        if A == []:
            return 0
        L = len(A)
        # 以下方法来自网友，使用了map, 暂时不知道如何优化
        mp = {}
        for a in A:
            for b in B:
                mp[a + b] = mp.get(a + b, 0) + 1
        for c in C:
            for d in D:
                if -(c + d) in mp:
                    s += mp[-c - d]
        return s
