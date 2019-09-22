class Solution:
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        sum_str = str(bin(int(a, 2) + int(b, 2))
                      )  # 先把字符串视为二进制，转换成十进制加减，再转换回二进制
        answer = sum_str.split('b')[1]  # 以‘b’为分隔符，把上句结果中的0b隔开
        return answer
