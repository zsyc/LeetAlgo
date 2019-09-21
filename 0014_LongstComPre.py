class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        # vertical scanning
        if not strs:
            return ""
        for i in range(len(strs[0])):
            ch = strs[0][i]
            for word in strs:
                if i >= len(word) or word[i] != ch:
                    return strs[0][:i]
            if i == len(strs[0]) - 1:   # 第一个单词已经到末尾
                return strs[0]
        return ""
