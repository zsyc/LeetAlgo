

class Solution {
    public:
    int romanToInt(string s) {
        unordered_map < char, int > roma = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        }
        int sum = roma[s.back()]
        for (int i=s.length() - 2
             i >= 0
- -i){// 倒数第二个元素开始
            if (roma[s[i]] < roma[s[i + 1]])
            sum -= roma[s[i]]
            else sum += roma[s[i]]
       }
        return sum
    }
};
