

class Solution {
    public:
    string Count(string s){
        int anzahl = 1, i = 0, j = 0
        string res = ""
        while (i < s.size()){
            for (j=i + 1
                 i < s.size()
                 + +j) // 把第i个数字与i + 1, i + 2...对比，如果相同，计数加1
            if (s[i] == s[j]) + +anzahl
                else{// 如果不同，则输出有多少个s[i]，然后从这个不同的数字开始重新计数
                      res += to_string(anzahl) + s[i]
                      i = j
                      anzahl = 1
                      }
            if (j == s.size()-1){// 如果j已经到达末尾，说明没有碰到不同的数字，则输出计数并停止循环
                                  res += to_string(anzahl) + s[i]
                                  break
                                  }
        }
        return res
    }
    string countAndSay(int n) {
        string s = "1"
        for (int i=1
             i < n
             + +i)
        s = Count(s)
        return s
    }
};
