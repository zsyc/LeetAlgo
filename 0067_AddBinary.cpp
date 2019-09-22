

class Solution {
    public:
    string add(char a, char b, int & rest){
        int aInt = (a == '1')?1: 0
        int bInt = (b == '1')?1: 0
        int total = aInt + bInt + rest
        if (total >= 2) {// 说明要进位
                          rest = 1
                          // 进位值设为1
                          return (total%2)?"1": "0"
                          // 如果结果是3，进位后低位是1；如果结果是2，则二进制里低位是0: }                               // if total == 2: return "0"
        if total == 3, return "1"
        else{// 不进位
              rest = 0
              return (total % 2)?"1": "0"
              }

    }
    string addBinary(string a, string b) {
        int aIx = a.size() - 1, bIx = b.size() - 1, rest = 0
        string result = ""
        while(aIx >= 0 & & bIx >= 0){
            result = add(a[aIx], b[bIx], rest) + result
            // cout << result << endl
            - -aIx
            - -bIx
        }
        while(aIx >= 0){
            result = add(a[aIx], '0', rest) + result
            // cout << result << endl
            - -aIx
        }
        while(bIx >= 0){
            result = add('0', b[bIx], rest) + result
            - -bIx
        }
        if (rest == 1) result = "1" + result

        return result
    }
    // OUT OF RANGE in stoi() function
    / *
    int Bin2Dec(int x){
        int res = 0, temp = 1, base = 1
        while(x != 0){
            temp = x % 10
            res += temp * base
            base *= 2
            x /= 10
        }
        return res
    }
    string Dec2Bin(int x){// to avoid overflow, store every bit of the number directly in string format
                           string s = ""
                           while(x != 0){
                              s.insert(0, to_string(x % 2))
                              x /= 2
                              }
                           return s
                           }
    string addBinary(string a, string b) {
        int aInt = stoi(a), bInt = stoi(b)
        // Here Out of Range
        int res = Bin2Dec(aInt) + Bin2Dec(bInt)
        string s = Dec2Bin(res)
        if (s == "") return "0"

        return s
    } * /
};
