class Solution:
    def count(self, s):
        res = ""
        i = 0
        anzahl = 1
        while i < len(s):
            j = 0  # when the string contains only "1", then j should be defined first
            for j in range(i + 1, len(s)):  # 把第i个数字与i+1,i+2...对比，如果相同，计数加1
                if s[j] == s[i]:
                    anzahl += 1
                else:  # 如果不同，则输出有多少个s[i]，然后从这个不同的数字开始重新计数
                    res += str(anzahl) + s[i]
                    i = j
                    anzahl = 1
            if j == len(s) - 1:  # 如果j已经到达末尾，说明没有碰到不同的数字，则输出计数并停止循环
                res += str(anzahl) + s[i]
                break
        return res

    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        s = "1"
        for i in range(n - 1):
            s = self.count(s)
        return s
