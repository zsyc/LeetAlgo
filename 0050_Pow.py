class Solution:
    def myPow(self, x: float, n: int) -> float:
        # 如果是c系语言，就要考虑输出值的类型，以防止溢出，python应该没有这个问题？
        if x == 0 and n == 0:
            return "undefined"
        elif n ==0:
            return 1
        y = n if n>0 else -n
        res = 1
        # 当输入值为0.00001  2147483647时，出现了超时错误……以下方法不高效
        '''
        for i in range (y):
            res *= x'''
        # folgende Loesung kommt aus Anderem
        # Idee ist: 3^11 = 3 * (3^2)^5 = 3 * 9^5 = 3*9* (9^2)^2 = 3*9* 81^2 =.....
        while y > 0:
            if y % 2 == 1:
                res *= x
                x *= x
                y = (y - 1) / 2
            else:
                x *= x
                y /= 2
        return res if n>0 else 1.0/res 
