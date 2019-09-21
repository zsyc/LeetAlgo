# 因为有"( [ ) ]"案例的存在，我能想到的是第一个思路是从中间开始判断，因为括号都是成对出现的。
# 但后来想想不太好实现，又考虑了一下规律：
# 1. 左括号后面必须跟对应的右括号或者其他类型的左括号
# 2. 可以用先进后出栈来实现，遇上对应的括号对就弹出去


class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        brRight = {')': '(',
                   ']': '[',
                   '}': '{'}
        pair = []
        if len(s) == 0:       # 空集成立
            return True
        if len(s) % 2 != 0:     # valid必然为偶数长度
            return False
        for br in s:
            pair.append(br)
            if len(pair) < 2:
                continue
            # 碰到右括号，就判定前一个字符是否是对应的左括号
            if pair[-1] in brRight:
                if pair[-2] == brRight[pair[-1]]:
                    pair.pop()
                    pair.pop()
                    continue
                else:
                    return False
            else:
                continue

        if len(pair) == 0:
            return True
        else:
            return False
