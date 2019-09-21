# 秘诀就是每抽出一位，就翻转*10加上去
class Solution:
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        rev = 0
        MAX = 2**31
        if x >= 0:
            while x != 0:
                pop = x % 10
                x = x // 10
                if rev > MAX // 10 or (rev == MAX // 10 and pop > 7):
                    return 0
                rev = rev * 10 + pop
            return rev
        else:
            x = -x
            while x != 0:
                pop = x % 10
                x = x // 10
                if rev > MAX // 10 or (rev == MAX // 10 and pop > 7):
                    return 0
                rev = rev * 10 + pop
            return -rev
