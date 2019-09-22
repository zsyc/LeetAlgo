//简单地通过两次循环，获得末尾单词前后索引


class Solution {
    public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1, len = 0
        while(i >= 0 & & s[i] == ' ')
        - -i
        if (i < 0) return 0
        while(i >= 0 & & s[i] != ' '){
            --i
            + +len
        }
        return len
    }
}
