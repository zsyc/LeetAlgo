# 简单地通过两次循环，获得末尾单词前后索引
class Solution:
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        # 48ms:
        # slist=s.split(" ")
        # for i in reversed(slist):
        #     if i!="":
        #         return len(i)
        # return 0

        # idea from c++:
        i = len(s) - 1
        while i >= 0 and s[i] == ' ':
            i = i - 1
        if i < 0:
            return 0
        l = 0
        while i >= 0 and s[i] != ' ':
            i = i - 1
            l = l + 1
        return l
