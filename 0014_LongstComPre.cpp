

class Solution {
    public:
    string longestCommonPrefix(vector < string > & strs) {
        if (strs.empty())
        return ""
        for (int i=0
             i < strs[0].size()
             + +i){
            char ch = strs[0][i]
            for (string & word: strs)
            if ((i >= word.size()) | |(ch != word[i]))
            return strs[0].substr(0, i)
            if (i == strs[0].size() - 1) // 第一个单词到达末尾，但其他单词长度更长，这个时候说明最大相同字符串就是第一个单词
            return strs[0]
        }
        return ""
        // 当for循环不起作用时，说明vector容器为空
    }
}
