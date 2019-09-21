// 因为有"( [ ) ]"案例的存在，我能想到的是第一个思路是从中间开始判断，因为括号都是成对出现的。
// 但后来想想不太好实现，又考虑了一下规律：
// 1. 左括号后面必须跟对应的右括号或者其他类型的左括号
// 2. 可以用先进后出栈来实现，遇上对应的括号对就弹出去


class Solution {
    public:
    bool isValid(string s) {
        map < char, char > brRight = {{'}', '{'},
                                      {')', '('},
                                      {']', '['}}
        vector < char > pair
        if (s.size() == 0) return true
        if (s.size() % 2 != 0) return false
        for (char & ch: s){
            pair.push_back(ch)
            if (pair.size() < 2) continue
            auto iter = pair.end() - 1
            // 注意，end()指向最后一个元素的下一格！所以 - 1就指向最后一个元素
            auto last = pair.back()
            if (brRight.find(last) != brRight.end()){
                if (*--iter == brRight[last]){
                    pair.pop_back()
                    pair.pop_back()
                    continue
                }
                else return false
            }
            else continue
        }
        if (pair.size() == 0) return true
        else return false
    }
}
