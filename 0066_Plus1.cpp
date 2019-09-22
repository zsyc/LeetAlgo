/*
Python ：
列表元素转换成字符，join连接成字符串，转换成int，+ 1；
转换成字符串，转换成列表返回。

C + +:
主要是注意9 + 1的进位，分别处理每个int，不使用上述方法
从最后一位往前判断，如果是9就设为0，碰到第一个不是9的，就加1。如果到了最开始，那就前加一位

还有一种答案是设置新的vector，+ 1后，形成vector
*/


class Solution {
    public:
    vector < int > plusOne(vector < int > & digits) {
        vector < int >: : iterator ite = digits.end()-1
        if (*ite != 9) * ite += 1
        else{
            for (
                *ite == 9 & & ite >= digits.begin()
                - -ite) * ite = 0
            if (ite >= digits.begin()) * ite += 1
            else digits.insert(digits.begin(), 1)
        }

        return digits
    }
}
