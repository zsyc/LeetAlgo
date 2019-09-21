class Solution:
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        rev = 0
        if x < 0 or (x % 10 == 0 and x != 0):
            return False
        while x > rev:
            pop = x % 10
            x = x // 10
            rev = rev * 10 + pop
        return x == rev or x == rev // 10
