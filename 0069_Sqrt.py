class Solution:
    def ten(self, n: int) -> int:   # 求10的n次方函数，可以用pow函数代替
        srt = 1
        for i in range(n):
            srt *= 10
        return srt

    def mySqrt(self, x: int) -> int:
        '''
        转化为循环寻找c，使得c^2<=x
        A. 分析
        但每次从最小值累加寻找太慢，首先划定范围：
        1.  当c为一位数，则x为一或两位数
        2.  当c为两位数，则x为三或者四位数……
        3.  当c为三位数，则x为五位数或者六位数
        反过来说，当x为三位数的时候，c必然是两位数
        当x为四位数的时候，c必然也是两位数
        当x为五位数时，c必然三位数……

        B. 因为3是不进位的最大数字，那么尝试的界限一般以3为界
            1. c为一位数，则3为界限
            2. c为两位数，则31
            3. c为三位数，则316

        C. 确定循环界限
        然后当x位数为奇数时，在上述范围内从1/10/100/1000到3/32/320/3200尝试平方
        当x位数为偶数，则从3/31/310/3100开始，因为这样比较接近
        '''
        if x == 0:
            return 0
        L = len(str(x))
        if L % 2 == 1:
            basis = self.ten(int((L - 1) / 2))
            for i in range(
                basis, int(3.2 * basis) + 1):    # +1就是为了应对一位数取不到3的情形
                if i * i <= x and (i + 1) * (i + 1) > x:
                    return i
        else:
            basis = self.ten(int((L - 2) / 2))
            for i in range(int(3.1 * basis), basis * 10):
                if i * i <= x and (i + 1) * (i + 1) > x:
                    return i

"""没想到思考了那么久，竟然得到的是只快于7%的python答案！
明晚再考虑优化……“”“
