"""
Python ：
列表元素转换成字符，join连接成字符串，转换成int，+1；
转换成字符串，转换成列表返回。

C++:
主要是注意9+1的进位，分别处理每个int，不使用上述方法
从最后一位往前判断，如果是9就设为0，碰到第一个不是9的，就加1。如果到了最开始，那就前加一位

还有一种答案是设置新的vector，+1后，形成vector
"""


class Solution:
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        s = list(map(str, digits))
        di = int(''.join(s)) + 1
        s = str(di)
        return [int(x) for x in s]
